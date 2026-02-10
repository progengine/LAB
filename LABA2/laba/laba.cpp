#include <iostream>
using namespace std;
#include <cmath>

int main() {
	
	setlocale(LC_ALL, "Russian");
	
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

	

}