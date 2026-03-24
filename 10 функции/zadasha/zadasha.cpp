#include <iostream>
using namespace std;


unsigned char* packArray(int* source, int size, int& packedSize) {
    packedSize = (size * 5 + 7) / 8; 
    unsigned char* packed = new unsigned char[packedSize];

    
    for (int i = 0; i < packedSize; i++) {
        packed[i] = 0;
    }

    
    for (int j = 0; j < size; j++) {
        int value = source[j];
        int bit = j * 5;
        int bait = bit / 8;
        int smesh = bit % 8;

        if ((smesh + 5) <= 8) {
            packed[bait] |= (value << smesh);
        }
        else {
            packed[bait] |= (value << smesh);
            packed[bait + 1] |= (value >> (8 - smesh));
        }
    }

    return packed;
}


int* unpackArray(unsigned char* packed, int size, int packedSize) {
    int* unpacked = new int[size];

    
    for (int l = 0; l < size; l++) {
        int bit1 = l * 5;
        int bait1 = bit1 / 8;
        int smesh1 = bit1 % 8;
        int value1;

        if ((smesh1 + 5) <= 8) {
            value1 = (packed[bait1] >> smesh1) & 0x1F;
        }
        else {
            int step1 = packed[bait1] >> smesh1;
            int step2 = packed[bait1 + 1] << (8 - smesh1);
            value1 = (step1 | step2) & 0x1F;
        }

        unpacked[l] = value1;
    }

    return unpacked;
}


void printArray(int* arr, int size, int count = 50) {
    for (int i = 0; i < min(count, size); i++) {
        cout << arr[i] << " ";
        if ((i + 1) % 10 == 0) cout << endl;
    }
    cout << endl;
}

int main() {
    setlocale(LC_ALL, "Russian");
    int size;

    cout << "Введите размер массива (больше 1000): ";
    cin >> size;
    while (size <= 1000) {
        cout << "Размер должен быть больше 1000: ";
        cin >> size;
    }

    
    int* arr = new int[size];
    for (int i = 0; i < size; i++) {
        arr[i] = i % 18;  
    }

    cout << "\nИсходный массив (первые 50 элементов):" << endl;
    printArray(arr, size);

    
    int packedSize;
    unsigned char* packed = packArray(arr, size, packedSize);

    int* unpacked = unpackArray(packed, size, packedSize);

    cout << "\nРаспакованный массив (первые 50 элементов):" << endl;
    printArray(unpacked, size);

    
    delete[] arr;
    delete[] packed;
    delete[] unpacked;

    return 0;
}