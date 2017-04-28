#include <iostream>
#include <vector>
#include "../node.h"
#include "../countingSort.cpp"
#include "../mergeSort.cpp"
#include "../quickSort.cpp"
#include "../insertionSort.cpp"
#include "../binarySearch.cpp"
#include "../bubbleSort.cpp"
#include "../stack.cpp"
#include "../binarySearchTree.cpp"
#include "../binaryMaxHeap.cpp"
#include "../linkedList.cpp"
#include "../doubleLinkedList.cpp"

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
    vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8};

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

void stackTest() {
    Stack s;

    s.push(4);
    s.push(3);
    s.push(0);
    s.push(10);

    while (!s.isEmpty()) {
        cout << s.pop() << " ";
    }

    cout << "\n";
}

void binarySearchTreeTest() {
    cout << "Binary Search Tree \n";

    BST bst;
    bst.insert(4);
    bst.insert(5);
    bst.insert(1);
    bst.insert(0);
    bst.insert(9);
    bst.insert(9);
    bst.insert(10);
    bst.insert(18);
    bst.print();

    if (bst.search(10) != NULL) {
        cout << "Found Value\n";
    } else {
        cout << "Not Found Value\n";
    }

    if (bst.search(1234) != NULL) {
        cout << "Found Value\n";
    } else {
        cout << "Not Found Value\n";
    }

    cout << "\n";
}

void binaryMaxHeapTest() {
    cout << "Binary Max Heap \n";

    BinaryMaxHeap maxHeap({1, 4, 0, 123, 9, 2, 1, 12});

    cout << "\n";
}

void heapSortTest() {
    cout << "Heapsort \n";

    BinaryMaxHeap heap;
    vector<int> result = heap.heapSort({1, 4, 0, 123, 9, 2, 1, 12});

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }

    cout << "\n";
}

void linkedListTest() {
    cout << "Linked list \n";

    LinkedList list;
    list.insertFront(12);
    list.insertFront(1);
    list.insertFront(19);
    list.insertFront(121);
    list.deleteFront();

    LinkedListNode *current = list.head;
    while (current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }

    cout << "\n";
}

void doubleLinkedListTest() {
    cout << "Double Linked list \n";

    DoubleLinkedList list;
    list.insertFront(13);
    list.insertFront(0);
    list.insertFront(19);
    list.insertFront(121);
    list.deleteFront();

    DoubleLinkedListNode *current = list.head;
    while (current != NULL) {
        cout << current->data << " ";
        current = current->next;
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
    stackTest();
    binarySearchTreeTest();
    binaryMaxHeapTest();
    heapSortTest();
    linkedListTest();
    doubleLinkedListTest();
}