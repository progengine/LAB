#include <iostream>;
using namespace std;

int main() {

	setlocale(LC_ALL, "Russian");

	int f1 = 0;
	int f2 = 1;
	int s = 0;
	int n;
	
	cout << "Введите n чисел Фибоначчи" << endl;
	cin >> n;

	for (int k = 2; k <= n; k++) {
		int f3 = f1 + f2;
		s = f3;
		f1 = f2;
		f2 = f3;
	}

	cout << "Введите максимальное число" << endl;
	int Max;
	cin >> Max;

	if (s > Max) {
		cout << "NO!";
	}
	else {
		cout << s;
	}

}