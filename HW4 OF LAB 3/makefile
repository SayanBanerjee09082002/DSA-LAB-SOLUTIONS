all: bin/linked_list.o bin/queue.o bin/driver.o
	gcc -o exe bin/linked_list.o bin/queue.o bin/driver.o
	./exe

bin/linked_list.o : linked_list/linked_list.c linked_list/linked_list.h
	gcc -c linked_list/linked_list.c -o bin/linked_list.o

bin/queue.o : queue/queue_ll.c queue/queue.h
	gcc -c queue/queue_ll.c -o bin/queue.o

bin/driver.o : driver.c queue/queue.h linked_list/linked_list.h
	gcc -c driver.c -o bin/driver.o