class BinaryMaxHeap {
public:
    BinaryMaxHeap() { }

    BinaryMaxHeap(vector<int> values) {
        buildHeap(values);
    }

    int findMax();

    void insert(int value);

    void deleteMax();

    void buildHeap(vector<int> values);

    int size();

    void heapSort();

    vector<int> heapSort(vector<int> values);

    bool isEmpty();

private:
    vector<int> data;

    int offsetSize = 0;

    int parent(int index);

    int left(int index);

    int right(int index);

    bool hasLeft(int index);

    bool hasRight(int index);

    bool hasParent(int index);

    void heapify(int index);

    void insertHeapify(int index);
};

bool BinaryMaxHeap::isEmpty() {
    return (size() == 0);
}

int BinaryMaxHeap::size() {
    return (data.size() - offsetSize);
}

bool BinaryMaxHeap::hasParent(int index) {
    return (parent(index) > -1);
}

int BinaryMaxHeap::parent(int index) {
    if (index == 1) { return 0; }
    return floor((index - 1) / 2);
}

int BinaryMaxHeap::left(int index) {
    return (2 * index + 1);
}

int BinaryMaxHeap::right(int index) {
    return (2 * index + 2);
}

bool BinaryMaxHeap::hasLeft(int index) {
    return (left(index) < size());
}

bool BinaryMaxHeap::hasRight(int index) {
    return (right(index) < size());
}

int BinaryMaxHeap::findMax() {
    return (size() != 0) ? data[0] : -1;
}

void BinaryMaxHeap::insert(int value) {
    data.push_back(value);
    insertHeapify(size() - 1);
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

    if (hasRight(index) && data[left(index)] < data[right(index)]) {
        max = right(index);
    }

    if (max != index) {
        int tmp = data[index];
        data[index] = data[max];
        data[max] = tmp;
        heapify(max);
    }
}

void BinaryMaxHeap::buildHeap(vector<int> values) {
    data = values;

    for (int i = floor(size() / 2); i >= 0; i--) {
        heapify(i);
    }
}

void BinaryMaxHeap::deleteMax() {
    if (!isEmpty()) {
        data[0] = data[size() - 1];
        data.pop_back();
        heapify(0);
    }
}

void BinaryMaxHeap::heapSort() {
    while (size() > 1) {
        int tmp = data[0];
        data[0] = data[size() - 1];
        data[size() - 1] = tmp;
        offsetSize++;
        heapify(0);
    }

    offsetSize = 0;
}

vector<int> BinaryMaxHeap::heapSort(vector<int> values) {
    buildHeap(values);
    heapSort();
    return data;
}