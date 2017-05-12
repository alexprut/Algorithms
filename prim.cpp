int findMinKey(vector<int> &key) {
    int minIndex = 0;

    for (int i = 1; i < key.size(); i++) {
        if (key[i] < key[minIndex]) {
            minIndex = i;
        }
    }

    return minIndex;
}

// hypothesis: connected graph, unidirectional graph, non-negative costs
vector<int> prim(vector <vector<int>> adjacencyMatrix) {
    vector<bool> visited(adjacencyMatrix.size(), false);
    vector<int> parent(adjacencyMatrix.size(), -1);
    vector<int> key(adjacencyMatrix.size(), INT_MAX);

    key[0] = 0;
    parent[0] = 0;
    int min = findMinKey(key);
    while (!visited[min] && key[min] != INT_MAX) {
        visited[min] = true;
        key[min] = INT_MAX;
        for (int i = 0; i < adjacencyMatrix.size(); i++) {
            if (adjacencyMatrix[min][i] > 0 && !visited[i] && adjacencyMatrix[min][i] < key[i]) {
                key[i] = adjacencyMatrix[min][i];
                parent[i] = min;
            }
        }

        min = findMinKey(key);
    }

    return parent;
};