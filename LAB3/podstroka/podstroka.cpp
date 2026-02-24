#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include <string>
#include <cstring>
#include <string.h>


int task1() {
	string siplus = "good";
	char let [15] = {'g','w','o','d','\0'};

	//ci++

	int sizeci = siplus.length();
	cout << "Длина строки в ++" << " " << "=" << " "<< sizeci << endl;
	string kop;
	kop.append(siplus);

	cout << "Копируемая строка в ++" << " "<<"="<<" " << kop << endl;

	

	if (siplus.find('g') != string::npos ) {
		cout << "Проверка на find = g" << endl;
	}
	
	//ci

	int sizeci2 = strlen(let);

	cout << "Длина строки в си" << " " << "="<<" " << sizeci2 << endl;

	char let2[15] = {};
	strcpy(let2, let);

	cout << "Копируемая строка в си" << " "<<"="<< " " << let2 << endl;

	
	if (strchr(let, 'w')) {
		cout << "Првоверка на find = w";
	}

	return 0;

}


int task2() {
	int size;

	cout << "Введите длину массива слов:" << endl;
	cin >> size;

	if (size > 20) {
		cout << "Много" << endl;
		return 0;
	}

	string* arr = new string[size];

	cout << "Введите слова в сам массив:" << endl;

	for (int i = 0; i < size; i++) {
		cin >> arr[i];
		if (arr[i].length() > 10) {
			cout << "Максильная длина слова 10" << endl;
			return 0;
		}
	}

	cout << "Слова с четным номер:" << " ";

	for (int j = 0; j < size; j++) {
		if (j % 2 == 0) {
			cout << arr[j] << " ";
		}
	}

	delete[] arr;

	return 0;

}

int task3() {
	int size;

	cout << "Введите длину size:" << endl;

	cin >> size;

	char mass[20][11];

	if (size > 20) {
		cout << "Много" << endl;
		return 0;
	}

	cout << "Введите слова в сам массив:" << endl;

	for (int i = 0; i < size; i++) {
		cin >> mass[i];
		if (strlen(mass[i]) > 10) {
			cout << "> 10" << endl;
			return 0;
		}
	}

	cout << "Слова с четным номер:" << " ";

	for (int j = 0; j < size; j++) {
		if (j % 2 == 0) {
			cout << mass[j] << " ";
		}
	}

	return 0;
}

int main() {

	setlocale(LC_ALL, "Russian");

	int choice;

	cout << "======== Меню программы ========" << endl;
	cout << "1. 3 функции в С++ и Си" << endl;
	cout << "2. Массив для С++" << endl;
	cout << "3. Массив для Си" << endl;
	cout << "Ваш выбор:" << " ";
	cin >> choice;

	if (cin.fail()) {
		cout << "Ops";
		return 0;
	}

	switch (choice) {
	case 1: task1(); break;
	case 2: task2(); break;
	case 3: task3(); break;
	case 4:
		break;
	default:
		cout << "Ничего не выбрано" << endl;
	}
}