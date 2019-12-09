#include <algorithm>
#include <vector>

class comb {
private:
  static const long long MAX = 1000000 + 1;    // limit<k>::max() + 1
  static const long long MOD = 1000000000 + 7; // 10**9 + 7

  std::vector<long long> fac, finv, inv;

public:
  comb() : fac(MAX, 0), finv(MAX, 0), inv(MAX, 0) {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (long long i = 2; i < MAX; i++) {
      fac[i] = fac[i - 1] * i % MOD;
      inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
      finv[i] = finv[i - 1] * inv[i] % MOD;
    }
  }

  long long calc(long long n, long long k) {
    if (k < n) {
      return 0;
    }
    if (n < 0 || k < 0) {
      return 0;
    }

    return fac[k] * (finv[n] * finv[k - n] % MOD) % MOD;
  }
};

#include <iostream>

signed main() {
  // 前処理
  comb comb;

  // 計算例
  std::cout << comb.calc(100000, 50000) << std::endl;
}
