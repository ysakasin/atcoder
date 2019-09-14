int gcd(int a, int b) {
  if (a < b) {
    int tmp = a;
    a = b;
    b = a;
  }

  while (b != 0) {
    int r = a % b;
    a = b;
    b = r;
  }
  return a;
}

int lcm(int a, int b) { return b / gcd(a, b) * a; }
