#ifndef _PRODUCT_LIST_H_
#define _PRODUCT_LIST_H_


/**Name of the file : securedinteractions.h
*Goal of the file : have secured fontions to interact with the user and avoid buffer overflows
*Author : Loïc MARTIN
*E-mail : loic.martin-01@utbm.fr
*Last modification : 26/11/2017
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/**Empty the buffer*/
void emptybuffer ();

/**Read a string without ricks of buffer overflows
*l[] : the string, of size n, that will be red
*n : an integer which is the size maximum of l[]*/
int read (char l[], int n);

/**Read a long (int) without ricks of buffer overflows*/
long read_long ();

/**Read a double (float) without ricks of buffer overflows*/
long read_double ();


#endif
