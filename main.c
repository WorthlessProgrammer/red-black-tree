#include "rbtree.h"

int main(void)
{
	Node *p_root = make_node(10, 0, NULL, NULL, NULL);

	insert_node(p_root, 5);

	insert_node(p_root, 18);	

	bool trobat = false;
	Node *v1 = b_search(p_root, 15, &trobat);

	if (trobat) {
		printf("found %d in the tree\n", v1->data);
	}

	insert_node(p_root, 37);
	insert_node(p_root, 108);
	insert_node(p_root, 7);
	insert_node(p_root, 1);
	insert_node(p_root, 108);
	
	print_rb(p_root);

	/* bool test_child_side = false; */
	
	if(is_right(p_root->r->r))
		printf("root's right's right child : %d\n", p_root->r->r->data);

	printf("Testing tree left rotation: \n");

	rotate_tree(p_root->r);

	print_rb(p_root);

	return 0;
}
