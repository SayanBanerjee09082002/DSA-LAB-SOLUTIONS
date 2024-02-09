all: bin/queueDriver.o bin/queue_array.o bin/heap_usage.o bin/queue_ll.o
	gcc -o runQueueWithArray_exe bin/queueDriver.o bin/queue_array.o bin/heap_usage.o
	gcc -o runQueueWithLL_exe bin/queueDriver.o bin/queue_ll.o bin/heap_usage.o

bin/queueDriver.o: queueDriver.c queue/queue.h
	gcc -c queueDriver.c -o bin/queueDriver.o

bin/heap_usage.o: heap_usage/heap_usage.c heap_usage/heap_usage.h
	gcc -c heap_usage/heap_usage.c -o bin/heap_usage.o

bin/linked_list.o: linked_list/linked_list.c linked_list/linked_list.h
	gcc -c linked_list/linked_list.c -o bin/linked_list.o

bin/queue_array.o: queue/queue_array.c queue/queue.h heap_usage/heap_usage.h
	gcc -c queue/queue_array.c -o bin/queue_array.o

bin/queue_ll.o: queue/queue_ll.c queue/queue.h linked_list/linked_list.h heap_usage/heap_usage.h
	gcc -c queue/queue_ll.c -o bin/queue_ll.o

queue_ll: runQueueWithLL_exe
	./runQueueWithLL_exe

queue_array: runQueueWithArray_exe
	./runQueueWithArray_exe

clean:
	rm -f bin/*.o runQueueWithArray_exe
	rm -f bin/*.o runQueueWithLL_exe