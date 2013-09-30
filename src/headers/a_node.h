#ifndef NODE_H
#define NODE_H

#include <vector>
#include <string>

class a_node {
	public:
		int matrix[4][4];
		int node_number;
		float h, g, f;
		std::string parent;
};

class a_vector : public std::vector<a_node> {
	public:
		void push_node(a_node);
		void pop_node();
		void initialize_vec();
};

class compare_node {
	public:
		bool operator() (a_node &a1, a_node &a2);
};

#endif
