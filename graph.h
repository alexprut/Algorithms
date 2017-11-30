class Graph {
 public:
  Graph(vector<vector<int>> data) {
    _data = data;
  }

  vector<vector<int>> getMatrix() {
    return _data;
  }

  void printMatrix();

 private:
  vector<vector<int>> _data;
};

void Graph::printMatrix() {
  for (int i = 0; i < _data.size(); ++i) {
    for (int j = 0; j < _data.size(); ++j) {
      cout << _data[i][j] << " ";
    }
    cout << "\n";
  }
}