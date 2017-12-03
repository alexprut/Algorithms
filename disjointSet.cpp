class DisjointSets {
 public:
  DisjointSets(int n) {
    for (int i = 0; i < n; i++) {
      makeSet(i);
    }
  }

  int findSet(int node) {
    if (parent[node] == node) { return node; }
    parent[node] = findSet(parent[node]);
    return parent[node];
  }

  int unionSets(int firstNode, int secondNode) {
    int firstNodeParent = findSet(firstNode);
    int secondNodeParent = findSet(secondNode);

    if (firstNodeParent == secondNodeParent) {
      return firstNodeParent;
    }

    if (rank[firstNodeParent] > rank[secondNodeParent]) {
      parent[secondNodeParent] = firstNodeParent;
      size[firstNodeParent] += size[secondNodeParent];
      return firstNodeParent;
    }

    parent[firstNodeParent] = secondNodeParent;
    size[secondNodeParent] += size[firstNodeParent];
    if (rank[firstNodeParent] == rank[secondNodeParent]) {
      rank[secondNodeParent] += 1;
    }

    return secondNodeParent;
  }

  int getSize(int node) {
    return size[findSet(node)];
  }

 private:
  unordered_map<int, int> parent;
  unordered_map<int, int> size;
  unordered_map<int, int> rank;

  void makeSet(int elem) {
    parent[elem] = elem;
    size[elem] = 1;
    rank[elem] = 0;
  }
};


struct DisjointSetNode: Node {
  DisjointSetNode *parent;
  int rank = 0;
  int size = 1;
};

DisjointSetNode *makeSet(int value) {
  DisjointSetNode *node = new DisjointSetNode;
  node->data = value;
  node->parent = node;

  return node;
}

DisjointSetNode *findSet(DisjointSetNode *node) {
  if (node->parent == node) { return node; }
  node->parent = findSet(node->parent);
  return node->parent;
}

DisjointSetNode *unionSets(DisjointSetNode *firstNode, DisjointSetNode *secondNode) {
  DisjointSetNode *firstNodeParent = findSet(firstNode);
  DisjointSetNode *secondNodeParent = findSet(secondNode);

  if (firstNodeParent == secondNodeParent) {
    return firstNodeParent;
  }

  if (firstNodeParent->rank > secondNodeParent->rank) {
    secondNodeParent->parent = firstNodeParent;
    firstNodeParent->size += secondNodeParent->size;
    return firstNodeParent;
  }

  firstNodeParent->parent = secondNodeParent;
  secondNodeParent->size += firstNodeParent->size;
  if (firstNodeParent->rank == secondNodeParent->rank) {
    secondNodeParent->rank += 1;
  }

  return secondNodeParent;
}

int size(DisjointSetNode *node) {
  DisjointSetNode *parent = findSet(node);
  return parent->size;
}