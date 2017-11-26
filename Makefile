registrymain.exe: registrymain.o registry.o
	gcc registrymain.o registry.o -o registrymain.exe -Wall -Werror -ansi -pedantic -I.
	
registrymain.o : registrymain.c
	gcc -c registrymain.c -Wall -Werror -ansi -pedantic -I.

registry.o: registry.c
	gcc -c registry.c -Wall -Werror -ansi -pendantic -I.
	
all: registrymain.exe

/** I haven't put an clean  rm -rf ".o".exe because i work on windows 
*/