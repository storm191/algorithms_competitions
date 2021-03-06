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
#define print_vector_2d(a) for (int i = 0; i < a.size(); i++) {for (int j = 0; j < a[i].size(); j++) { if (i == a.size() - 1) {cout << a[i][j];} else { cout << a[i][j] << " ";}} cout << endl; }
using namespace std;

int main () {
  setvbuf(stdout, NULL, _IONBF, 0);
  int n;
  scanf("%d", &n);
  map<int, int> counts;
  for (int i = 0; i < n; ++i) {
    int a;
    scanf("%d", &a);
    if (a == 0) {
      continue;
    }
    if (counts.find(a) == counts.end()) {
      counts[a] = 1;
    } else {
      counts[a]++;
    }
  }
  int result = 0;
  for (map<int, int>::iterator it = counts.begin(); it != counts.end(); it++) {
    if (it->second > 2) {
      printf("-1");
      return 0;
    } else if (it->second == 2) {
      result++;
    }
  }
  printf("%d", result);
}
