#include <iostream>
#include <vector>
#include <cmath>

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

vector<int> merge(vector<int> left, vector<int> right) {
    vector<int> numbers;

    int i = 0, j = 0;

    while (i < left.size() || j < right.size()) {
        if (i == left.size()) {
            numbers.push_back(right[j]);
            j++;
        } else if (j == right.size()) {
            numbers.push_back(left[i]);
            i++;
        } else {
            if (left[i] <= right[j]) {
                numbers.push_back(left[i]);
                i++;
            } else {
                numbers.push_back(right[j]);
                j++;
            }
        }
    }

    return numbers;
}

vector<int> mergeSort(vector<int> numbers) {
    if (numbers.size() > 1) {
        vector<int> left, right;

        for (int i = 0; i < floor(numbers.size() / 2); i++) {
            left.push_back(numbers[i]);
        }

        for (int i = floor(numbers.size() / 2); i < numbers.size(); i++) {
            right.push_back(numbers[i]);
        }

        left = mergeSort(left);
        right = mergeSort(right);

        numbers = merge(left, right);
    }

    return numbers;
}

void mergeSortTest() {
    vector<int> numbers = {4, 5, 0, 1, 6, 2};

    numbers = mergeSort(numbers);

    cout << "MergeSort \n";

    for (int n : numbers) {
        cout << n << "\n";
    }
}

void mergeTest() {
    vector<int> left = {0, 1, 6};
    vector<int> right = {0, 0, 1, 2, 3};

    vector<int> numbers = merge(left, right);

    cout << "Merge \n";

    for (int n : numbers) {
        cout << n << "\n";
    }
}

int main() {
    insertionSortEmptyTest();
    insertionSortRandomNonOrderedTest();
    mergeTest();
    mergeSortTest();
}