int maxSubArray(int arr[], int n) {
  int maxSoFar = INT_MIN;
  int maxEnding = INT_MIN;
  for (int i = 0; i < n; i++) {
    maxEnding = max(maxEnding + arr[i], arr[i]);
    maxSoFar = max(maxSoFar, maxEnding);
  }

  return maxSoFar;
}