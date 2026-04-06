#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

const double EPS = 1e-9;

// "Функция приведения матрицы к ступенчатому виду"
int gauss(vector<vector<double>>& a, int m, int n, vector<int>& where) {
    where.assign(n, -1);
    int row = 0;

    for (int col = 0; col < n && row < m; ++col) {
        int sel = row;
        for (int i = row; i < m; ++i) {
            if (fabs(a[i][col]) > fabs(a[sel][col])) {
                sel = i;
            }
        }

        if (fabs(a[sel][col]) < EPS) {
            continue;
        }

        for (int j = col; j <= n; ++j) {
            swap(a[sel][j], a[row][j]);
        }

        where[col] = row;

        double div = a[row][col];
        for (int j = col; j <= n; ++j) {
            a[row][j] /= div;
        }

        for (int i = 0; i < m; ++i) {
            if (i != row && fabs(a[i][col]) > EPS) {
                double mult = a[i][col];
                for (int j = col; j <= n; ++j) {
                    a[i][j] -= mult * a[row][j];
                }
            }
        }

        ++row;
    }

    return row;
}

// "Функция проверки системы на совместность"
bool is_consistent(const vector<vector<double>>& a, int m, int n) {
    for (int i = 0; i < m; ++i) {
        bool all_zero = true;
        for (int j = 0; j < n; ++j) {
            if (fabs(a[i][j]) > EPS) {
                all_zero = false;
                break;
            }
        }
        if (all_zero && fabs(a[i][n]) > EPS) {
            return false;
        }
    }
    return true;
}

// "Функция вывода решения"
void print_solution(const vector<vector<double>>& a, int m, int n, const vector<int>& where) {
    cout << "-----------------------------------------" << endl;

    if (!is_consistent(a, m, n)) {
        cout << "Inconsistent system" << endl;
        return;
    }

    int rank = 0;
    for (int i = 0; i < n; ++i) {
        if (where[i] != -1) rank++;
    }

    if (rank == n) {
        cout << "Unique solution:" << endl;
        vector<double> solution(n);
        for (int i = 0; i < n; ++i) {
            solution[i] = a[where[i]][n];
        }
        for (int i = 0; i < n; ++i) {
            cout << "x" << i + 1 << " = " << solution[i];
            if (i < n - 1) cout << "; ";
        }
        cout << endl;
    }
    else {
        cout << "General solution (infinite many):" << endl;
        vector<bool> is_free(n, true);
        for (int i = 0; i < n; ++i) {
            if (where[i] != -1) is_free[i] = false;
        }

        for (int i = 0; i < n; ++i) {
            if (!is_free[i]) {
                int row = where[i];
                cout << "x" << i + 1 << " = " << a[row][n];
                for (int j = 0; j < n; ++j) {
                    if (is_free[j] && fabs(a[row][j]) > EPS) {
                        double coef = -a[row][j];
                        if (coef > 0) cout << " + " << coef << "*x" << j + 1;
                        else cout << " - " << fabs(coef) << "*x" << j + 1;
                    }
                }
                cout << endl;
            }
            else {
                cout << "x" << i + 1 << " is free" << endl;
            }
        }
    }
    cout << "-----------------------------------------" << endl;
}

int main() {
    setlocale(LC_ALL, "Russian");
    string filename = "13 Тесты.txt";
    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "Ошибка: не удалось открыть файл " << filename << endl;
        return 1;
    }

    string line;
    int test_num = 0;

    while (getline(file, line)) {
        // "Пропускаем пустые строки"
        if (line.empty()) continue;

        // "Пытаемся прочитать из строки два числа (m и n)"
        stringstream ss(line);
        int m, n;
        ss >> m >> n;

        
        if (ss && m > 0 && m <= 100 && n > 0 && n <= 100) {
            test_num++;
            cout << "\n========== TEST " << test_num << " ==========" << endl;
            cout << "Размер: " << m << "x" << n << endl;

            // "Читаем матрицу"
            vector<vector<double>> a(m, vector<double>(n + 1));
            int rows_read = 0;

            while (rows_read < m && getline(file, line)) {
                if (line.empty()) continue;

                stringstream ss2(line);
                bool has_number = false;
                vector<double> row(n + 1);
                for (int j = 0; j <= n; ++j) {
                    if (!(ss2 >> row[j])) {
                        break;
                    }
                    has_number = true;
                }

                if (has_number) {
                    for (int j = 0; j <= n; ++j) {
                        a[rows_read][j] = row[j];
                    }
                    rows_read++;
                }
            }

            // "Проверяем, что прочитали всю матрицу"
            if (rows_read < m) {
                cout << "Ошибка: недостаточно данных в файле для теста " << test_num << endl;
                continue;
            }

            // "Выводим исходную матрицу"
            cout << "Исходная матрица:" << endl;
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j <= n; ++j) {
                    cout << a[i][j] << "\t";
                }
                cout << endl;
            }

            // "Приводим к ступенчатому виду"
            vector<int> where;
            int rank = gauss(a, m, n, where);

            cout << "Ступенчатый вид:" << endl;
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j <= n; ++j) {
                    cout << a[i][j] << "\t";
                }
                cout << endl;
            }

            cout << "Ранг: " << rank << endl;
            print_solution(a, m, n, where);
        }
    }

    file.close();
    cout << "\nОбработано тестов: " << test_num << endl;

    return 0;
}