#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

// Чтение ребер из файла
// "n m" (вершины, ребра)
vector<pair<int, int>> readEdges(const string& filename, int& n, int& m) {
    ifstream fin(filename);
    vector<pair<int, int>> edges;

    if (!fin.is_open()) {
        cerr << "Ошибка открытия файла " << filename << endl;
        return edges;
    }

    fin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        fin >> u >> v;
        edges.push_back({ u, v });
    }

    fin.close();
    return edges;
}


// Построение матрицы смежности для неориентированного графа
void exercise1(const string& inputFile, const string& outputFile) {
    int n, m;
    vector<pair<int, int>> edges = readEdges(inputFile, n, m);

    // Матрица смежности (нумерация вершин с 1, размер n+1 x n+1)
    vector<vector<int>> M(n + 1, vector<int>(n + 1, 0));

    for (auto& e : edges) {
        int u = e.first;
        int v = e.second;
        M[u][v] = 1;
        M[v][u] = 1;  // неориентированный граф
    }

    ofstream fout(outputFile);
    fout << n << endl;  // сохраняем размер для упр. 2
    fout << "Матрица смежности (" << n << " x " << n << "):" << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            fout << M[i][j] << " ";
        }
        fout << endl;
    }
    fout.close();

    cout << "Упражнение 1: матрица смежности -> " << outputFile << endl;
}


// Построение массива номеров смежных вершин 
void exercise2(const string& inputFile, const string& outputFile) {
    ifstream fin(inputFile);
    int n;
    string line;

    fin >> n;
    getline(fin, line);          // остаток первой строки
    getline(fin, line);          // заголовок "Матрица смежности..."

    // Чтение матрицы
    vector<vector<int>> M(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            fin >> M[i][j];
        }
    }
    fin.close();

    // Формирование компактного представления
    vector<int> S(n + 1);     // начало списка в D
    vector<int> L(n + 1);     // длина списка
    vector<int> D;            // все смежные вершины подряд

    for (int i = 1; i <= n; i++) {
        S[i] = D.size(); // запоминаем, где начнётся список вершины i
        int count = 0;
        for (int j = 1; j <= n; j++) {
            if (M[i][j] == 1) {
                D.push_back(j);
                count++;
            }
        }
        L[i] = count;
    }

    ofstream fout(outputFile);
    fout << n << endl;  // сохраняем размер
    fout << "Массив номеров смежных вершин:" << endl;
    fout << "S (начало смежных): ";
    for (int i = 1; i <= n; i++) fout << S[i] << " ";
    fout << endl;
    fout << "L (количество):     ";
    for (int i = 1; i <= n; i++) fout << L[i] << " ";
    fout << endl;
    fout << "D (все смежные):    ";
    for (int val : D) fout << val << " ";
    fout << endl;

    // Удобочитаемый вывод списков смежности
    fout << "\nСписки смежности по вершинам:" << endl;
    for (int i = 1; i <= n; i++) {
        fout << i << ": ";
        for (int k = S[i]; k < S[i] + L[i]; k++) {
            fout << D[k] << " ";
        }
        fout << endl;
    }
    fout.close();

    cout << "Упражнение 2: массив номеров смежных вершин -> " << outputFile << endl;
}


// Восстановление последовательности ребер
void exercise3(const string& inputFile, const string& outputFile) {
    ifstream fin(inputFile);
    int n;
    string line;

    fin >> n;
    getline(fin, line);          // остаток строки
    getline(fin, line);          // заголовок

    vector<int> S(n + 1), L(n + 1);
    vector<int> D;

    // Чтение S
    getline(fin, line);  // "S (начало смежных): ..."
    size_t pos = line.find(":");
    istringstream issS(line.substr(pos + 1));
    for (int i = 1; i <= n; i++) issS >> S[i];

    // Чтение L
    getline(fin, line);  // "L (количество): ..."
    pos = line.find(":");
    istringstream issL(line.substr(pos + 1));
    for (int i = 1; i <= n; i++) issL >> L[i];

    // Чтение D
    getline(fin, line);  // "D (все смежные): ..."
    pos = line.find(":");
    istringstream issD(line.substr(pos + 1));
    int val;
    while (issD >> val) D.push_back(val);

    fin.close();

    // Восстановление ребер (каждое выводим один раз)
    ofstream fout(outputFile);
    fout << n << " ";

    // Сначала посчитаем количество ребер
    int edgeCount = 0;
    vector<vector<bool>> printed(n + 1, vector<bool>(n + 1, false));
    for (int i = 1; i <= n; i++) {
        for (int k = S[i]; k < S[i] + L[i]; k++) {
            int j = D[k]; //запоминаем смежную вершину
            if (!printed[i][j]) {
                edgeCount++;
                printed[i][j] = true;
                printed[j][i] = true;
            }
        }
    }
    fout << edgeCount << endl;

    // Выводим ребра
    fout << "Последовательность ребер неориентированного графа:" << endl;
    printed.assign(n + 1, vector<bool>(n + 1, false));
    for (int i = 1; i <= n; i++) {
        for (int k = S[i]; k < S[i] + L[i]; k++) {
            int j = D[k];
            if (!printed[i][j]) {
                fout << i << " " << j << endl;
                printed[i][j] = true;
                printed[j][i] = true;
            }
        }
    }
    fout.close();

    cout << "Упражнение 3: последовательность ребер -> " << outputFile << endl;
}


int main() {
    setlocale(LC_ALL, "Russian");

    // Имена рабочих файлов
    string inputFile = "edges.txt";
    string matrixFile = "matrix.txt";
    string listFile = "adjlist.txt";
    string edges2File = "edges2.txt";

    // Упражнение 1: edges.txt -> matrix.txt
    exercise1(inputFile, matrixFile);

    // Упражнение 2: matrix.txt -> adjlist.txt
    exercise2(matrixFile, listFile);

    // Упражнение 3: adjlist.txt -> edges2.txt
    exercise3(listFile, edges2File);

    cout << "\nВсе упражнения выполнены." << endl;
    return 0;
}