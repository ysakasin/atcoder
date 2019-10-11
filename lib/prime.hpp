#include <vector>

constexpr int PRIME_LIM = 55555;
std::vector<bool> isprime(PRIME_LIM + 1, true);

void calc_prime() {
  isprime[0] = false;
  isprime[1] = false;
  for (int i = 2; i < isprime.size(); i++) {
    if (!isprime[i]) {
      continue;
    }
    for (int x = i + i; x < isprime.size(); x += i) {
      isprime[x] = false;
    }
  }
}
