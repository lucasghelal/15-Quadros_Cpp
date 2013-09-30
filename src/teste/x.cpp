#include <iostream>
#include <cstdlib>
#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
string change();

int main() {
	string a = "";
	a += change();
	a = a + "lalalalal";
	cout << a << endl;
}

string change() {
	return "sousousou";
}
