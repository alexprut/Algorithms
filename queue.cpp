class Queue: public DoubleLinkedList {
 public:
  Queue() { }

  void enqueue(int value);

  int dequeue();

  DoubleLinkedListNode *tail = NULL;
};

void Queue::enqueue(int value) {
  DoubleLinkedListNode *node = new DoubleLinkedListNode(value, head, NULL);
  if (head == NULL) {
    tail = node;
  } else {
    head->prev = node;
  }
  head = node;
}

int Queue::dequeue() {
  if (tail != NULL) {
    DoubleLinkedListNode *tmp = tail;
    int value = tmp->data;
    if (tail->prev != NULL) {
      tail->prev->next = NULL;
      tail = tail->prev;
    } else {
      tail = NULL;
      head = NULL;
    }
    delete tmp;
    return value;
  }
  return -1;
}