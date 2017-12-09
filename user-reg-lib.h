/**Name of the file : user.h
*Goal of the file : containing all the user methods and atributes
*Author : Lucas Celant
*E-mail : lucas.celant@utbm.fr
*Last modification : 28/11/2017
*/

#ifndef _USER_H_
#define _USER_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MaxNameLenght 30

/*
 * the abstract datatype user
 */
typedef struct User_struct {
	long ID;
	char Name[MaxNameLenght];
} User_struct;
typedef User_struct* User;

/*
 * createUser take a long and allocate memory for a User
 * name : a long, the name of the user
 * Return : a pointer to the structure
 */
User createUser(long name);

/*
 * getId get the user's ID
 * u : a User data type, a pointer to a User
 * Return : a long, the ID of the user
 */
long getID(User u);

/*
 * getName get the user name
 * u : a User data type, a pointer to a User
 * Return : a string, the name of the user
 */
char* getName(User u);

/*
 * setName specifies the name of the user
 * u : a User data type, a pointer to a User
 * name : the name of the user
 */
void setName(User u, char name[]);

/**
 * A function that encode the name in the ID
 * @param name the name of the user
 * @return a long, the hashed name
 */
long create_ID(char name[]);

#endif
