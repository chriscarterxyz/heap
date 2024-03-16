#include <stdio.h>
#include <stdlib.h>

#include "heap.h"

#define HEAP_MIN_SIZE 16

heap* heap_new() {
	
	heap* h = (heap*)malloc(sizeof(heap));

	h->size = HEAP_MIN_SIZE;
	h->count = 0;
	h->items = (int*)malloc(sizeof(int) * HEAP_MIN_SIZE);

	return h;

}

void heap_delete(heap* h) {
	free(h->items);
	free(h);
} 

int heap_peek(const heap* h) {
	if (h->count == 0) return 0;
	return h->items[0];
}

int heap_left_child(const int index) {
	return 2 * index + 1;
}

int heap_right_child(const int index) {
	return 2 * index + 2;
}

int heap_parent(const int index) {
	return (index - 1) / 2; // int truncates, performing floor function
}

void heap_print(const heap* h) {
	if (h != NULL) {
		printf("heap(count=%d, size=%d)\n", h->count, h->size);
		for (int i = 0; i < h->count; i++) {
			if (h->items[heap_parent(i)] < h->items[i]) printf("*"); // idiot check while debugging
			printf("%d ", h->items[i]);
		}
		printf("\n");
	} else {
		puts("(null)");
	}
}

static void heap_swap(heap* h, const int index1, const int index2) {

	int temp = h->items[index1];
	h->items[index1] = h->items[index2];
	h->items[index2] = temp;

}

static void heap_do_resize(heap* h, const int newsize) {

	int *newitems, *olditems;
	
	newitems = malloc(sizeof(int) * newsize);
	for (int i = 0; i < h->count; i++) {
		newitems[i] = h->items[i];
	}
	
	olditems = h->items; 
	h->items = newitems;
	free(olditems);

	h->size = newsize;

}

static void heap_resize(heap* h) {

	if (h->count == h->size) {
		heap_do_resize(h, h->size * 2);	
	} else if (h->count == h->size / 2 && HEAP_MIN_SIZE <= h->count) {	
		heap_do_resize(h, h->count);
	}

}

void heap_push(heap* h, const int x) {

	int index = h->count;

	// add to end of array and increment count
	h->items[index] = x;
	h->count++;

	// rebalance 
	int parent = heap_parent(index);
	while (h->items[index] > h->items[parent]) { // check if index == 0?
		
		heap_swap(h, index, parent);
		index = parent;
		parent = heap_parent(parent);

	}	
	
	heap_resize(h);

}

int heap_pop(heap* h) {

	// copy root item value
	int root = h->items[0];
	
	// move the last element of the array to the root
	h->items[0] = h->items[h->count-1];
	h->count--;

	// rebuild the heap
	int index = 0;
	int left, right, target; // left and right child
	while (index < h->count) {
		left = heap_left_child(index);
		right = heap_right_child(index);

		if (left >= h->count && right >= h->count) { // if node has no children, we are done
			break;
		} else if (left >= h->count) {
			target = right;
		} else if (right >= h->count) {
			target = left;
		} else {
			target = h->items[left] > h->items[right] ? left : right;
		}

		if (h->items[index] < h->items[target]) 
			heap_swap(h, index, target);
		index = target;

	}

	heap_resize(h);
	return root;

}


