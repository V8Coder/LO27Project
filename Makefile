CFLAGS = -Wall -Werror -ansi -pedantic
LDFLAGS = -Wall -Werror -ansi -pedantic
EXEC=Registry.exe
LIB=libRegistry.so

lib:$(LIB)

libRegistry.o : registry.c transaction.c user.c
    gcc -c

clean
    rm -rf *.o *.exe

