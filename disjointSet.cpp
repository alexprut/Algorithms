struct DisjointSetNode : Node {
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

int size(DisjointSetNode* node) {
    DisjointSetNode* parent = findSet(node);
    return parent->size;
}