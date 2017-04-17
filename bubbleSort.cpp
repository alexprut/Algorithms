void bubbleSort(vector<int> &numbers) {
    bool isSwap = true;
    int length = numbers.size();

    while (isSwap) {
        isSwap = false;
        for (int i = 1; i < length; i++) {
            if (numbers[i - 1] > numbers[i]) {
                int tmp = numbers[i];
                numbers[i] = numbers[i-1];
                numbers[i-1] = tmp;
                isSwap = true;
            }
        }
        length--;
    }
}
