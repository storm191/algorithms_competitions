#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <iterator>
#define print_vector(a) for (int i = 0; i < a.size(); i++) { if (i == a.size() - 1) {cout << a[i];} else { cout << a[i] << " ";}}
#define print_vector_2d(a) for (int i = 0; i < a.size(); i++) {for (int j = 0; j < a[i].size(); j++) { if (j == a[0].size() - 1) {cout << a[i][j];} else { cout << a[i][j] << " ";}} cout << endl; }
using namespace std;

bool is_lucky(int x, int k) {
  stringstream ss;
  ss << x;
  string s = ss.str();
  int count = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '4' || s[i] == '7') {
      count++;
    }
  }
  return count <= k;
}

int main () {
  setvbuf(stdout, NULL, _IONBF, 0);
  int n, k;
  scanf("%d %d", &n, &k);
  int count = 0;
  for (int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    if (is_lucky(a, k)) {
      count++;
    }
  }
  printf("%d", count);
}
