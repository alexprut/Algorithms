#include <vector>

using namespace std;

int partition(vector<int> &numbers, int beginIndex, int endIndex) {
    int pivot = numbers[endIndex];
    int i = beginIndex - 1;

    for (int j = beginIndex; j < endIndex; j++) {
        if (numbers[j] <= pivot) {
            i++;
            int tmp = numbers[i];
            numbers[i] = numbers[j];
            numbers[j] = tmp;
        }
    }

    numbers[endIndex] = numbers[i + 1];
    numbers[i + 1] = pivot;

    return ++i;
}

void quickSort(vector<int> &numbers, int beginIndex, int endIndex) {
    if (beginIndex < endIndex) {
        int pivotIndex = partition(numbers, beginIndex, endIndex);
        quickSort(numbers, beginIndex, pivotIndex - 1);
        quickSort(numbers, pivotIndex + 1, endIndex);
    }
}