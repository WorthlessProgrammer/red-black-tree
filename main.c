#include "rbtree.h"

int main(void)
{
	Node *p_root = make_node(10, 0, NULL, NULL, NULL);

	insert_node(p_root, 5);

	insert_node(p_root, 18);	

	bool trobat = false;
	Node *v1 = b_search(p_root, 15, &trobat);

	if (trobat) {
		printf("%d\n", v1->data);
	}

	print_rb(p_root);

	insert_node(p_root, 37);
	insert_node(p_root, 108);
	insert_node(p_root, 7);
	insert_node(p_root, 1);
	insert_node(p_root, 108);
	
	print_rb(p_root);

	return 0;
}
