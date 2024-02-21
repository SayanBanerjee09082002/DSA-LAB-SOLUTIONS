all: bin/bst.o bin/deletion.o bin/insertion.o bin/query.o bin/traversal.o bin/bst_driver.o
	gcc -o bst_exe bin/bst.o bin/deletion.o bin/insertion.o bin/query.o bin/traversal.o bin/bst_driver.o
	./bst_exe

bin/bst.o: bst/bst.h bst/bst.c
	gcc -c bst/bst.c -o bin/bst.o

bin/deletion.o: deletion/deletion.h deletion/deletion.c
	gcc -c deletion/deletion.c -o bin/deletion.o

bin/insertion.o: insertion/insertion.h insertion/insertion.c
	gcc -c insertion/insertion.c -o bin/insertion.o

bin/query.o: query/query.h query/query.c
	gcc -c query/query.c -o bin/query.o

bin/traversal.o: traversal/traversal.h traversal/traversal.c
	gcc -c traversal/traversal.c -o bin/traversal.o

bin/bst_driver.o: bst/bst.h insertion/insertion.h traversal/traversal.h query/query.h
	gcc -c bst_driver.c -o bin/bst_driver.o

clean:
	rm -f bin/*.o
	rm bst_exe