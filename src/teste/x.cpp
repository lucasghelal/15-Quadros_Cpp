#include <iostream>
#include <cstdlib>
#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
void print(int(*)[2]);

int main() {
	int matrix[2][2];
	print(matrix);
	cout << "matriz: ";
	for(int i=0; i<2; i++) {
		for(int j=0; j<2; j++) {
			cout << matrix[i][j] << " ";
		}
	}
	cout << endl;
}

void print(int x[][2]) {
	int (*mat)[2] = x;
	mat[0][0] = 1;
	mat[0][1] = 2;
	mat[1][0] = 3;
	mat[1][1] = 4;
}

