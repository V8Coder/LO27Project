/**Name of the file : registry.h
*Goal of the file : Make a library which support secure transaction
*Author : Lucas CELANT
*E-mail : lucas.celant@utbm.fr
*Last modification : 28/11/2017
*/

#ifndef _REGISTRY_H_
#define _REGISTRY_H_


#include "transaction-reg-lib.h"
#include "user-reg-lib.h"

/*
 	* The abstract datatype transaction
 */
typedef struct TransactionElem{
	struct TransactionElem* previous;
	Transaction transaction;
	struct TransactionElem* next;
}transactionElement;
typedef transactionElement* TransactionElement;

typedef struct RegistryElem{
	TransactionElement head;
	TransactionElement tail;
	long transactionCount;
	long lastTransactionDate;
}RegistryElem;
typedef RegistryElem* Registry;

typedef long Start;
typedef long End;



/*
	* The functions related to an account
*/

/*
*Gets the curent balance for the specified user
*Return : a double which is the curent balance of the user
*/
double getBalance(Registry r, User u);

/*
*Gets the complete list of the transactions for the specified user
*Return : a registry which contains all the transactions made by the user
*/
Registry getHistory(Registry r, User u);

/*
*Gets the complete list of the transactions for the specified user between two dates Start and End
*Return : a registry which contains all the transactions made by the user between two dates
*/
Registry getHistoryLimit(Registry r, User u, Start s, End e);

/*
*Gets the average credit of the user between two dates Start and End 
*Return : a double which is the average credit of the user between two dates
*/
double getAverageCredit(Registry r, User u, Start s, End e);

/*
*Gets the average debit of the user between two dates Start and End
*Return : a double which is the average debit of the user
*/
double getAverageDebit(Registry r, User u, Start s, End e);


/*
	* The functions related to a transaction
*/


/*
*Gets the amount of the transaction knowing only its ID
*Return : a long which is the amount of the transaction
*/
long getAmountR (Registry r, long ID);

/*
*Gets the status of the transaction knowing only its ID
*Return : a TransactionStatus of a transaction
*/
TransactionStatus getStatusR (Registry r, long ID);


/*
	* The functions related to the registry
*/


/*
*Loads a registry from a file
*Return : a registry 
*/
Registry load (char* S);

/*
*Saves a registry to a file
*/
void save (Registry r, char* S);

/*
*Performs a transaction request with the recipient user and amount: registers a new transaction in the registry
*with the status Pending and return the transaction ID, a private transaction key is generated. THe request is 
*performed by the recipient
*Return : a long which is the transaction ID
*/ 
long requestTransaction (Registry r, User u, double amount);

/*
*Sets the status to Confirmed if the emitter balance allows it. The amount is withdrawn from the emitter balance,
*but is not on the recipient balance yet. It returns the encrypted private key named the Transaction Key.
*The request is confirmed by the emitter.
*Return : a string which is the transaction key
*/
char* confirmTransaction (Registry r, User u, long ID);

/*
*Sets the status to Executed if the previous status was Confirmed and if the Transaction Key matches the encryption 
*of the private key. If so return true, otherwise return false. The EndDateTIme is set at the moment. The 
*transacation must be executec by the recipient.
*Return :a boolean which is True if the transaction can be Executed
*/
bool executeTransaction (Registry r, long TransactionID, long TransactionKey); /*Check the order*/

/*
*Sets the status to Cancelled if hte previous status was Pending, return false otherwise. Can ba called by either
*the emitter or the recipient.
*Return : a boolean which is true if the transaction have been successfully cancelled
*/
bool cancelTransaction (Registry r, long ID);

/*
*Return the average transaction time between two dates Star and End
*Return : a double which is the average time between two transactions
*/
double getAverageTransactionTime (Registry r, long Start, long End);


#endif
