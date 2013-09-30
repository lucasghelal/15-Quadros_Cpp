#ifndef MATRIX_TREE_H
#define MATRIX_TREE_H

class matrix_tree {
	private:
		matrix_tree_node begin;
		matrix_tree_node *head;
		int diff, elem_nu;
	
	public:
		matrix_tree();
		void insert_node(int(*)[4]);
		bool find(int(*)[4]);
		void delete_node(int(*)[4]);
}

class matrix_tree_node {
	public:
		matrix_tree_node *left;
		matrix_tree_node *right;
		int (*matrix)[4];
		int elem_nu;
		int *elem;
		bool is_node;
};

#endif
