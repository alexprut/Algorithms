#include <vector>

using namespace std;

void insertionSort(vector<int> &numbers) {
  for (int i = 1, size = numbers.size(); i < size; i++) {
    int k = numbers[i];
    int j = i - 1;

    while (j >= 0 && (k <= numbers[j])) {
      numbers[j + 1] = numbers[j];
      j--;
    }

    numbers[j + 1] = k;
  }
}