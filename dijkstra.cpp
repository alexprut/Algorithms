#include <vector>

using namespace std;

// TODO refactor, presence of future bugs and unexpected behaviour
int findMinKeyDijkstra(vector<int> &key, vector<bool> &visited) {
  int index;
  int tmpValue = INT_MAX;

  for (int i = 0; i < key.size(); i++) {
    if (key[i] < tmpValue && !visited[i]) {
      visited[i] = true;
      tmpValue = key[i];
      index = i;
    }
  }

  return index;
}

// TODO implement and use Fibonacci Heaps, inefficient and fake implementation below - cost is |V^2|
pair<vector<int>, vector<int>> dijkstra(vector<LinkedList *> &adjacency, vector<vector<int >> &matrix, int root) {
  vector<pair<int, int>> result;
  vector<bool> visited(matrix.size(), false);
  vector<int> parent(adjacency.size(), -1);
  vector<int> pathCost(adjacency.size(), INT_MAX);

  parent[root] = 0;
  pathCost[root] = 0;

  for (int i = 0; i < matrix.size(); i++) {
    int j = findMinKeyDijkstra(pathCost, visited);
    LinkedListNode *tmp = adjacency[j]->head;
    while (tmp != NULL) {
      relax(parent, pathCost, matrix, j, tmp->data);
      tmp = tmp->next;
    }
  }

  return make_pair(parent, pathCost);
}