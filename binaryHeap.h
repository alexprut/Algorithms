class BinaryHeap {
public:
    BinaryHeap() { }

    void insert(int value);

    void buildHeap(vector<int> values);

    int size();

    void heapSort();

    vector<int> heapSort(vector<int> values);

    bool isEmpty();

    vector<int> data;

    int offsetSize = 0;

    int parent(int index);

    int left(int index);

    int right(int index);

    bool hasLeft(int index);

    bool hasRight(int index);

    bool hasParent(int index);

    virtual void heapify(int index) = 0;

    virtual void insertHeapify(int index) = 0;

private:
};

bool BinaryHeap::isEmpty() {
    return (size() == 0);
}

int BinaryHeap::size() {
    return (data.size() - offsetSize);
}

bool BinaryHeap::hasParent(int index) {
    return (parent(index) > -1);
}

int BinaryHeap::parent(int index) {
    if (index == 1) { return 0; }
    return floor((index - 1) / 2);
}

int BinaryHeap::left(int index) {
    return (2 * index + 1);
}

int BinaryHeap::right(int index) {
    return (2 * index + 2);
}

bool BinaryHeap::hasLeft(int index) {
    return (left(index) < size());
}

bool BinaryHeap::hasRight(int index) {
    return (right(index) < size());
}


void BinaryHeap::insert(int value) {
    data.push_back(value);
    insertHeapify(size() - 1);
}

void BinaryHeap::buildHeap(vector<int> values) {
    data = values;

    for (int i = floor(size() / 2); i >= 0; i--) {
        heapify(i);
    }
}

void BinaryHeap::heapSort() {
    while (size() > 1) {
        int tmp = data[0];
        data[0] = data[size() - 1];
        data[size() - 1] = tmp;
        offsetSize++;
        heapify(0);
    }

    offsetSize = 0;
}

vector<int> BinaryHeap::heapSort(vector<int> values) {
    buildHeap(values);
    heapSort();
    return data;
}