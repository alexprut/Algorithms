// TODO simplify cost (both space & time), write cleaner code
vector <pair<int, int>> kruskal(vector <vector<int>> &matrix) {
    vector <pair<int, int>> result;
    vector < pair < int, pair < int, int >> > edges;
    vector < DisjointSetNode * > sets;

    // Make sets
    for (int i = 0; i < matrix.size(); i++) {
        sets.push_back(makeSet(i));
    }

    // Create the edges vector
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); ++j) {
            if (matrix[i][j] > 0) {
                edges.push_back(make_pair(matrix[i][j], make_pair(i, j)));
            }
        }
    }

    // Sort Edges
    sort(edges.begin(), edges.end(), [](const pair<int, pair<int, int>> &left, const pair<int, pair<int, int>> &right) {
        return left.first < right.first;
    });

    for (int i = 0; i < edges.size(); i++) {
        pair<int, int> tmpEdge = edges[i].second;

        DisjointSetNode *first = sets[tmpEdge.first];
        DisjointSetNode *second = sets[tmpEdge.second];

        DisjointSetNode *parentFist = findSet(first);
        DisjointSetNode *parentSecond = findSet(second);

        if (parentFist != parentSecond) {
            unionSets(first, second);
            result.push_back(tmpEdge);
        }
    }

    return result;
}