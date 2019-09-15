int fib(int n) {
  if (n == 0) {
    return 0;
  }

  int a = 1, b = 0;

  for (int i = 2; i <= n; i++) {
    int x = a + b;
    b = a;
    a = x;
  }
  return a;
}
