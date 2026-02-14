#include <iostream>
using namespace std;
#include <cmath>
#include <iomanip>
#include <stdio.h>

int task1() {

	cout << "Введите начальную точку:" << endl;

	double z;
	double x;
	double y;

	cin >> z;

	if (z <= 4 && z > 0) {
		cout << "Точка входит в интервал!" << endl;
	}
	else {
		cout << "Точка не входит в интервал!" << endl;
		return 0;
	}

	double count = (4 - z) / 9;
	for (int i = 0; i < 10; i++) {
		x = z + i * count;
		y = sin(x) / x;
		cout << "Точка " << (i + 1) << ": x = " << x
			<< ", f(x) = " << y << endl;

	}
	cin.get();
	cin.get();

	return 0;
}

int task2() {

	int max = 0;
	cout << "Введите число max" << endl;
	cin >> max;
	int s = 0;
	int n = 0;
	int f1 = 0;
	int f2 = 1;
	int f3;

	if (s + f1 <= max) {
		s = s + f1;
		n++;
	}

	if (s + f2 <= max) {
		s = s + f2;
		n++;
	}

	while (true) {
		f3 = f1 + f2;
		if (s + f3 <= max) {
			s = s + f3;
			n++;
			f1 = f2;
			f2 = f3;
		}
		else {
			break;
		}
	}

	cout << "Количество чисел Фибоначчи: " << n << endl;
	cout << "Их сумма: " << s << endl;

	return 0;
}

int task3() {


	double sum;
	printf("Введите сумму кредита:\n");
	scanf_s("%lf", &sum);
	int srok;
	printf("Введите срок кредита:\n");
	scanf_s("%d", &srok);
	double stavka;
	printf("Введите годовую ставку:\n");
	scanf_s("%lf", &stavka);
	double plat = sum / srok; //платеж
	double rate = stavka / 12.0 / 100.0; //ежемесяц.ставка

	double debt = sum;

	double total = 0;

	printf("| Месяц | Долг      | Процент   | Платеж    |\n");
	printf("|-------|-----------|-----------|-----------|\n");

	for (int i = 1; i <= srok; i++) {
		double ine = debt * rate;
		double pay = plat + ine;
		total += ine;

		printf("| %6d | %9.2f| %9.2f | %9.2f |\n", i, debt, ine, pay);


		debt = debt - plat;

	}
	printf("|-------|-----------|-----------|-----------|\n");
	printf("Всего процентов: %.2f\n", total);

	return 0;

}

int main() {
	setlocale(LC_ALL, "Russian");
	cout << "==Начало программы==" << endl;
	cout << "1. Функция " << endl;
	cout << "2. Числа Фибоначчи" << endl;
	cout << "3. Кредиты " << endl;
	cout << "Введите число, чтобы выбрать программу:" << endl;


	int choice;
	cin >> choice;

	if (cin.fail()) {
		cout << "Ошибка ввода. Завершение программы." << endl;
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