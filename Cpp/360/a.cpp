#include <iostream>
#include <string>
#include <stack>
using namespace std;

long long value(const string& s) {
  int n = s.size();
  stack<long long> sn;
  stack<char> sc;
  long long curr = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '+') {
      sn.push(curr);
      while (!sc.empty()) {
        long long num2 = sn.top();
        sn.pop();
        long long num1 = sn.top();
        sn.pop();
        char op = sc.top();
        sc.pop();
        if (op == '+') {
          sn.push(num1 + num2);
        } else {
          sn.push(num1 * num2);
        }
      }
      sc.push('+');
      curr = 0;
    } else if (s[i] == '*') {
      sn.push(curr);
      while (!sc.empty() && sc.top() == '*') {
        long long num2 = sn.top();
        sn.pop();
        long long num1 = sn.top();
        sn.pop();
        char op = sc.top();
        sc.pop();
        if (op == '+') {
          sn.push(num1 + num2);
        } else {
          sn.push(num1 * num2);
        }
      }
      sc.push('*');
      curr = 0;
    } else {
      curr = curr * 10 + s[i] - '0';
    }
  }
  sn.push(curr);
  while (!sc.empty()) {
    long long num2 = sn.top();
    sn.pop();
    long long num1 = sn.top();
    sn.pop();
    char op = sc.top();
    sc.pop();
    if (op == '+') {
        sn.push(num1 + num2);
    } else {
        sn.push(num1 * num2);
    }
  }
  return sn.top();
}

bool check(const string& expr) {
  int n = expr.size();
  int k = 0;
  while (k < n && expr[k] != '=') {
    ++k;
  }
  string expr1 = expr.substr(0, k), expr2 = expr.substr(k + 1, n - k - 1);
  if (value(expr1) == value(expr2)) {
    return true;
  }
  for (int i = 0; i <= n; ++i) {
    for (char c = '0'; c <= '9'; ++c) {
      string tmp = expr;
      tmp.insert(tmp.begin() + i, c);
      string expr1, expr2;
      if (i <= k) {
        expr1 = tmp.substr(0, k + 1);
        expr2 = tmp.substr(k + 2, n - k - 1);
      } else {
        expr1 = tmp.substr(0, k);
        expr2 = tmp.substr(k + 1, n - k);
      }
      if (value(expr1) == value(expr2)) {
        return true;
      }
    }
  }
  return false;
}

void solve() {
  string expr;
  cin >> expr;
  if (check(expr)) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}