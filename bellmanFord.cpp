#include <vector>

using namespace std;

void relax(vector<int> &parent, vector<int> &pathCost, vector<vector<int>> &matrix, int a, int b) {
    if (pathCost[b] > (pathCost[a] + matrix[a][b])) {
        pathCost[b] = pathCost[a] + matrix[a][b];
        parent[b] = a;
    }
}

pair<vector<int>, vector<int>> bellmanFord(vector<LinkedList *> &adjacency, vector<vector<int>> &matrix, int root) {
    vector<pair<int, int>> result;
    vector<int> parent(adjacency.size(), -1);
    vector<int> pathCost(adjacency.size(), INT_MAX);

    parent[root] = 0;
    pathCost[root] = 0;

    for (int i = 0; i < adjacency.size(); i++) {
        for (int j = 0; j < adjacency.size(); j++) {
            LinkedListNode *tmp = adjacency[j]->head;
            while (tmp != NULL) {
                relax(parent, pathCost, matrix, j, tmp->data);
                tmp = tmp->next;
            }
        }
    }

    // Control if there is a negative cycle
    for (int i = 0; i < adjacency.size(); i++) {
        LinkedListNode *tmp = adjacency[i]->head;
        while (tmp != NULL) {
            if (pathCost[tmp->data] > (pathCost[i] + matrix[i][tmp->data])) {
                vector<int> a;
                a.push_back(-1);
                return make_pair(a, a);
            }
            tmp = tmp->next;
        }
    }

    return make_pair(parent, pathCost);
};