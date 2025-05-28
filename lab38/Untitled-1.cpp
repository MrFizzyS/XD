#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

template <typename T>
void numEqualToFirst(T* arr, int n) {
    T f = *(arr);
    int i, k = 0;
    for (i = 1; i < n; i++) {
        if (f == *(arr + i)) {
            k++;
        }
    }
    cout << "The number of equals to the first: " << k << endl;
}

template <typename T>
void exchange(T* arr, int i_1, int i_2) {
    T temp = *(arr + i_1);
    *(arr + i_1) = *(arr + i_2);
    *(arr + i_2) = temp;
}

template <typename T>
void insert(T* arr, T el, int& n, int pos) {
    int i, j;
    for (i = 0; i < n; i++) {
        if (i == pos) {
            for (j = n + 1; j > i; j--) {
                *(arr + j) = *(arr + j - 1);
            }
            *(arr + i) = el;
            n = n + 1;
        }
    }
}

template <typename T>
void maxSection(T* arr, int n) {
    int i, k = 1;
    T temp = *arr;
    vector <T> num;
    num.push_back(temp);
    vector <T> top;
    for (i = 1; i < n; i++) {
        if (*(arr + i) == temp) {
            num.push_back(*(arr + i));
        }
        else {
            temp = *(arr + i);
            if (num.size() > top.size()) {
                top.clear();
                top = num;
                num.clear();
            }
            else {
                num.clear();
            }
            num.push_back(temp);
        }
    }
    if (num.size() > top.size()) {
        top = num;
    }
    cout << "Max section: ";
    for (auto it : top) {
        cout << it << " ";
    }
    cout << endl;
}

template <typename T>
void sortArr(T* arr, int n) {
    T min_val = arr[0], max_val = arr[0];
    int min_i = 0, max_i = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] < min_val) {
            min_val = arr[i];
            min_i = i;
        }
        if (arr[i] > max_val) {
            max_val = arr[i];
            max_i = i;
        }
    }
    int start = min(min_i, max_i);
    int end = max(min_i, max_i);
    sort(arr + start + 1, arr + end);

}

template <typename T>
void print(T* arr, int n) {
    int i;
    cout << "arr[] = ";
    for (i = 0; i < n; i++) {
        cout << *(arr + i) << " ";
    }
    cout << endl;
}

void fillRandom(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 10;
    }
}

int main() {
    srand(time(NULL));
    int i_1, i_2, el, pos;
    char el_ch;
    int n = 10;
    int arr[n * 2];
    
    fillRandom(arr, n);
    
    print(arr, n);
    numEqualToFirst(arr, n);
    cout << "Enter indexes: ";
    cin >> i_1 >> i_2;
    exchange(arr, i_1, i_2);
    print(arr, n);
    cout << "Enter element and pos: ";
    cin >> el >> pos;
    insert(arr, el, n, pos);
    print(arr, n);
    maxSection(arr, n);
    sortArr(arr, n);
    cout << "Array after sorting between min and max: ";
    print(arr, n);
    return 0;
}