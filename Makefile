#Definition of the variables
CFLGAS = -Wall -Werror -ansi -pedantic -I.

#$^ means all the arguments
#$< means the first argument
#$@ means the name of the file to create

#Creation of the main executable
all: registrymain.exe

registrymain.exe: registrymain.o registry-lib.o transaction-lib.o user-lib.o securedinteractions.o
	gcc $^ -o $@ $(CFLAGS)
	
registrymain.o : registrymain.c registry-lib.c user-lib.c securedinteractions.c
	gcc -c $< -o $@ $(CFLAGS)
	
transaction-lib.o: transaction-lib.c registry-lib.c user-lib.c securedinteractions.c
	gcc -c $< -o $@ $(CFLAGS)

registry-lib.o: registry-lib.c securedinteractions.c
	gcc -c $< -o $@ $(CFLAGS)
	
user-lib.o: user-lib.c securedinteractions.c
	gcc -c $< -o $@ $(CFLAGS)

securedinteractions.o: securedinteractions.c
	gcc -c $< -o $@ $(CFLAGS)
	
#Delete all temporary files
clean:
	rm -rf *.o *.exe