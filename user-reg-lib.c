/**Name of the file : user.c
*Goal of the file : containing all the user methods and atributes
*Author : Lucas Celant
*E-mail : lucas.celant@utbm.fr
*Last modification : 28/11/2017
*/

#include "securedinteractions.h"
#include "user-lib.h"

User createUser(long name)
{
	User u = (User) malloc(sizeof(User_struct));
	u->ID = create_ID(name);
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
	create_ID(name);
}

long create_ID(char name[])
{
	long ID;
	int i;
	while(i<30 && name[i]!='\0'){
		ID=ID+name[i];
	}
	return ID;
}
