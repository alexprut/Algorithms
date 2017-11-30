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
#include "../kruskal.cpp"
#include "../bellmanFord.cpp"
#include "../dijkstra.cpp"
#include "../trie.cpp"
#include "../maxSubArray.cpp"

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
  vector<int> numbers2 = {
      1, 2, 6, 7, 9, 10, 11, 12, 14, 15, 17, 19, 24, 25,
      30, 39, 40, 44, 46, 48, 51, 53, 54, 56, 59, 60, 69,
      70, 73, 75, 80, 87, 88, 89, 92, 93, 97, 99, 104, 107,
      109, 110, 111, 117, 123, 124, 125, 126, 127, 128, 135,
      136, 137, 141, 148, 153, 154, 161, 166, 167, 169, 175,
      177, 180, 181, 182, 185, 186, 189, 193, 198, 202
  };

  cout << "BinarySearch \n";

  cout << binarySearch(numbers, 3) << "\n";
  cout << binarySearch(numbers, 11) << "\n";
  cout << binarySearch(numbers2, 198) << "\n";
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

  cout << size(node2) << "\n";
}

void kruskalTest() {
  cout << "Kruskal \n";

  vector<vector<int>> matrix = {{
    {0, 2, 3, 0},
    {0, 0, 0, 4},
    {0, 0, 0, 1},
    {0, 0, 0, 0},
  }};

  vector<pair<int, int>> result = kruskal(matrix);
}

void bellmanFordTest() {
  cout << "Bellman-Ford \n";

  // TODO parametric linked list which contains the weight value (i.e. pair<int,int>)
  vector<LinkedList *> adjacency(5);
  for (int k = 0; k < adjacency.size(); k++) {
    adjacency[k] = new LinkedList();
  }
  adjacency[0]->insertFront(1);
  adjacency[0]->insertFront(2);
  adjacency[1]->insertFront(4);
  adjacency[1]->insertFront(3);
  adjacency[2]->insertFront(4);
  adjacency[3]->insertFront(2);
  adjacency[4]->insertFront(3);

  vector<vector<int>> matrix = {{
    {0, 1, 1, 0, 0},
    {0, 0, 0, 2, 1},
    {0, 0, 0, 0, 4},
    {0, 0, 1, 0, 0},
    {0, 0, 0, 1, 0},
  }};

  // Test without negative cycles
  pair<vector<int>, vector<int>> result = bellmanFord(adjacency, matrix, 0);

  // Test with negative cycles
  matrix = {{
    {0, 1, 1, 0, 0},
    {1, 0, 0, 2, 1},
    {0, -9, 0, 0, 4},
    {0, 0, 1, 0, 0},
    {0, 0, 0, 1, 0},
  }};
  adjacency[1]->insertFront(0);
  adjacency[2]->insertFront(1);
  result = bellmanFord(adjacency, matrix, 0);
}

void dijkstraTest() {
  cout << "Dijkstra \n";

  // TODO parametric linked list which contains the weight value (i.e. pair<int,int>)
  vector<LinkedList *> adjacency(5);
  for (int k = 0; k < adjacency.size(); k++) {
    adjacency[k] = new LinkedList();
  }
  adjacency[0]->insertFront(1);
  adjacency[0]->insertFront(2);
  adjacency[1]->insertFront(4);
  adjacency[1]->insertFront(3);
  adjacency[2]->insertFront(4);
  adjacency[3]->insertFront(2);
  adjacency[4]->insertFront(3);

  vector<vector<int>> matrix = {{
    {0, 1, 1, 0, 0},
    {0, 0, 0, 2, 1},
    {0, 0, 0, 0, 4},
    {0, 0, 1, 0, 0},
    {0, 0, 0, 1, 0},
  }};

  pair<vector<int>, vector<int>> result = dijkstra(adjacency, matrix, 0);
}

void trieTest() {
  cout << "Trie \n";

  Trie *t = new Trie;
  t->add("h");
  t->add("hac");
  t->add("hack");
  t->add("er");
  cout << t->countPartialFind("ha") << "\n";
}

void maxSubArrayTest() {
  cout << "Maximum subarray \n";

  int arr[] = {1, -1, 2, 4, 5};
  cout << maxSubArray(arr, 5) << "\n";
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
  kruskalTest();
  bellmanFordTest();
  dijkstraTest();
  trieTest();
  maxSubArrayTest();
}