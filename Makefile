#definition of the variables
CFLGAS = -Wall -Werror -ansi -pedantic -I.

#Creation of the main executable
all: registrymain.exe

registrymain.exe: registrymain.o registry.o
	gcc registrymain.o registry.o -o registrymain.exe $(CFLAGS)
	
registrymain.o : registrymain.c
	gcc -c registrymain.c $(CFLAGS)

registry.o: registry.c
	gcc -c registry.c $(CFLAGS)
	
securedinteractions.o: securedinteractions.c
	gcc -c securedinteractions.c 
	
$gcc $(FLAGS) "source file"   -o libRegistry.so -shared -fpic

clean:
	rm -rf *.o *.exe