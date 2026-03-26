#include <iostream>
using namespace std;
#include <array>

int canplace(int row, int col, int** matrix, int k) {
	for (int i = row - 1; i >= 0; --i) {
		if (matrix[i][col] == 1) {
			return false;
		}
	}

	int r = row - 1, j = col - 1;
	while (r >= 0 && j >= 0) {
		if (matrix[r][j] == 1) return false; //главная диаг
		r--;
		j--;
	}

	int q = row - 1, m = col + 1;
	while (q >= 0 && m < k) {
		if (matrix[q][m] == 1) return false; //побочная диаг
		q--;
		m++;
	}

	return true;

}


void place(int row, int** matrix, int k) {
	if (row == k) {
		for (int i = 0; i < k; i++) {
			for (int j = 0; j < k; j++) {
				if (matrix[i][j] == 1) {
					cout << j + 1 << " ";
					break;
				}
			}
		}

		return;
	}
	else {
		for (int col = 0; col < k; col++) {
			if (canplace(row, col, matrix, k) == true) {
				matrix[row][col] = 1;
				place(row + 1, matrix, k);
				matrix[row][col] = 0;
			}
		}
	}


}

void fastplace(int row,int colUsed[],int diag1[],int diag2[],int queens[],int k) {
	if (row == k) {
		for (int i = 0; i < k; i++){
			cout << queens[i] + 1 << " ";
		}
		return;
	}
	else {
		for (int col = 0; col < k; col++) {
			if (colUsed[col] == 0 && diag1[row - col + (k - 1)] == 0 && diag2[row + col] == 0) {
				colUsed[col] = 1;
				diag1[row - col + (k - 1)] = 1;
				diag2[row + col] = 1;
				queens[row] = col;
				fastplace(row + 1, colUsed, diag1, diag2, queens, k);
				colUsed[col] = 0;
				diag1[row - col + (k - 1)] = 0;
				diag2[row + col] = 0;

			}
		}
	}
	
}


int main() {
	setlocale(LC_ALL, "Russian");
	int k;
	cout << "Введите количество ферзей:" << " ";
	cin >> k;
	int** matrix = new int* [k];
	for (int i = 0; i < k; i++) {
		matrix[i] = new int[k];
	}
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < k; j++) {
			matrix[i][j] = 0;
		}
	}

	cout << "\nМатричный способ:\n";
	place(0, matrix, k);
	for (int i = 0; i < k; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;

	int* colUsed = new int[k];
	int* diag1 = new int[(2 * k) - 1];
	int* diag2 = new int[(2 * k) - 1];
	int* queens = new int[k];

	for (int i1 = 0; i1 < k; i1++) {
		colUsed[i1] = 0;
	}
	for (int i2 = 0; i2 < (2*k) - 1; i2++) {
		diag1[i2] = 0;
	}
	for (int i3 = 0; i3 < (2*k)-1; i3++) {
		diag2[i3] = 0;
	}
	for (int i4 = 0; i4 < k; i4++) {
		queens[i4] = 0;
	}

	cout << "\nБыстрый способ:\n";
	fastplace(0, colUsed, diag1, diag2, queens, k);

	delete[] colUsed;
	delete[] diag1;
	delete[] diag2;
	delete[] queens;


}




