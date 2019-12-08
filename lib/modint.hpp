#include <iostream>

// https://qiita.com/drken/items/3b4fdf0a78e7a138cd9a

class modint {
private:
  static constexpr long long int MOD = 1000000000 + 7; // (10 ** 9) + 7
  long long int x;

  static long long int sanitize(long long int n) {
    while (n < 0) {
      n += modint::MOD;
    }
    return n % modint::MOD;
  }

public:
  modint(long long int x) : x(sanitize(x)) {}
  modint() : x(0) {}

  modint &operator=(const modint &other) {
    this->x = other.x;
    return *this;
  }

  modint operator+(const modint &other) const {
    modint ret;
    ret.x = (this->x + other.x) % modint::MOD;
    return ret;
  }

  modint operator-(const modint &other) const {
    modint ret;
    ret.x = (this->x - other.x);
    if (x < 0) {
      ret.x += modint::MOD;
    }
    return ret;
  }

  modint operator*(const modint &other) const {
    modint ret;
    ret.x = (this->x * other.x) % modint::MOD;
    return ret;
  }

  modint &operator+=(const modint &other) {
    this->x = (this->x + other.x) % modint::MOD;
    return *this;
  }

  modint operator<<(const long long int shift) const {
    modint base = modint(2).pow(shift);
    return *this * base;
  }

  modint pow(long long int n) const {
    modint ret;
    ret.x = _pow(n);
    return ret;
  }

  friend std::ostream &operator<<(std::ostream &stream, const modint &value);

private:
  long long int _pow(long long int n) const {
    long long int a = this->x;
    long long res = 1;
    while (n > 0) {
      if (n & 1) {
        res = res * a % modint::MOD;
      }
      a = a * a % modint::MOD;
      n >>= 1;
    }
    return res;
  }
};

std::ostream &operator<<(std::ostream &stream, const modint &value) {
  return stream << value.x;
}
