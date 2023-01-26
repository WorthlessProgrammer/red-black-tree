#ifndef RB_TREEE_H
#define RB_TREEE_H

#if 1
#include <stdio.h>
#endif

#include <stdlib.h>
#include <stdbool.h>

typedef struct Node_t {
	int data;
	int color;
	struct Node_t *p;
	struct Node_t *l;
	struct Node_t *r;
} Node;

Node *b_search_rec(Node *r, int value, bool *found);
Node *b_search(Node *r, int value, bool *found);
Node *make_node(int data, int color, Node *p, Node *l, Node *r);
Node *get_left(Node *n);
Node *get_right(Node *n);
Node *get_parent(Node *n);
int insert_node(Node *r, int value);
int swap_color(Node *r);
bool is_left(Node *n);
bool is_right(Node *n);
void swap_node_content(Node *n1, Node *n2);
void rotate_tree_left(Node *n);
void rotate_tree_right(Node *n);
void print_rb_rec(Node *r, int level);
void print_rb(Node *r);

#endif //RB_TREEE_H
