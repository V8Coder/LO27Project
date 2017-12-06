/**Name of the file : registry.h
*Goal of the file : Make a library which support secure transaction
*Author : Lucas CELANT
*E-mail : lucas.celant@utbm.fr
*Last modification : 28/11/2017
*/

#ifndef _REGISTRY_H_
#define _REGISTRY_H_


#include "transaction-lib.h"
#include "user-lib.h"

/*
 	* The abstract datatype transaction
 */
typedef struct TransactionElem{
	struct TransactionElem *previous;
	Transaction transaction;
	struct TransactionElem *next;
}TransactionElement;

typedef struct Registry{
	TransactionElement *head;
	TransactionElement *tail;
	long transactionCount;
	long lastTransactionDate;
}Registry;

typedef long Start;
typedef long End;

/*
	* The functions
*/

double getBalance(Registry r, User u);


Registry getHistory(Registry r, User u);


Registry getHistoryLimit(Registry r, User u, Start s, End e);


double getAverageCredit(Registry r, User u, Start s, End e);


double getAverageDebit(Registry r, User u, Start s, End e);




#endif