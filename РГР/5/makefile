all: main

libcez.so: cez.c
	gcc -fPIC -shared -o libcez.so cez.c

main: main.c libcez.so
	gcc -o main main.c -L. -lcez -Wl,-rpath=.

clean:
	rm -f main libcez.so