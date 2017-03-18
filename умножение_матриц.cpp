
#include "stdafx.h"
#include <iostream>
#include <conio.h>
using namespace std;

void matrix_output(int ** MATRIX, int STRINGS, int COLUMNS);

int main() {
	int DIM_a = 0, DIM_b = 0, DIM_c = 0, DIM_d = 0;
	char ch;

	cout << "<=MATRIX\=>\n\Enter the dimension of 1st matrix: ";
	cin >> DIM_a >> DIM_b;
	cout << "Enter the dimension of 2nd matrix: ";
	cin >> DIM_c >> DIM_d;

	if (DIM_b != DIM_c) {
		cout << "\nMatrix product is not determind!";
		_getch();
		return 0;
	}

	int ** mat_A = new int *[DIM_a];
	for (int i = 0; i < DIM_a; i++)
		mat_A[i] = new int[DIM_b];

	int ** mat_B = new int *[DIM_c];
	for (int i = 0; i < DIM_c; i++)
		mat_B[i] = new int[DIM_d];

	int ** mat_C = new int *[DIM_a];
	for (int i = 0; i < DIM_a; i++)
		mat_C[i] = new int[DIM_d];

	cout << endl;
	for (int m = 0; m < DIM_a; m++) {
		for (int n = 0; n < DIM_b; n++) {
			cout << "a" << m + 1 << "_" << n + 1 << " = ";
			cin >> mat_A[m][n];
		}
		cout << endl;
	}

	cout << "----------------------------------------\n\n";
	for (int m = 0; m < DIM_c; m++) {
		for (int n = 0; n < DIM_d; n++) {
			cout << "b" << m + 1 << "_" << n + 1 << " = ";
			cin >> mat_B[m][n];
		}
		cout << endl;
	}	
	
	cout << "First matrix:" << endl;
	for (unsigned int m = 0; m<DIM_a; ++m)
	{
		for (unsigned int n = 0; n<DIM_b; ++n)
			cout << mat_A[m][n] << "  ";
		cout << endl;
	}

	cout << "Second matrix:" << endl;
	for (unsigned int m = 0; m<DIM_c; ++m)
	{
		for (unsigned int n = 0; n<DIM_d; ++n)
			cout << mat_B[m][n] << "  ";
		cout << endl;
	}
	cout << "----------------------------------------\n\n";


	matrix_output(mat_A, DIM_a, DIM_b);
	matrix_output(mat_B, DIM_c, DIM_d);

	cout << "----------------------------------------\n\n";

	int prod1 = 1, prod2 = 1, summ = 0;
	for (int m = 0; m < DIM_a; m++) {
		for (int n = 0; n < DIM_d; n++) {

			summ = 0;
			for (int c = 0; c < DIM_b; c++)
				summ += mat_A[m][c] * mat_B[c][n];
			mat_C[m][n] = summ;
		}
	}

	matrix_output(mat_C, DIM_a, DIM_d);


	for (int i = 0; i < DIM_a; i++)
		delete[] mat_A[i];
	delete[] mat_A;

	_getch();
	return 0;
}

void matrix_output(int ** MATRIX, int ROWS, int COLUMNS) {
	if (ROWS == 1) {
		for (int c = 0; c < COLUMNS; c++)
			cout << " " << MATRIX[0][c];
	}
	else {
		for (int c = 0; c < ROWS; c++) {
			if (c == 0)
				cout << '\x2f';
			else if (c == ROWS - 1)
				cout << '\x5c';
			else
				cout << '\x7c';

			for (int d = 0; d < COLUMNS; d++)
				cout << " " << MATRIX[c][d];

			if (c == 0)
				cout << " " << '\x5c';
			else if (c == ROWS - 1)
				cout << " " << '\x2f';
			else
				cout << " " << '\x7c';

			cout << endl;
		}
		cout << endl;
	}
}