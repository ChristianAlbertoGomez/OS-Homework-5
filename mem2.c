#include <stdio.h>
#include <stdlib.h>

// Program that uses malloc inside a loop to allocate and allocate 1 MiB on 
// the heap each time through the loop, without freeing any memory until the
// end of the program. 
int main(int argc, char *argv[]) {
    if (argc != 2) {
	fprintf(stderr, "usage: mem2 <memory (MB)>\n");
	exit(1);
    }
    int size = (int) atoi(argv[1]);
    int *array;

    for (int i = 1; i <= size; i++) {
        array = (int *) malloc(1024*1024);
	if (!array) {
		printf("malloc %d failed\n", i);
	        return(-1);
	}
	printf("malloc %d succeeded\n", i);
	for (int j = 0; j < (1024*1024)/sizeof(int); j++)
		array[j] = 0;
	printf("total memory allocated and initialized so far: %d MB\n", i);
    }

    return 0;
}

