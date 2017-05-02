class Stack {
public:
    Stack() {}
    int pop() {
        if (topIndex != -1) {
            topIndex--;
            return _data[topIndex + 1];
        }

        return -1;
    }

    void push(int n) {
        topIndex++;
        if (topIndex > ((int)_data.size() - 1)) {
            _data.push_back(n);
        } else {
            _data[topIndex] = n;
        }
    }

    int top() {
        return _data[topIndex];
    }

    bool isEmpty() {
        return (topIndex == -1);
    }

private:
    vector<int> _data;
    int topIndex = -1;
};