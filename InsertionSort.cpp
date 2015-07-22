#include <iostream>
#include <vector>

using namespace std;

vector<int> insertionSort(vector<int> numbers) {
    for (int i = 1; i < numbers.size(); i++) {
        int k = numbers[i];
        int j = i - 1;

        while (j >= 0 && (k <= numbers[j])) {
            numbers[j + 1] = numbers[j];
            j--;
        }

        numbers[j + 1] = k;
    }

    return numbers;
}

void insertionSortEmptyTest() {
    vector<int> v = {};

    v = insertionSort(v);

    for (int n : v) {
        cout << n << "\n";
    }
}

void insertionSortRandomNonOrderedTest() {
    vector<int> v = {2, 2, 0, 4, 3};

    v = insertionSort(v);

    for (int n : v) {
        cout << n << "\n";
    }
}

int main() {
    insertionSortEmptyTest();
    insertionSortRandomNonOrderedTest();
}

