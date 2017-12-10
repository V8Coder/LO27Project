/**Name of the file : user.c
*Goal of the file : containing all the user methods and atributes
*Author : Lucas Celant
*E-mail : lucas.celant@utbm.fr
*Last modification : 28/11/2017
*/


#include "user-reg-lib.h"

User createUser(long Name)
{
	User u = NULL;
	u = (User) malloc(sizeof(User_struct));
	return u;
}

long getID(User u)
{
	return u->ID;
}

char* getName(User u)
{
	return u->Name;
}

void setName(User u, char name[])
{
	strcpy(u->Name,name);
}
