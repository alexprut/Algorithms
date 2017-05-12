class BinaryMaxHeap : public BinaryHeap {
public:
    BinaryMaxHeap() { }

    BinaryMaxHeap(vector<int> values) {
        buildHeap(values);
    }

    int findMax();

    void deleteMax();

    void insertHeapify(int index);

    void heapify(int index);

private:
};

int BinaryMaxHeap::findMax() {
    return (size() != 0) ? data[0] : -1;
}

void BinaryMaxHeap::insertHeapify(int index) {
    if (hasParent(index) && data[parent(index)] < data[index]) {
        int tmp = data[index];
        data[index] = data[parent(index)];
        data[parent(index)] = tmp;
        insertHeapify(parent(index));
    }
}

void BinaryMaxHeap::heapify(int index) {
    int max = index;

    if (hasLeft(index) && data[index] < data[left(index)]) {
        max = left(index);
    }

    if (hasRight(index) && data[max] < data[right(index)]) {
        max = right(index);
    }

    if (max != index) {
        int tmp = data[index];
        data[index] = data[max];
        data[max] = tmp;
        heapify(max);
    }
}

void BinaryMaxHeap::deleteMax() {
    if (!isEmpty()) {
        data[0] = data[size() - 1];
        data.pop_back();
        heapify(0);
    }
}