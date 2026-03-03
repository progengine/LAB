#include <iostream>
using namespace std;
#include <array>


int main() {

	setlocale(LC_ALL, "Russian");

	int size;

	cout << "Введите размер массива:" << " ";
	cin >> size;

	int* arr = new int[size];

	cout << "Введите значения массива:" << endl;

	for (int i = 0; i < size; i++) {
		cin >> arr[i];
		if(arr[i] < 0 || arr[i] > 17){
			cout << "Не в интервале" << endl;
			break;
		}
	}


	int size2 = size * 5; //бит
	int size3 = (size * 5 + 7) / 8; //байт

	unsigned char* arr2 = new unsigned char[size3];
	for (int i = 0; i < size3; i++) {
		arr2[i] = 0;
	}

	for (int j = 0; j < size; j++) {
		int value = arr[j];
		int bit = j * 5;
		int bait = bit / 8;
		int smesh = bit % 8;

		if ((smesh + 5) <= 8) {
			arr2[bait] |= (value << smesh);
		}
		else {
			arr2[bait] |= (value << smesh);
			arr2[bait + 1] |= (value >> (8 - smesh));
		}
	}

	int* arr3 = new int[size];
	for (int l = 0; l < size; l++) {
		int bit1 = l * 5;
		int bait1 = bit1 / 8;
		int smesh1 = bit1 % 8;
		int value1;
		if ((smesh1 + 5) <= 8) {
			value1 = (arr2[bait1] >> smesh1) & 0x1F;
		}
		else {
			int step1 = arr2[bait1] >> smesh1;
			int step2 = arr2[bait1 + 1] << (8 - smesh1);
			value1 = (step1 | step2) & 0x1F;
		}

		arr3[l] = value1;
	}

	cout << "Распакованный массив:" << endl;
	for (int i = 0; i < size; i++) {
		cout << arr3[i] << " ";
	}
	cout << endl;

	delete[] arr;
	delete[] arr2;
	delete[] arr3;
	
}





