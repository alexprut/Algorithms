#include <iostream>
#include <vector>
#include "../countingSort.cpp"
#include "../mergeSort.cpp"
#include "../quickSort.cpp"
#include "../insertionSort.cpp"
#include "../binarySearch.cpp"
#include "../bubbleSort.cpp"

using namespace std;

void insertionSortEmptyTest() {
    vector<int> v = {};

    cout << "InsertionSort \n";

    insertionSort(v);

    for (int n : v) {
        cout << n << " ";
    }

    cout << "\n";
}

void insertionSortRandomNonOrderedTest() {
    vector<int> v = {2, 2, 0, 4, 3};

    cout << "InsertionSort \n";

    insertionSort(v);

    for (int n : v) {
        cout << n << " ";
    }

    cout << "\n";
}

void mergeSortTest() {
    vector<int> numbers = {4, 5, 0, 1, 6, 2};

    numbers = mergeSort(numbers);

    cout << "MergeSort \n";

    for (int n : numbers) {
        cout << n << " ";
    }

    cout << "\n";
}

void mergeTest() {
    vector<int> left = {0, 1, 6};
    vector<int> right = {0, 0, 1, 2, 3};

    vector<int> numbers = merge(left, right);

    cout << "Merge \n";

    for (int n : numbers) {
        cout << n << " ";
    }

    cout << "\n";
}

void quickSortTest() {
    vector<int> numbers = {4, 5, 0, 1, 6, 2, 10, 22, 44, 33};

    quickSort(numbers, 0, (int) (numbers.size() - 1));

    cout << "QuickSort \n";

    for (int n : numbers) {
        cout << n << " ";
    }

    cout << "\n";
}

void countingSortTest() {
    vector<int> numbers = {4, 5, 0, 1, 6, 2, 10, 22, 44, 33};

    countingSort(numbers, 33);

    cout << "CountingSort \n";

    for (int n : numbers) {
        cout << n << " ";
    }

    cout << "\n";
}

void binarySearchTest() {
    vector<int> numbers = {1,2,3,4,5,6,7,8};

    cout << "BinarySearch \n";

    cout << binarySearch(numbers, 3) << "\n";
    cout << binarySearch(numbers, 11) << "\n";
}

void bubbleSortTest() {
    vector<int> numbers = {4, 5, 0, 1, 6, 2, 10, 22, 44, 33, 0};

    bubbleSort(numbers);

    cout << "BubbleSort \n";

    for (int n : numbers) {
        cout << n << " ";
    }

    cout << "\n";
}

int main() {
    insertionSortEmptyTest();
    insertionSortRandomNonOrderedTest();
    mergeTest();
    mergeSortTest();
    quickSortTest();
    countingSortTest();
    binarySearchTest();
    bubbleSortTest();
}