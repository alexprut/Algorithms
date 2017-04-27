struct LinkedListNode : Node {
    LinkedListNode() {
        next = NULL;
    }

    LinkedListNode(int value, LinkedListNode *nextNode);

    LinkedListNode *next;
};

LinkedListNode::LinkedListNode(int value, LinkedListNode *nextNode) {
    next = nextNode;
    data = value;
}

class LinkedList {
public:
    LinkedListNode *head = NULL;

    LinkedList() { }

    void insertFront(int value);

    void deleteFront();

private:
};

void LinkedList::insertFront(int value) {
    LinkedListNode *node = new LinkedListNode(value, head);
    head = node;
}

void LinkedList::deleteFront() {
    LinkedListNode *tmp = head->next;
    delete head;
    head = tmp;
}