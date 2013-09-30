#include <iostream>
#include <algorithm>
#include <vector>

class CompareMinor {
	public:
		bool operator()(int &i1, int &i2);
};

bool CompareMinor::operator()(int &i1, int &i2) {
	return (i1 > i2);
}

int main() {
	std::vector<int> lista;

	lista.push_back(5);
	lista.push_back(3);
	lista.push_back(9);
	lista.push_back(32);

	std::cout << "lista: ";
	for(std::vector<int>::iterator i=lista.begin(); i!=lista.end(); i++) {
		std::cout << *i << " ";
	}   
	std::cout << std::endl;

	std::make_heap(lista.begin(), lista.end(), CompareMinor());
	std::sort_heap(lista.begin(), lista.end(), CompareMinor());
	std::cout << "lista: ";
	for(std::vector<int>::iterator i=lista.begin(); i!=lista.end(); i++) {
		std::cout << *i << " ";
	}   
	std::cout << std::endl;

	lista.clear();
	std::make_heap(lista.begin(), lista.end(), CompareMinor());
	lista.push_back(5);
	std::make_heap(lista.begin(), lista.end(), CompareMinor());
	lista.push_back(3);
	std::push_heap(lista.begin(), lista.end(), CompareMinor());
	lista.push_back(32);
	std::push_heap(lista.begin(), lista.end(), CompareMinor());
	lista.push_back(1);
	std::push_heap(lista.begin(), lista.end(), CompareMinor());
	lista.push_back(6);
	std::make_heap(lista.begin(), lista.end(), CompareMinor());
	lista.push_back(29);
	std::push_heap(lista.begin(), lista.end(), CompareMinor());
	lista.push_back(33);
	std::push_heap(lista.begin(), lista.end(), CompareMinor());
	lista.push_back(55);
	std::push_heap(lista.begin(), lista.end(), CompareMinor());
	lista.push_back(15);
	std::make_heap(lista.begin(), lista.end(), CompareMinor());
	lista.push_back(13);
	std::push_heap(lista.begin(), lista.end(), CompareMinor());
	lista.push_back(320);
	std::push_heap(lista.begin(), lista.end(), CompareMinor());
	lista.push_back(18);
	std::push_heap(lista.begin(), lista.end(), CompareMinor());

	std::cout << "lista: ";
	while(!lista.empty()) {
		std::cout << lista.front() << " ";
		std::pop_heap(lista.begin(), lista.end(), CompareMinor());
		lista.pop_back();
	}
	std::cout << std::endl;
	
}

