struct DoubleLinkedListNode : Node {
    DoubleLinkedListNode() {
        next = NULL;
        prev = NULL;
    }

    DoubleLinkedListNode(int value, DoubleLinkedListNode *nextNode, DoubleLinkedListNode *prevNode);

    DoubleLinkedListNode *next;
    DoubleLinkedListNode *prev;
};

DoubleLinkedListNode::DoubleLinkedListNode(int value, DoubleLinkedListNode *nextNode, DoubleLinkedListNode *prevNode) {
    next = nextNode;
    prev = prevNode;
    data = value;
}

class DoubleLinkedList {
public:
    DoubleLinkedListNode *head = NULL;

    DoubleLinkedList() { }

    void insertFront(int value);

    void deleteFront();

    bool isEmpty();
};

bool DoubleLinkedList::isEmpty() {
    return (head == NULL);
}

void DoubleLinkedList::insertFront(int value) {
    DoubleLinkedListNode *node = new DoubleLinkedListNode(value, head, NULL);
    head = node;
    if (head->next != NULL) { head->next->prev = head; }
}

void DoubleLinkedList::deleteFront() {
    DoubleLinkedListNode *tmp = head->next;
    if (tmp != NULL) { tmp->prev = NULL; }
    delete head;
    head = tmp;
}