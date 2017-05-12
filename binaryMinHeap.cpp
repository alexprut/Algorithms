class BinaryMinHeap : public BinaryHeap {
public:
    BinaryMinHeap() { }

    BinaryMinHeap(vector<int> values) {
        buildHeap(values);
    }

    int findMin();

    void deleteMin();

    void insertHeapify(int index);

    void heapify(int index);

private:
};

int BinaryMinHeap::findMin() {
    return (size() != 0) ? data[0] : -1;
}

void BinaryMinHeap::insertHeapify(int index) {
    if (hasParent(index) && data[parent(index)] > data[index]) {
        int tmp = data[index];
        data[index] = data[parent(index)];
        data[parent(index)] = tmp;
        insertHeapify(parent(index));
    }
}

void BinaryMinHeap::heapify(int index) {
    int min = index;

    if (hasLeft(index) && data[index] > data[left(index)]) {
        min = left(index);
    }

    if (hasRight(index) && data[min] > data[right(index)]) {
        min = right(index);
    }

    if (min != index) {
        int tmp = data[index];
        data[index] = data[min];
        data[min] = tmp;
        heapify(min);
    }
}

void BinaryMinHeap::deleteMin() {
    if (!isEmpty()) {
        data[0] = data[size() - 1];
        data.pop_back();
        heapify(0);
    }
}