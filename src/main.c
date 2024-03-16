#include <stdio.h>
#include <stdlib.h>

#include "heap.h"

void main() {
	heap* h = heap_new();

	puts("pushed:");
	int x;
	for (int i = 0; i < 100; ++i) {
		x = i / 3;
		printf("%d ", x);
		heap_push(h, x);
	}
	printf("\n\n");

	heap_print(h);

	puts("\npopped:");
	while (h->count > 0) {
		printf("%d ", heap_pop(h));
	}
	printf("\n\n");

	heap_print(h);

	heap_delete(h);

}
