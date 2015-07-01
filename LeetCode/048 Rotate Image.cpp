#include <vector>

using std::vector;

class Solution {
 public:
  void nextRC(int& r, int& c, int layer, int layerBorder, int layerLength) {
    if (r == layer) {
      r = c;
      c = layerBorder;
    } else if (r == layerBorder) {
      r = c;
      c = layer;
    } else if (c == layer) {
      c = layer + layerBorder - r;
      r = layer;
    } else if (c == layerBorder) {
      c = layer + layerBorder - r;
      r = layerBorder;
    }
  }

  void rotate(vector<vector<int> >& matrix) {
    int n = matrix.size();
    int maxLayer = (n / 2) + (n & 1);
    for (int layer = 0; layer < maxLayer; ++layer) {
      int layerBorder = n - layer - 1;
      int layerLength = n - 2 * layer;
      if (layerLength == 1) {
        return;
      }
      for (int r = layer, c = layer; c < layerBorder; ++c) {
        int newValue = matrix[r][c];
        int realR = r, realC = c;
        for (int d = 0; d < 4; ++d) {
          nextRC(realR, realC, layer, layerBorder, layerLength);
          int temp = matrix[realR][realC];
          matrix[realR][realC] = newValue;
          newValue = temp;
        }
      }
    }
  }
};

int main() {
  return 0;
}
