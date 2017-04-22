struct Node {
    int data;
    Node *left = NULL;
    Node *right = NULL;
};

class BST {
public:
    Node *root = NULL;

    void insert(int value);

    void print();

    Node *search(int value);

private:
    Node *createNode(int value);

    void insert(Node *&current, Node *node);

    void printInOrder(Node *current);

    Node* search(Node *current, int value);
};


Node *BST::createNode(int value) {
    Node *node = new Node;
    node->data = value;
    return node;
}

void BST::insert(int value) {
    Node *node = BST::createNode(value);
    insert(root, node);
}

void BST::insert(Node *&current, Node *node) {
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

void BST::printInOrder(Node *current) {
    if (current->left != NULL) { BST::printInOrder(current->left); }
    cout << current->data << " ";
    if (current->right != NULL) { BST::printInOrder(current->right); }
}

void BST::print() {
    BST::printInOrder(root);
    cout << "\n";
}

Node* BST::search(Node *current, int value) {
    if (current == NULL) {return NULL;}
    if (current->data == value) {return current;}
    if (current->data > value) {
        return BST::search(current->left, value);
    } else {
        return BST::search(current->right, value);
    }
}

Node* BST::search(int value) {
    return BST::search(root, value);
}