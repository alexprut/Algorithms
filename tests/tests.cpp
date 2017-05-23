#include <iostream>
#include <vector>
#include <unordered_map>
#include "../node.h"
#include "../countingSort.cpp"
#include "../mergeSort.cpp"
#include "../quickSort.cpp"
#include "../insertionSort.cpp"
#include "../binarySearch.cpp"
#include "../bubbleSort.cpp"
#include "../stack.cpp"
#include "../binarySearchTree.cpp"
#include "../binaryHeap.h"
#include "../binaryMaxHeap.cpp"
#include "../binaryMinHeap.cpp"
#include "../linkedList.cpp"
#include "../doubleLinkedList.cpp"
#include "../queue.cpp"
#include "../graph.h"
#include "../breadthFirstSearch.cpp"
#include "../depthFirstSearch.cpp"
#include "../prim.cpp"
#include "../disjointSet.cpp"

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
    s.pop();
    s.push(3);
    s.push(0);
    s.push(10);

    cout << "Stack \n";

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

void binaryMinHeapTest() {
    cout << "Binary Min Heap \n";

    BinaryMinHeap minHeap({1, 4, 0, 123, 9, 2, 1, 12});

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

void queueTest() {
    cout << "Queue \n";

    Queue queue;
    queue.enqueue(13);
    queue.enqueue(12);
    queue.enqueue(1);
    queue.enqueue(25);

    while (!queue.isEmpty()) {
        cout << queue.dequeue() << " ";
    }

    cout << "\n";
}

void breadthFirstSearchTest() {
    cout << "Breadth-first Search (BFS) \n";

    Graph graph = {{
        {0, 1, 1, 0, 1},
        {0, 0, 0, 1, 1},
        {0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}
    }};

    graph.printMatrix();

    BFS(graph, 0);
    BFS(graph, 1);
    BFS(graph, 4);
}

void depthFirstSearchTest() {
    cout << "Depth-first Search (DFS) \n";

    Graph graph = {{
        {0, 1, 1, 0, 1},
        {0, 0, 0, 1, 1},
        {0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}
    }};

    DFS(graph, 0);
    DFS(graph, 1);
    DFS(graph, 4);
}

void primTest() {
    cout << "Prim (Minimum Spanning Tree) \n";

    vector<vector<int>> matrix = {{
        {0, 3, 1, 1},
        {3, 0, 1, 9},
        {1, 1, 0, 6},
        {1, 9, 6, 0},
    }};

    vector<int> parent = prim(matrix);

    for (int i = 0; i < parent.size(); i++) {
        cout << parent[i] << " ";
    }

    cout << "\n";
}

void disjointSetTest() {
    cout << "Disjoint Set \n";

    DisjointSetNode *node1 = makeSet(1);
    DisjointSetNode *node2 = makeSet(2);
    DisjointSetNode *node3 = makeSet(3);

    node1 = unionSets(node1, node2);
    node2 = unionSets(node1, node3);
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
    binaryMinHeapTest();
    heapSortTest();
    linkedListTest();
    doubleLinkedListTest();
    queueTest();
    breadthFirstSearchTest();
    depthFirstSearchTest();
    primTest();
    disjointSetTest();
}