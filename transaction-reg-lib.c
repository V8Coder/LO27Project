/**Name of the file : transaction.c
*Goal of the file : containing all the transaction methods and atributes
*Author : Lucas Celant
*E-mail : lucas.celant@utbm.fr
*Last modification : 28/11/2017
*/

#include "securedinteractions.h"
#include "transaction-lib.h"

Transaction createTransaction()
{

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
