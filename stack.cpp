class Stack {
public:
    int pop() {
        if (topIndex != -1) {
            topIndex--;
            return data[topIndex+1];
        }

        return -1;
    }
    void push(int n) {
        data.push_back(n);
        topIndex++;
    }
    int top() {
        return data[topIndex];
    }
    bool isEmpty() {
        return (topIndex == -1);
    }
private:
    vector<int> data;
    int topIndex = -1;
};