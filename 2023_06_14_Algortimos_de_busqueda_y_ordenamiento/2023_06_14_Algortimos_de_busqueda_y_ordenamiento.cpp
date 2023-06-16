#include <iostream>
#include <Windows.h>
#include <cstdlib>
#include <ctime>

using namespace std;

void shellSort(int arr[], int n) {
    int gap = n / 2;
    while (gap > 0) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j = i;
            while (j >= gap && arr[j - gap] > temp) {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = temp;
        }
        gap /= 2;
    }
}

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void cocktailSort(int arr[], int n) {
    bool swapped = true;
    int start = 0;
    int end = n - 1;

    while (swapped) {
        swapped = false;

        for (int i = start; i < end; i++) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }

        if (!swapped) {
            break;
        }

        swapped = false;
        end--;

        for (int i = end - 1; i >= start; i--) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }

        start++;
    }
}

int sequentialSearch(const int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

int binarySearch(const int arr[], int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid;
        }
        if (arr[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return -1;
}

int main() {
    const int ARRAY_SIZE = 100;
    int searchChoice;
    int sortChoice;
    int target;
    int index;
    int arr[ARRAY_SIZE];

    srand(time(0));
    for (int i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = rand() % 1000;
    }
    cout << "=====================================================" << endl;
    cout << "|| Seleccione el algoritmo de ordenamiento deseado ||" << endl;
    cout << "||                     0) shell sort               ||" << endl;
    cout << "||                     1) bubble sort              ||" << endl;
    cout << "||                     2) coctail sort             ||" << endl;
    cout << "=====================================================" << endl;
    cin >> sortChoice;
    cout << "\n\n" << endl;
    Sleep(4000);
    system("CLS");

    cout << "Arreglo desordenado: ";
    for (int i = 0; i < ARRAY_SIZE; i++) {
        cout << arr[i] << " ";
    }
    cout<<"\n\n" << endl;
    Sleep(4000);
    system("CLS");

    switch (sortChoice) {
    case 0:
        shellSort(arr, ARRAY_SIZE);
        cout << "Arreglo ordenado usando Shell Sort." << endl;
        break;
    case 1:
        bubbleSort(arr, ARRAY_SIZE);
        cout << "Arreglo ordenado usando Bubble Sort." << endl;
        break;
    case 2:
        cocktailSort(arr, ARRAY_SIZE);
        cout << "Arreglo ordenado usando Cocktail Sort." << endl;
        break;
    default:
        cout << "Opcion de ordenamiento no valida." << endl;
        return 0;
    }


    cout << "Arreglo ordenado: ";
    for (int i = 0; i < ARRAY_SIZE; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "\n\n" << endl;


    
    cout << "Ingrese el numero a buscar: ";
    cin >> target;


    
    cout << "=====================================================" << endl;
    cout << "||   Seleccione el algoritmo de busqueda deseada   ||" << endl;
    cout << "||                     0) sequential search        ||" << endl;
    cout << "||                     1) binary seach             ||" << endl;
    cout << "=====================================================" << endl;
    cin >> searchChoice;

    
    if (searchChoice == 0) {

        index = sequentialSearch(arr, ARRAY_SIZE, target);
    }
    else if (searchChoice == 1) {

        index = binarySearch(arr, 0, ARRAY_SIZE - 1, target);
    }
    else {
        cout << "Opcion de busqueda no valida." << endl;
        return 0;
    }


    if (index == -1) {
        cout << "El numero no se encuentra en el arreglo." << endl;
    }
    else {
        cout << "El numero se encuentra en la posicion " << index << " del arreglo." << endl;
    }

    return 0;
}
