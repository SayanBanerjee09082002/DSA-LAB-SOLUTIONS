all: bin/insertion_sort_driver.o bin/insertion_sort.o
	gcc -o insertion_sort_exe bin/insertion_sort_driver.o bin/insertion_sort.o
	./insertion_sort_exe

bin/insertion_sort.o: insertion_sort/insertion_sort.c insertion_sort/insertion_sort.h structure/person.h
	gcc -c insertion_sort/insertion_sort.c -o bin/insertion_sort.o

bin/insertion_sort_driver.o: insertion_sort/insertion_sort.h structure/person.h insertion_sort_driver.c
	gcc -c insertion_sort_driver.c -o bin/insertion_sort_driver.o

clean:
	rm -f bin/*.o
	rm insertion_sort_exe

