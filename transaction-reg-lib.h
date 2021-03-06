/**Name of the file : transaction.c
*Goal of the file : containing all the transaction methods and atributes
*Author : Lucas Celant
*E-mail : lucas.celant@utbm.fr
*Last modification : 28/11/2017
*/

#ifndef _TRANSACTION_H_
#define _TRANSACTION_H_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PRIVATE_KEY_LENGTH 16
/*
 	* The abstract datatype transaction
 */

typedef enum bool
{
	true = 1, false = 0
} bool; 

typedef enum TransactionStatus
{
    PENDING, CONFIRMED, EXECUTED, CANCELED
} TransactionStatus;

typedef struct Transaction_struct {
	long ID;
	double Amount;
	long EmitterID;
	long RecipientID;
	TransactionStatus Status ;
	long StartDateTime;
	long EndDateTime;
	long TTL;
	char PrivateKey[PRIVATE_KEY_LENGTH];
} Transaction_struct;
typedef Transaction_struct* Transaction;

/**
 * createTransaction create a new transaction with a randomly generated ID
 * @param amount the amount of the transaction, a reel not equal to zero
 * @param emitterID the emitterID
 * @param recipientID the recipient ID
 * @param TTL the time to leave of the transaction in second
 * @return a transaction
 */
Transaction createTransaction(double amount, long emitterID, long recipientID, long TTL);

/**
 * getAmount take a transaction pointer and gets the amount of the transaction
 * t : a transaction type pointer
 * return : a double which shows the ammount of the transaction
 */
double getAmount(Transaction t);

/*
 * getstatus take a transaction pointer and return the status of the transaction
 * t : a transaction pointer
 * return : Transaction status
 */
TransactionStatus getStatus(Transaction t);

/*
 * getStartDateTime take a transaction pointer and return the timesptamp of the creation of the transaction
 * t : a transaction pointer
 * return : long the timestamp of the begining of the transaction
 */
long getStartDateTime(Transaction t);

/*
 * getEndDateTime take a transaction pointer and return the timesptamp of the end of the transaction
 * t : a transaction pointer
 * return : long the timestamp of the end of the transaction
 */
long getEndDateTime(Transaction t);

/*
 * getTTL take a transaction pointer and gets the time-to-live of the transaction
 * t : a transaction pointer
 * return : a long, the time to live of the transaction
 */
long getTTL(Transaction t);

/*
 * isExpired take a transaction pointer and the current date and return true if the transaction is expired, 
 		flase atherwise
 * t : a transaction pointer
 * d : a long, the current date 
 * return : a boolean, return true if the transaction is expired flase atherwise
 */
bool isExpired(Transaction t, long d);

#endif
