#include "rbtree.h"

Node *b_search_rec(Node *r, int value, bool *found)
{
	if (r->data == value) {
		*found = true;
		return r;
	} else if (r->data > value){
		if (r->l == NULL) return r;
		return b_search_rec(r->l, value, found);
	} else if (r->data < value) {
		if (r->r == NULL) return r;
		return b_search_rec(r->r, value, found);
	}
	return NULL;
}

Node *b_search(Node *r, int value, bool *found)
{
	if (r == NULL)
		return NULL;
	return b_search_rec(r, value, found);
}

Node *make_node(int dt, int cr, Node *par, Node *left, Node *right)
{
	Node *n = NULL;

	n = malloc(sizeof(Node));
	
	if (!n)
		return NULL;

	n->data = dt;
	n->color = cr;
	n->p = par;
	n->l = left;
	n->r = right;

	return n;
}

int insert_node(Node *r, int value)
{
	bool found = false;	

	Node *parent = b_search(r, value, &found);

	if (found || parent == NULL)
		return 0;

	Node *child = make_node(value, 1, parent, NULL, NULL);

	if (!child)
		return -1;

	if (value < parent->data) {
		parent->l = child;
	} else {
		parent->r = child;
	}
	return 0;
}

void print_rb_rec(Node *r, int level)
{
	for (int i = 0; i < level; i++) {
		printf(" ");
	}
	printf("%d\n", r->data);
	
	if (r->l != NULL) {
		print_rb_rec(r->l, level+1);
	} 

	if (r->r != NULL) {
		print_rb_rec(r->r, level+1);
	}

	return;
}

void print_rb(Node *r)
{
	if (r == NULL)
		return;
	print_rb_rec(r, 0);
}
