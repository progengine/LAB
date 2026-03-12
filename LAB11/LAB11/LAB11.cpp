#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include <stdio.h>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

static int task1() {
    int s;
    cout << "Введите число:" << " ";
    cin >> s;

    int n;
    printf("Введите еще:");
    scanf_s("%d", &n);

    char str[100];
    puts("Введите имя:");
    fgets(str, sizeof(str), stdin);

    FILE* fl = fopen("data.txt", "w");
    if (fl != NULL) {
        fprintf(fl, "hello");
        fclose(fl);
    }

    char buffer[100];
    FILE* fl2 = fopen("data.txt", "r");
    if (fl2 != NULL) {
        fscanf_s(fl2, "%s", buffer, (unsigned)_countof(buffer));
        fclose(fl2);
    }

    cout << buffer << endl;

    char person[7] = "Person";
    ofstream out("data.bin", std::ios::binary);
    if (!out) {
        cout << "Не прочитался" << endl;
    }
    else {
        out.write(person, sizeof(person));
        out.close();
    }

    char personi[7];
    ifstream in("data.bin", std::ios::binary);
    if (!in) {
        cout << "Не прочитался" << endl;
    }
    else {
        in.read(personi, sizeof(personi));
        streamsize byte = in.gcount();
        if (in.eof()) {
            cout << "Достигнут конец файла." << " " << "=" << " " << byte << endl;
        }
        in.close();
    }

    cout << personi << endl;
    return 0;
}

static int task2() {
    ifstream inputFile("11 Tests.txt");
    string line;
    string word;
    vector<string> vec;
    int testNum = 1;
    bool readingWords = true;

    while (getline(inputFile, line)) {
        if (line.find("Test") != string::npos) {
            readingWords = true;
            continue;
        }

        if (line.find("===") == 0) {
            if (!vec.empty()) {
                vector<int> counts(vec.size(), 0);

                for (int i = 0; i < vec.size(); i++) {
                    for (int j = 0; j < vec.size(); j++) {
                        if (i != j && (vec[i].length() <= vec[j].length())) {
                            if (vec[j].find(vec[i]) == 0) {
                                counts[i]++;
                            }
                        }
                    }
                }

                auto max_it = max_element(counts.begin(), counts.end());
                auto index = max_it - counts.begin();
                int maxleng = 0;
                int maxin = 0;

                for (int l = 0; l < vec.size(); l++) {
                    if (counts[l] > 0) {
                        if (vec[l].length() > maxleng) {
                            maxleng = vec[l].length();
                            maxin = l;
                        }
                    }
                }

                string file1 = "longest_root_test" + to_string(testNum) + ".txt";
                string file2 = "important_root_test" + to_string(testNum) + ".txt";

                ofstream outFile(file1);
                ofstream outFile2(file2);

                if (!outFile.is_open() || !outFile2.is_open()) {
                    cout << "Ошибка!";
                    return 1;
                }

                bool hasRoot = false;
                for (int i = 0; i < counts.size(); i++) {
                    if (counts[i] > 0) {
                        hasRoot = true;
                        break;
                    }
                }

                if (!hasRoot) {
                    outFile << "NO";
                    outFile2 << "NO";
                }
                else {
                    outFile << vec[maxin];
                    for (int p = 0; p < vec.size(); p++) {
                        if (p != maxin && vec[p].find(vec[maxin]) == 0) {
                            outFile << " " << vec[p];
                        }
                    }
                    outFile2 << vec[index] << " " << counts[index];
                }

                outFile.close();
                outFile2.close();
                testNum++;
                vec.clear();
            }
            readingWords = false;
        }
        else if (readingWords && !line.empty()) {
            stringstream ss(line);
            while (ss >> word) {
                vec.push_back(word);
            }
        }
    }

    if (!vec.empty()) {
        vector<int> counts(vec.size(), 0);

        for (int i = 0; i < vec.size(); i++) {
            for (int j = 0; j < vec.size(); j++) {
                if (i != j && (vec[i].length() <= vec[j].length())) {
                    if (vec[j].find(vec[i]) == 0) {
                        counts[i]++;
                    }
                }
            }
        }

        auto max_it = max_element(counts.begin(), counts.end());
        auto index = max_it - counts.begin();
        int maxleng = 0;
        int maxin = 0;

        for (int l = 0; l < vec.size(); l++) {
            if (counts[l] > 0) {
                if (vec[l].length() > maxleng) {
                    maxleng = vec[l].length();
                    maxin = l;
                }
            }
        }

        string file1 = "longest_root_test" + to_string(testNum) + ".txt";
        string file2 = "important_root_test" + to_string(testNum) + ".txt";

        ofstream outFile(file1);
        ofstream outFile2(file2);

        if (!outFile.is_open() || !outFile2.is_open()) {
            cout << "Ошибка!";
            return 1;
        }

        bool hasRoot = false;
        for (int i = 0; i < counts.size(); i++) {
            if (counts[i] > 0) {
                hasRoot = true;
                break;
            }
        }

        if (!hasRoot) {
            outFile << "NO";
            outFile2 << "NO";
        }
        else {
            outFile << vec[maxin];
            for (int p = 0; p < vec.size(); p++) {
                if (p != maxin && vec[p].find(vec[maxin]) == 0) {
                    outFile << " " << vec[p];
                }
            }
            outFile2 << vec[index] << " " << counts[index];
        }

        outFile.close();
        outFile2.close();
    }

    return 0;
}

int main() {
    setlocale(LC_ALL, "Russian");
    int choice;
    cout << "======== Меню программы ========" << endl;
    cout << "II.1.	ВАРИАНТЫ ВВОДА-ВЫВОДА" << endl;
    cout << "II.2.	КОРНЕВЫЕ СЛОВА" << endl;
    cout << "Ваш выбор:" << " ";
    cin >> choice;

    if (cin.fail()) {
        cout << "error";
        return 0;
    }

    switch (choice) {
    case 1: task1(); break;
    case 2: task2(); break;
    default:
        cout << "Ничего не выбрано" << endl;
    }
}