class BST {
public:
    BinaryNode *root = NULL;

    void insert(int value);

    void print();

    BinaryNode *search(int value);

private:
    BinaryNode *createNode(int value);

    void insert(BinaryNode *&current, BinaryNode *node);

    void printInOrder(BinaryNode *current);

    void printPreOrder(BinaryNode *current);

    void printPostOrder(BinaryNode *current);

    BinaryNode *search(BinaryNode *current, int value);
};


BinaryNode *BST::createNode(int value) {
    BinaryNode *node = new BinaryNode;
    node->data = value;
    return node;
}

void BST::insert(int value) {
    BinaryNode *node = BST::createNode(value);
    insert(root, node);
}

void BST::insert(BinaryNode *&current, BinaryNode *node) {
    if (current == NULL) {
        current = node;
        return;
    }
    if (current->data > node->data) {
        BST::insert(current->left, node);
    } else {
        BST::insert(current->right, node);
    }
}

void BST::printInOrder(BinaryNode *current) {
    if (current->left != NULL) { BST::printInOrder(current->left); }
    cout << current->data << " ";
    if (current->right != NULL) { BST::printInOrder(current->right); }
}

void BST::printPreOrder(BinaryNode *current) {
    if (current->left != NULL) { BST::printInOrder(current->left); }
    if (current->right != NULL) { BST::printInOrder(current->right); }
    cout << current->data << " ";
}

void BST::printPostOrder(BinaryNode *current) {
    cout << current->data << " ";
    if (current->left != NULL) { BST::printInOrder(current->left); }
    if (current->right != NULL) { BST::printInOrder(current->right); }
}

void BST::print() {
    BST::printInOrder(root);
    cout << "\n";
}

BinaryNode *BST::search(BinaryNode *current, int value) {
    if (current == NULL) { return NULL; }
    if (current->data == value) { return current; }
    if (current->data > value) {
        return BST::search(current->left, value);
    } else {
        return BST::search(current->right, value);
    }
}

BinaryNode *BST::search(int value) {
    return BST::search(root, value);
}