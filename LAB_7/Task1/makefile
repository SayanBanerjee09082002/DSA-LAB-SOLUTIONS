all: bin/avl.o bin/insertion.o bin/query.o bin/rotation.o bin/traversal.o bin/avl_driver.o
	gcc -o avl_exe bin/avl.o bin/insertion.o bin/query.o bin/rotation.o bin/traversal.o bin/avl_driver.o
	./avl_exe

bin/avl.o: avl/avl.h avl/avl.c
	gcc -c avl/avl.c -o bin/avl.o

# bin/deletion.o: deletion/deletion.h deletion/deletion.c
# 	gcc -c deletion/deletion.c -o bin/deletion.o

bin/insertion.o: insertion/insertion.h insertion/insertion.c
	gcc -c insertion/insertion.c -o bin/insertion.o

bin/rotation.o: rotation/rotation.h rotation/rotation.c
	gcc -c rotation/rotation.c -o bin/rotation.o

bin/query.o: query/query.h query/query.c
	gcc -c query/query.c -o bin/query.o

bin/traversal.o: traversal/traversal.h traversal/traversal.c
	gcc -c traversal/traversal.c -o bin/traversal.o

bin/avl_driver.o: avl/avl.h insertion/insertion.h rotation/rotation.h traversal/traversal.h
	gcc -c avl_driver.c -o bin/avl_driver.o

clean:
	rm -f bin/*.o
	rm avl_exe