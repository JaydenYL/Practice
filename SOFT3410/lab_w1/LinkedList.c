#include <stdio.h>


struct linkedlist_node {
	struct linkedlist_node* next;
	int element;
};

struct linkedlist {
	struct linkedlist_node* head;
	size_t size;
};


void list_add(struct linkedlist* l, int element);
void list_remove(struct linkedlist* l, size_t index);
void list_destroy(struct linkedlist* l);
int list_get(struct linkedlist* l, size_t index);


int main(int argc, char *argv[]) {
	
	
	return 0;
}
