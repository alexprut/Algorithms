void DFS(Graph &graph, int root) {
    vector <vector<int>> matrix = graph.getMatrix();
    Stack stack;
    unordered_map<int, bool> visited;
    stack.push(root);

    while (!stack.isEmpty()) {
        int currentNode = stack.pop();
        unordered_map<int, bool>::const_iterator match = visited.find(currentNode);
        if (match == visited.end()) {
            visited.insert(make_pair(currentNode, true));
            cout << currentNode << " ";

            for (int i = matrix.size() - 1; i >= 0; i--) {
                if (matrix[currentNode][i] > 0) {
                    match = visited.find(i);
                    if (match == visited.end()) {
                        stack.push(i);
                    }
                }
            }
        }
    }

    cout << "\n";
}