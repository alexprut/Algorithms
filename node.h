struct Node {
    int data;
};

struct BinaryNode : Node {
    BinaryNode *left = NULL;
    BinaryNode *right = NULL;
};