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

Node *get_left(Node *n)
{
	if (n == NULL)
		return NULL;
	if (n->l != NULL)
		return n->l;
	return NULL;
}

Node *get_right(Node *n)
{
	if (n == NULL)
		return NULL;
	if (n->r != NULL)
		return n->r;
	return NULL;
}

Node *get_parent(Node *n)
{
	if (n == NULL)
		return NULL;
	if (n->p != NULL)
		return n->p;
	return NULL;
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

int swap_color(Node *n)
{
	if (n == NULL)
		return -1;
	if (n->color == 0) {
		n->color = 1;
		return 0;
	} else if (n->color == 1) {
		n->color = 0;
		return 0;
	}
	return -1;
}

bool is_left(Node *n)
{
	if (n->p == NULL)
		return false;
	if (n->p->l == n)
		return true;
	return false;
}

bool is_right(Node *n)
{
	if (n->p == NULL)
		return false;
	if (n->p->r == n)
		return true;
	return false;
}

void swap_node_content(Node *n1, Node *n2)
{
	if (n1 == NULL || n2 == NULL)
		return;

	Node *temp_d = make_node(n1->data,
						     n1->color,
						     n1->p,
							 n1->l,
							 n1->r);
	n1->data = n2->data;
	n1->color = n2->color;
	n1->p = n2->p;
	n1->l = n2->l;
	n1->r = n2->r;

	n2->data = temp_d->data;
	n2->color = temp_d->color;
	n2->p = temp_d->p;
	n2->l = temp_d->l;
	n2->r = temp_d->r;

	Node *temp_p = n1;
	n1 = n2;
	n2 = temp_p; 

}

void rotate_tree(Node *n)
{
	/*
	 *
	 *        2         3
	 *		1   3  -> 2   4 ->   
	 *		     4   1		
	 *		left rotation
	 */
	if (n == NULL)
		return;
	
	Node *node_left = get_left(n);
	Node *node_right = get_right(n);
	Node *node_parent = get_parent(n); 

	if (node_parent) {
		Node *node_grandParent = get_parent(node_parent);
		if (is_right(n)) {
			if (node_grandParent) {
				if (is_left(node_parent)) {
					node_grandParent->l = n;
				} else {
					node_grandParent->r = n;
				}
				n->p = node_grandParent;
				node_parent->p = n;
			} else {
				swap_node_content(node_parent, n);
			}
			node_parent->r = node_left;
		} else {
			if (node_right) {
				node_parent->l = node_right;
				n->p = node_right;
				n->r = node_right->l;
				node_right->l = n;
			} else {
				return;
			}
		}
	} else {
		if (node_right == NULL)
			return;
		swap_node_content(n, node_right);
		node_right->p = n;
		n->p = NULL;
		node_right->r = n->l;
		n->l = node_right;
	}
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
