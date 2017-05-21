void countingSort(vector<int> &numbers, int k) {
    vector<int> counting(k);
    vector<int> ordered(numbers.size());

    for (int i = 0; i <= k; i++) {
        counting[i] = 0;
    }

    for (int i = 0, size = numbers.size(); i < size; i++) {
        counting[numbers[i]] += 1;
    }

    for (int i = 1; i <= k; i++) {
        counting[i] += counting[i - 1];
    }

    for (int i = ((int) numbers.size() - 1); i >= 0; i--) {
        int value = numbers[i];
        ordered[counting[value]] = value;
        counting[value] -= 1;
    }

    numbers = ordered;
}