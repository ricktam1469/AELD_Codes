all:helloall	

helloall: main.o factorial.o hello.o
	gcc main.o factorial.o hello.o -o out 
main.o: main.c
	gcc -c  main.c
factorial.o: factorial.c
	gcc -c  factorial.c
hello.o: hello.c
	gcc -c  hello.c
del: 
	rm *.o
