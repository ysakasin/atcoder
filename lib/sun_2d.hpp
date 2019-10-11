#include <iostream>

constexpr int LIM = 1000;

int a[LIM][LIM];
int s[LIM + 1][LIM + 1];

int sum_2d() {
  for (int i = 0; i < LIM; i++) {
    for (int j = 0; j < LIM; j++) {
      std::cin >> a[i][j];
    }
  }

  for (int i = 0; i < LIM; i++) {
    for (int j = 0; j < LIM; j++) {
      s[i + 1][j + 1] = s[i][j + 1] + s[i + 1][j] - s[i][j] + a[i][j];
    }
  }

  int x1, x2, y1, y2; // [x1, x2) x [y1, y2)
  std::cin >> x1 >> y1 >> x2 >> y2;
  return s[x2][y2] - s[x1][y2] - s[x2][y1] + s[x1][y1];
}
