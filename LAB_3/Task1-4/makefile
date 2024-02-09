all: bin/stackDriver.o bin/stack_array.o bin/stack_ll.o bin/linked_list.o bin/stack_array_performance.o bin/stack_ll_performance.o
	gcc -o runStackWithArray_exe bin/stackDriver.o bin/stack_array.o
	gcc -o runStackWithLL_exe bin/stackDriver.o bin/stack_ll.o bin/linked_list.o
	gcc -o stackArrayPerformanceWithArray_exe bin/stack_array_performance.o bin/stack_array.o
	gcc -o stackArrayPerformanceWithLL_exe bin/stack_ll_performance.o bin/stack_ll.o bin/linked_list.o
	
bin/stackDriver.o: stackDriver.c stack/stack.h
	gcc -c stackDriver.c -o bin/stackDriver.o

bin/linked_list.o: linked_list/linked_list.c linked_list/linked_list.h
	gcc -c linked_list/linked_list.c -o bin/linked_list.o

bin/stack_array.o: stack/stack_array.c stack/stack.h
	gcc -c stack/stack_array.c -o bin/stack_array.o

bin/stack_ll.o: stack/stack_ll.c stack/stack.h
	gcc -c stack/stack_ll.c -o bin/stack_ll.o

bin/stack_array_performance.o:: stack_array_performance.c stack/stack.h
	gcc -c stack_array_performance.c -o bin/stack_array_performance.o

bin/stack_ll_performance.o: stack_ll_performance.c stack/stack_ll.c stack/stack.h
	gcc -c stack_ll_performance.c -o bin/stack_ll_performance.o

stack_array: runStackWithArray_exe
	./runStackWithArray_exe

stack_ll: runStackWithLL_exe
	./runStackWithLL_exe

stack_array: runStackWithArray_exe
	./runStackWithArray_exe

stack_ll: runStackWithLL_exe
	./runStackWithLL_exe

performance: stackArrayPerformanceWithArray_exe stackArrayPerformanceWithLL_exe
	./stackArrayPerformanceWithArray_exe
	./stackArrayPerformanceWithLL_exe

clean:
	rm -f bin/*.o runStackWithArray_exe
	rm -f bin/*.o runStackWithLL_exe
	rm -f bin/*.o stackArrayPerformanceWithArray_exe
	rm -f bin/*.o stackArrayPerformanceWithLL_exe