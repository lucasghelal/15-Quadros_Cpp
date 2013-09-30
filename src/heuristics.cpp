#include <iostream>
#include "headers/heuristics.h"

float out_of_order_heuristic(int mat[][4]) {
	int n = 1;
	float pieces_n = 0;
	for(int i=0; i<4; i++) {
		for(int j=0; j<4; j++) {
			if(mat[i][j] != n) pieces_n++;
			n++;
		}
	}
	return pieces_n;
}

float out_of_sequence_heuristic(int mat[][4]) {
	float pieces_n = 0;
	int next_lin, next_col;
	for(int i=0; i<4; i++) {
		for(int j=0; j<4; j++) {
			if(mat[i][j] != 0) {
				next_col = j+1;
				next_lin = i;
				if((j == 3) && (i != 3)) {
					next_col = 0;
					next_lin = i+1;
				}
				if(!((i == 3) && (j == 3)) && (mat[i][j]+1 != mat[next_lin][next_col]))
					pieces_n++;
			}
		}
	}
	return pieces_n;
}

float calc_dist(int mat[][4], int lin, int col) {
	int pos_lin, pos_col;
	float total;
	pos_lin = (mat[lin][col] - 1) / 4;
	pos_col = (mat[lin][col] - 1) % 4;
	pos_lin -= lin;
	pos_col -= col;
	if(pos_lin < 0) pos_lin *= -1;
	if(pos_col < 0) pos_col *= -1;
	return (float) (pos_lin + pos_col);
}

float rect_distance_heuristic(int mat[][4]) {
	float mov = 0;
	int n = 1;
	for(int i=0; i<4; i++) {
		for(int j=0; j<4; j++) {
			if(mat[i][j] != 0)
				if(mat[i][j] != n)
					mov += calc_dist(mat, i, j);
			n++;
		}
	}
	return mov;
}
