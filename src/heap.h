typedef struct {
	int size;
	int count;
	int* items;
} heap;

// Creates a new heap with minumum heap size of 16, and returns a heap*
heap* heap_new();

// Deallocates and deletes a heap
void heap_delete(heap* h);

// Returns the root element of a heap without popping the element
int heap_peek(const heap* h);

// Gets the index of the left child of a heap element. Does not check if the index is in the heap array.
static int heap_left_child(const int index);

// Gets the index of the right child of a heap element. Does not check if the index is in the heap array.
static int heap_right_child(const int index);

// Gets the index of the parent of a heap element.
static int heap_parent(const int index);

// Prints the heap array with size and count information
void heap_print(const heap* h);

// Swaps two elements in a heap.
static void heap_swap(heap* h, const int index1, int const index2);

// Resizes the heap array to newsize.
static void heap_do_resize(heap* h, const int newsize);

// Resizes the heap depending on the heap count versus the heap size. If the count equals the size, the size is doubled. If the count is equal to half the size (rounded down) but greater than or equal to the min heap size, the size is halved.
static void heap_resize(heap* h);

// Pushes an element onto the heap and rebuilds the heap.
void heap_push(heap* h, const int x);

// Pops the root element from the heap and rebuilds the heap.
int heap_pop(heap* h);

