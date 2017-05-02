void BFS(Graph &graph, int root) {
    vector <vector<int>> matrix = graph.getMatrix();
    Queue queue;
    unordered_map<int, bool> visited;
    queue.enqueue(root);
    visited.insert(make_pair(root, true));

    while (!queue.isEmpty()) {
        int currentNode = queue.dequeue();
        cout << currentNode << " ";

        for (int i = 0; i < matrix.size(); i++) {
            if (matrix[currentNode][i] > 0) {
                unordered_map<int, bool>::const_iterator match = visited.find(i);
                if (match == visited.end()) {
                    queue.enqueue(i);
                    visited.insert(make_pair(i, true));
                }
            }
        }
    }

    cout << "\n";
}