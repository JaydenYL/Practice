#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


typedef struct linkedlist_node {
	struct linkedlist_node* next;
	int element;
} node;



typedef struct linkedlist {
	struct linkedlist_node* head;
	size_t size;
} llist;


void list_add(struct linkedlist* l, int element);
void list_remove(struct linkedlist* l, size_t index);
void list_destroy(struct linkedlist* l);
void list_print(struct linkedlist* l);
int  list_get(struct linkedlist* l, size_t index);


void test_add();
void test_remove();
void test_get();


int main(int argc, char *argv[]) {
	
	test_add();
	
	test_remove();
	
	return 0;
}

/*-----------------------------

Test Functions

  -----------------------------
*/

void test_add() {
	llist * l = (llist*) malloc(sizeof(llist));
	l->head = NULL;
	l->size = 0;
	printf("%p\n", l->head);
	for (int i = 0; i < 7; i ++) {
		list_add(l, 100+i);
	}
	list_print(l);
	list_destroy(l);
	
}


void test_remove() {
	llist * l = (llist*) malloc(sizeof(llist));
	l->head = NULL;
	l->size = 0;
	printf("%p\n", l->head);
	for (int i = 0; i < 7; i ++) {
		list_add(l, 100+i);
	}
	list_remove(l, 3);
	list_print(l);
	assert(l->size == 6);
	list_remove(l, 0);
	assert(l->size == 5);
	list_remove(l, 0);
	list_print(l);
	assert(l->size == 4);
	list_remove(l, 0);
	list_print(l);
	assert(l->size == 3);
	list_remove(l, 0);
	list_print(l);
	assert(l->size == 2);
	list_remove(l, 0);
	list_print(l);
	assert(l->size == 1);
	list_remove(l, 0);
	list_print(l);
	assert(l->size == 0);
	list_remove(l, 0);

//	list_destroy(l);
}


//------------------------------


void list_add(struct linkedlist* l, int element) {
	if (l == NULL)
		return;
	node *cur = l->head;
	if (cur == NULL) {
		l->head	= (node*)malloc(sizeof(node));
		l->head->next = NULL;
		l->head->element = element;
		l->size ++;
		return;
	}
	
	while (cur->next != NULL) {
		cur = cur->next;
	}
	
	cur->next = (node*) malloc(sizeof(node));
	cur->next->next = NULL;
	cur->next->element = element;
	l->size ++;
}



void list_remove(struct linkedlist* l, size_t index) {
	if (index >= l->size) {
		fprintf(stderr, "Index Out of Bound! (list_remove)\n");
		return;
	}
	
	node *cur = l->head;
	if (index == 0) {
		l->head = cur->next;
		free(cur);
		l->size --;
		return;
	}
	for (int i = 1; i < index; i++) {
		cur = cur->next;
	}
	node *tmp = cur->next;
	cur->next = tmp->next;
	free(tmp);
	l->size --;
}


void free_node(node *nd){
	if (nd == NULL) {
		return;
	}
	free_node(nd->next);
	free(nd);

}


void list_destroy(struct linkedlist* l) {
	if (l != NULL) {
		free_node(l->head);
		free(l);
	}
}



int list_get(struct linkedlist* l, size_t index) {
	if (index >= l->size) {
		fprintf(stderr, "Index Out of Bond (list_get)");
		exit(1);
	}
	node* cur = l->head;
	for (int i = 0; i < index; i ++) {
		cur = cur->next;
	}
	return cur->element;
}



void list_print(struct linkedlist* l) {
	printf("size %zu\n", l->size);
	node *cur= l->head;
	while (cur) {
		printf("%-5d ", cur->element);
		cur = cur->next;
	}
	putchar(10);
}
