#include <iostream>

matrix_tree::matrix_tree() {
	this->begin.is_node = true;
	this->begin.elem_nu = 0;
	this->begin.matrix = NULL;
	this->begin.left = NULL;
	this->begin.right = NULL;
	this->head = NULL;
}

bool matrix_tree::find(int mat[4][4]) {
	matrix_tree_node *cur = &(this->begin);
	this->diff = 0;
	int elem_mat, elem_node, i = 0, j = 0, k = 1;
	while(cur != NULL) {
		if(cur->is_node) {
			head = cur;
			this->elem_nu = cur->elem_nu - this->diff;
			for(k=this->diff; k<cur->elem_nu; k++) {
				if(mat[k/4][k%4] != cur->elem[k-this->diff]) {
					this->diff = k;
					return false;
				}
			}

			this->diff = k-1;
			if(mat[k/4][k%4] == cur->elem[cur->elem_nu]) {
				this->diff++;
				cur = cur->left;
			} else 				
				cur = cur->right;
		} else if(cur->matrix != NULL) {
			i = n/4;
			j = n%4;
			for(i=i; i<4; i++) {
				for(j=j; j<4; j++) {
					if(mat[i][j] != cur->matrix[i][j]) {
						this->diff = i*4+j;
						return false;
					}
				}
			}
			return true;
		} else return false;
	}
	return false;
}

void matrix_tree::insert_node(int mat[4][4]) {
	this->find(mat);
	int inicio, aux_i, *aux_p, (*aux_m)[4];
	if(this->head == NULL) {
		this->begin.is_node = false;
		this->begin.matrix = mat;
	} else {
		matrix_tree_node *n = new matrix_tree_node();
		n->elem_nu = this->diff;
		n->is_node = true;
		if(this->diff < head->elem_nu) {
			n->elem = head->elem + (this->diff-this->elem_nu);
			head->elem = &(mat[(this->diff-this->elem_nu)/4][(this->diff-this->elem_nu)%4]);

			n->elem_nu = head->elem_nu;
			head->elem_nu = this->diff;
	
			n->left = head->left;
			head->left = new matrix_tree_node();
			left->is_node = false;
			left->matrix = mat;

			n->right = head->right;
			head->right = n;
		} else {
			n->elem = &(mat[(this->diff-head->elem_nu)/4][(this->diff-head->elem_nu)%4]);
			n->left = new matrix_tree_node();
			n->left.is_node = false;
			n->left.matrix = mat;

			if(mat[head->elem_nu/4][head->elem_nu%4] == head->elem[this->elem_nu]) {
				n->right = head->left;
				head->left = n;
			} else {
				n->right = head->right;
				head->right = n;
			}
		}
	}
}
