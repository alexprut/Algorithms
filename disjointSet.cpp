struct DisjointSetNode : Node {
    DisjointSetNode *parent;
    int rank = 0;
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
}

DisjointSetNode *unionSets(DisjointSetNode *firstNode, DisjointSetNode *secondNode) {
    DisjointSetNode *firstNodeParent = findSet(firstNode);
    DisjointSetNode *secondNodeParent = findSet(secondNode);

    if (firstNodeParent->rank > secondNodeParent->rank) {
        secondNodeParent->parent = firstNodeParent;
        return firstNodeParent;
    }

    firstNodeParent->parent = secondNodeParent;
    if (firstNodeParent->rank == secondNodeParent->rank) {
        secondNodeParent->rank += 1;
    }

    return secondNodeParent;
}