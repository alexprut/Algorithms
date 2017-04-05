#include <vector>
#include <cmath>

using namespace std;

vector<int> merge(vector<int> left, vector<int> right) {
    vector<int> numbers;
    int i = 0, j = 0;

    while (i < left.size() || j < right.size()) {
        if (i == left.size()) {
            numbers.push_back(right[j]);
            j++;
        } else if (j == right.size()) {
            numbers.push_back(left[i]);
            i++;
        } else {
            if (left[i] <= right[j]) {
                numbers.push_back(left[i]);
                i++;
            } else {
                numbers.push_back(right[j]);
                j++;
            }
        }
    }

    return numbers;
}

vector<int> mergeSort(vector<int> numbers) {
    if (numbers.size() > 1) {
        vector<int> left, right;

        for (int i = 0; i < floor(numbers.size() / 2); i++) {
            left.push_back(numbers[i]);
        }

        for (int i = floor(numbers.size() / 2); i < numbers.size(); i++) {
            right.push_back(numbers[i]);
        }

        left = mergeSort(left);
        right = mergeSort(right);

        numbers = merge(left, right);
    }

    return numbers;
}