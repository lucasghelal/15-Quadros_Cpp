#include <iostream>
#include "headers/a_node.h"
#include <vector>
#include <algorithm>

a_node::a_node() {
	this->ativo = true;
}

bool compare_node::operator()(a_node *&a1, a_node *&a2) {
	return ( a1->f > a2->f );	
}

void a_vector::push_node(a_node *n) {
	this->push_back(n);
	std::push_heap(this->begin(), this->end(), compare_node()); 
}

void a_vector::pop_node() {
	std::pop_heap(this->begin(), this->end(), compare_node());
	this->pop_back();
}

void a_vector::initialize_vec() {
	std::make_heap(this->begin(), this->end(), compare_node());
}
