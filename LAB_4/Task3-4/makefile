all: bin/merge_sort_driver.o bin/merge_sort.o
	gcc -o merge_sort_exe bin/merge_sort_driver.o bin/merge_sort.o
	./merge_sort_exe

bin/merge_sort.o: merge_sort/merge_sort.c merge_sort/merge_sort.h structure/person.h
	gcc -c merge_sort/merge_sort.c -o bin/merge_sort.o

bin/merge_sort_driver.o: merge_sort/merge_sort.h structure/person.h merge_sort_driver.c
	gcc -c merge_sort_driver.c -o bin/merge_sort_driver.o

clean:
	rm -f bin/*.o
	rm merge_sort_exe