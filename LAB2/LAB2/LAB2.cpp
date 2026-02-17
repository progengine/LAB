#include <iostream>
using namespace std;
#include <array>
#include <stdlib.h>
#include <ctime>


int task1() {
	int arr[10];
	for (int i = 0; i < 10; i++) {
		arr[i] = i * i;
	}

	cout << "статический массив, индексная адресация" << endl;
	for (int j = 0; j < 10; j++) {
		cout << arr[j] << " ";
	}
	cout << endl << endl;

	int* ptr;
	ptr = &arr[0];

	for (int d = 0; d < 10; d++) {
		*(ptr + d) = d * d;
	}

	cout << "статический массив, адресация  с помощью указателя (косвенная адресация)" << endl;
	for (int s = 0; s < 10; s++) {
		cout << *(ptr + s) << " ";
	}
	cout << endl << endl;

	int size;
	cout << "Введите размер массива:" << endl;
	cin >> size;
	int* arr2 = new int[size];

	int* ptr2 = arr2;

	for (int l = 0; l < size; l++) {
		arr2[l] = l * l;
	}

	cout << "динамический массив, индексная адресация" << endl;
	for (int h = 0; h < size; h++) {
		cout << arr2[h] << " ";
	}
	cout << endl << endl;

	for (int p = 0; p < size; p++) {
		*(ptr2 + p) = p * p;
	}

	cout << "динамический массив, адресация  с помощью указателя (косвенная адресация)" << endl;
	for (int u = 0; u < size; u++) {
		cout << *(ptr2 + u) << " ";
	}
	cout << endl << endl;

	delete[] arr2;

	return 0;
}


void sort(int arr[],int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}

int task2() {

	srand(time(0));

	int size1;
	cout << "Введите размер первого массива:" << " ";
	cin >> size1;
	int* arr1 = new int[size1];

	int size2;
	cout << "Введите размер второго массива:" << " ";
	cin >> size2;
	int* arr2 = new int[size2];

	for (int i = 0; i < size1; i++) {
		arr1[i] = rand() % 100;
	}

	for (int j = 0; j < size2; j++) {
		arr2[j] = rand() % 100;
	}


	sort(arr1, size1);
	sort(arr2, size2);


	int size3 = size1 + size2;
	int* arr3 = new int[size3];

	int i = 0;
	int j = 0;
	int k = 0;

	while ((i < size1) && (j < size2)) {
		if (arr1[i] > arr2[j]) {
			arr3[k] = arr2[j];
			j++;
			k++;
		}
		else if (arr1[i] < arr2[j]) {
			arr3[k] = arr1[i];
			i++;
			k++;
		}
		else {
			arr3[k] = arr1[i];
			i++;
			k++;
			arr3[k] = arr2[j];
			j++;
			k++;
		}
	}

	while (i < size1) {
		arr3[k] = arr1[i];
		i++;
		k++;
	}

	while (j < size2) {
		arr3[k] = arr2[j];
		j++;
		k++;
	}

	int* pt = arr3;

	cout << "Массив после слияния:" << endl;

	for (int x = 0; x < size3; x++) {
		cout << *(pt + x) << " ";  
	}
	cout << endl;  

	delete[] arr1;
	delete[] arr2;
	delete[] arr3;

	return 0;
}


int task3() {
	struct node {
		int data;
		node* next;
		node* previos;
		node(int data) : data(data), next(nullptr), previos(nullptr){}
	};


	node* newnode = new node(1);
	node* head = newnode;
	node* tail = newnode;

	newnode = new node(2);
	tail->next = newnode;
	newnode->previos = tail;
	tail = newnode;

	newnode = new node(3);
	tail->next = newnode;
	newnode->previos = tail;
	tail = newnode;

	newnode = new node(4);
	tail->next = newnode;
	newnode->previos = tail;
	tail = newnode;

	newnode = new node(5);
	tail->next = newnode;
	newnode->previos = tail;
	tail = newnode;

	newnode = new node(6);
	tail->next = newnode;
	newnode->previos = tail;
	tail = newnode;

	newnode = new node(7);
	tail->next = newnode;
	newnode->previos = tail;
	tail = newnode;

	newnode = new node(8);
	tail->next = newnode;
	newnode->previos = tail;
	tail = newnode;

	newnode = new node(9);
	tail->next = newnode;
	newnode->previos = tail;
	tail = newnode;

	newnode = new node(10);
	tail->next = newnode;
	newnode->previos = tail;
	tail = newnode;

	node* current = head;

	while (current != nullptr) {
		cout << current->data << " ";
		current = current->next;
	}

	return 0;
	
}

int main() {
	setlocale(LC_ALL, "Russian");

	cout << "========Меню программы========"<<endl;
	cout << "1. 4 варианта алгоритма заполнения целочисленного массива" << endl;
	cout << "2. Объединение двух упорядоченных массивов" << endl;
	cout << "3. создания двусвязного самоадресуемого списка" << endl;
	cout << "Ваш выбор:" << " ";

	int choice;
	cin >> choice;

	if (cin.fail()) {
		cout << "Ошибка!";
		return 0;
	}

	switch (choice) {
	case 1: task1(); break;
	case 2: task2(); break;
	case 3: task3(); break;
	case 4: 
		break;
	default:
		cout << "Ничего не выбрано или неверный выбор" << endl;
	}
}