/**Name of the file : saisiesecu.c
*Goal of the file : have secured fontions to interact with the user and avoid buffer overflows
*Author : Loïc MARTIN
*E-mail : loic.martin-01@utbm.fr
*Last modification : 26/11/2017
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void emptybuffer ()
{
	int c;
	while (c!='\0'&&c!=EOF)
	{
		c=getchar();
	}
}


int read (char l[], int n)
{
	char* position=NULL;
	if (fgets(l,n,stdin)!=NULL)
	{
		position=strchr(l, '\n');
		if (position!=NULL)
		{
			*position= '\0';
		}
		else
		{
			emptybuffer();
		}
		return 1;
	}
	else
	{
		emptybuffer();
		return 0;
	}
}


long read_long ()
{
	char number[100]={0};
	if (read(number,100))
	{
		return strtol (number,NULL,10);
	}
	else
	{
		return 0;
	}
}


long read_double ()
{
	char number[100]={0};
	if (read(number,100))
	{
		return strtod(number,NULL);
	}
	else
	{
		return 0;
	}
}
