/**Name of the file : registry.c
*Goal of the file : Make a library which support secure transaction
*Author : Lucas CELANT
*E-mail : lucas.celant@utbm.fr
*Last modification : 28/11/2017
*/


#include "registry-reg-lib.h"


double getBalance(Registry r, User u)
{
	double balance=0;
	TransactionElement t=r->head;
	for (int i =0;i<r->transactionCount;i++)
	{
		if (t->transaction->EmitterID*1.==u->ID)
		{
			balance-=t->transaction->Amount;
		}
		if (t->transaction->RecipientID*1.==u->ID)
		{
			balance+=t->transaction->Amount;
		}
		t=t->next;
	}
	return balance;
}


Registry getHistory(Registry r, User u)
{
	Registry Reg;
	Reg->head=NULL;
	Reg->tail=NULL;
	Reg->transactionCount=0;
	Reg->lastTransactionDate=0;
	TransactionElement t=r->head, Tra=NULL;
	while 
	{
		
	}
	while (t->Transaction->EmitterID!=u->ID&&t->Transaction->RecipientID!=u->ID&&t!=r->tail)
	{
			t=t->next;
	}
	if (t!=r->tail)
	{
		Reg->head=t;
		Reg->tail=t;
		Reg->transactionCount+=1;
		Reg->lastTransactionDate=t->Transaction->StartDateTime;
	}
	while (t!=r->tail)
	{
		while (t->Transaction->EmitterID!=u->ID&&t->Transaction->RecipientID!=u->ID&&t!=r->tail)
		{
				t=t->next;
		}
		if (t!=r->tail)
		{
			Reg->tail=t;
			Reg->transactionCount+=1;
			Reg->lastTransactionDate=t->Transaction->StartDateTime;
		}
	}
	
	
}


Registry getHistoryLimit(Registry r, User u, Start s, End e)
{
	if (s>e&&s>r->lastTransactionDate)
	{
		throw;
	}
	if (e>r->lastTransactionDate)
	{
		e=r->lastTransactionDate;
	}
	Registry Reg;
	Reg->head=NULL;
	Reg->tail=NULL;
	Reg->transactionCount=0;
	Reg->lastTransactionDate=0;
	TransactionElement t=r->head, Tra=NULL;	
	while (t->Transaction->StartDateTime<s)
	{
		t=t->next;
	}
	while (t->Transaction->StartDateTime<=e)
	{
		while (t->Transaction->EmitterID!=u->ID && t->Transaction->RecipientID!=u->ID && t->Transaction->StartDateTime<=e)
		{
			t=t->next;
		}
		if (t->Transaction->StartDateTime<=e)
		{
			Tra->t;
			
		}
	}

	
	
}


double getAverageCredit(Registry r, User u, Start s, End e)
{
	double creditSomme=0;
	long nbCredit=0;
	TransactionElement t=r->head;
	for (int i=0;i<r->transactionCount;i++)
	{
		if (t->transaction->RecipientID*1.==u->ID)
		{
			creditSomme+=t->transaction->Amount;
			nbCredit+=1;
		}
		t=t->next;
	}
	return creditSomme/nbCredit;
	
}


long getAmountR (Registry r, long ID);
{
	TransactionElement t = r->tail;
	while(t->transaction->ID != ID || t->previous != NULL)
		t = t->previous;
	if(t->transaction->ID == ID)
		return t->transaction->Amount;
	else
		return 0;
}

TransactionStatus getStatusR (Registry r, long ID);
{
	TransactionElement t = r->tail;
	while(t->transaction->ID != ID || t->previous != NULL)
		t = t->previous;
	if(t->transaction->ID == ID)
		return t->transaction->Status;
	else
		return 0;
}
