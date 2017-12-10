#Definition of the variables
CFLGAS = -Wall -Werror -ansi -pedantic -I.

#$^ means all the arguments
#$< means the first argument
#$@ means the name of the file to create

#Creation of the main executable
all: registrymain.exe

registrymain.exe: registrymain.o registry-reg-lib.o transaction-reg-lib.o user-reg-lib.o tree-lib.o stack-lib.o secured-interactions-lib.o
	gcc $^ -o $@ $(CFLAGS)

#Creation of the .o of every .c	
registrymain.o : registrymain.c registry-reg-lib.c transaction-reg-lib.c user-reg-lib.c tree-lib.c stack-lib.c secured-interactions-lib.c
	gcc -c $< -o $@ $(CFLAGS)
	
transaction-reg-lib.o: transaction-reg-lib.c registry-reg-lib.c user-reg-lib.c
	gcc -c $< -o $@ $(CFLAGS)

registry-reg-lib.o: registry-reg-lib.c transaction-reg-lib.c
	gcc -c $< -o $@ $(CFLAGS)
	
user-reg-lib.o: user-reg-lib.c
	gcc -c $< -o $@ $(CFLAGS)
	
tree-lib.o: tree-lib.c
	gcc -c $< -o $@ $(CFLAGS)

stack-lib.o: stack-lib.c
	gcc -c $< -o $@ $(CFLAGS)
	
secured-interactions-lib.o: secured-interactions-lib.c
	gcc -c $< -o $@ $(CFLAGS)
	
#Delete all temporary files
clean:
	rm -rf *.o *.exe