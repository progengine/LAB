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

	place(0, matrix, k);
	for (int i = 0; i < k; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;
}




