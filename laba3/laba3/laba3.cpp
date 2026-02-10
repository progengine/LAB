#include <iostream>
using namespace std;
#include <iomanip>

int main() {

	setlocale(LC_ALL, "Russian");

	double sum = 150000.0;
	int srok = 12;
	double stavka = 14;
	double plat = sum / srok; //платеж
	double rate = stavka / 12.0 / 100.0; //ежемесяц.ставка
	double pro = sum * rate; //процент
	double plat2 = plat + pro; // платеж + процент

	double debt = sum;

	double total = 0;

	cout << "| Месяц | Долг      | Процент   | Платеж    |" << endl;
	cout << "|-------|-----------|-----------|-----------|" << endl;

	for (int i = 1; i <= 12; i++) {
		double ine = debt * rate;
		double pay = plat + ine;
		total += ine;

		cout << fixed << setprecision(2);
		cout << "| " << setw(6) << i << " | "
			<< setw(9) << debt << "| "
			<< setw(9) << ine << " | "
			<< setw(9) << pay << " |" << endl;
		

		debt = debt - plat;
		
	}
	cout << "|-------|-----------|-----------|-----------|";
	cout << "\nВсего процентов: " << total << endl;





	


}