int binarySearch(vector<int> &numbers, int n) {
    int start = 0;
    int end = numbers.size() - 1;

    while (start <= end) {
        int middle = (start + end) / 2;

        if (n == numbers[middle]) {
            return middle;
        } else if (n > numbers[middle]) {
            start = middle + 1;
        } else {
            end = middle - 1;
        }
    }

    return -1;
}