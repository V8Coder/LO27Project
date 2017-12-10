/**Name of the file : transaction.c
*Goal of the file : containing all the transaction methods and atributes
*Author : Lucas Celant
*E-mail : lucas.celant@utbm.fr
*Last modification : 28/11/2017
*/

#include "transaction-reg-lib.h"

Transaction createTransaction(double amount, long emitterID, long recipientID, long TTL)
{
	int i;
	time_t sec = time(NULL);
	if(sec != -1 && amount != 0 && TTL > 0){
		Transaction t = (Transaction)malloc(sizeof(Transaction_struct));
		/*penser a faire fct moin facile*/
		t->ID = sec-15;
		t->Amount = amount;
		t->EmitterID = emitterID;
		t->RecipientID = recipientID;
		t->Status = PENDING;
		t->StartDateTime = sec;
		t->EndDateTime = sec + TTL;
		t->TTL = TTL;
		srand(time(NULL));
		for(i=0;i<PRIVATE_KEY_LENGTH;i++){
			t->PrivateKey[i] = rand()%(127-32)+32;
		}
		return t;
	}
	else{
		return NULL;
	}
}

double getAmount(Transaction t)
{
	return(t->Amount);
}

TransactionStatus getStatus(Transaction t)
{
	return(t->Status);
}

long getStartDateTime(Transaction t)
{
	return(t->StartDateTime);
}

long getEndDateTime(Transaction t)
{
	return(t->EndDateTime);
}

long getTTL(Transaction t)
{
	return(t->TTL);
}

bool isExpired(Transaction t, long d)
{
	if(t->EndDateTime >= d)
		return true;
	else
		return false;
}
