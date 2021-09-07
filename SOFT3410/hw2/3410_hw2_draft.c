#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>


typedef struct node Node;
typedef struct AVLtree Tree;

struct node { 
	Node* left;
	Node* right;
	char word[128];
};

struct AVLtree {
	Node* root;
	int size;
};
void process_file(char *filepath);
void add_node(Tree *tr, Node *new_node);
bool comparator(Node *node_1, Node *node_2);
int cmptr(const void *s_1, const void *s_2);
void asc(Node*);
void desc(Node*);



int main(int argc, char *argv[]) {

//	process_file(argv[1]);
	FILE* fp = fopen(argv[1], "r");
	char words[10000][128] = {0};
	int size = 0;
	while (fgets(words[size++], 127, fp)) {
		
	}
	qsort(words, size, 128*sizeof(char), cmptr);
	for (int i = 0; i < size; i++) {
		puts(words[i]);
	}
	
}

int cmptr(const void *s_1, const void *s_2) {
	char *str_1 = (char*)s_1, *str_2 = (char*)s_2;
	int i = 0;
	for (; i < strlen(str_1) && i < strlen(str_2); i++) {
		if (tolower(str_1[i]) < tolower(str_2[i])) {
			return 1;
		} else if (tolower(str_1[i]) > tolower(str_2[i])) {
			return -1;
		}
	}
	return 1 == strlen(str_1);
}


void process_file(char* filepath) {
	FILE* fp = fopen(filepath, "r");
	char word[128] = {0};
	Tree tr = {NULL, 0};
	
	while (fgets(word, 127, fp)) {
		Node new_node = {NULL, NULL, {0}};
		memcpy(new_node.word, word, 127);
		add_node(&tr, &new_node);
	}
	
	asc(tr.root);
	
}



void add_node(Tree* tr, Node *new_node) {
	if (tr->root == NULL) {
		tr->root = new_node;
		tr->size ++;
		return;
	}
	Node *cur = tr->root;

	while (true) {
		if (comparator(cur, new_node)) {
			if (cur->right == NULL) {
				cur->right = new_node;
				return;
			} else {
				cur = cur->right;
			}
		} else {
			if (cur->left == NULL) {
				cur->left = new_node;
				return;
			} else {
				cur = cur->left;
			}
		}
	}
	
}



// what if they are duplicated?
bool comparator(Node *node_1, Node *node_2) {
	char *str_1= node_1->word, *str_2 = node_2->word;
	int i = 0;
	for (; i < strlen(str_1) && i < strlen(str_2); i++) {
		if (tolower(str_1[i]) < tolower(str_2[i])) {
			return true;
		} else if (tolower(str_1[i]) > tolower(str_2[i])) {
			return false;
		}
	}
	if (i == strlen(str_1)) {
		return true;
	}
	return false;
}



void asc(Node *nd) {
	if (nd) {
		asc(nd->left);
		printf("%s\n", nd->word);
		asc(nd->right);
	}
}


void desc(Node *nd) {
	if (nd) {
		desc(nd->right);
		printf("%s\n", nd->word);
		desc(nd->left);
	}
}

int cmptr(const void *s_1, const void *s_2) {
	char *str_1 = (char*)s_1, *str_2 = (char*)s_2;
	int i = 0;
	for (; i < strlen(str_1) && i < strlen(str_2); i++) {
		if (tolower(str_1[i]) < tolower(str_2[i])) {
			return 1;
		} else if (tolower(str_1[i]) > tolower(str_2[i])) {
			return -1;
		}
	}
	return 1 == strlen(str_1);
}