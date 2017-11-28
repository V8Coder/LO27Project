/**Name of the file : transaction.c
*Goal of the file : containing all the transaction methods and atributes
*Author : Lucas Celant
*E-mail : lucas.celant@utbm.fr
*Last modification : 28/11/2017
*/

#ifndef _TRANSACTION_H_
#define _TRANSACTION_H_


typedef enum Status
{
    PENDING, CONFIRMED, EXECUTED, CANCELED
} Status;

/*
 * the abstract datatype transaction
 */
typedef struct Transaction_struct {
	long ID;
	double Amount;
	long EmitterID;
	long RecipentID;
	Status TransactionStatus;
	long StartDateTime;
	long EndDateTime;
	long TTL;
	char PrivateKey[];
} Transaction_struct;
typedef Transaction_struct* Transaction;

#endif
