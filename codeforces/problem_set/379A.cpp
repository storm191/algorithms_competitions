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
using namespace std;

int main () {
  int a, b;
  scanf("%d %d", &a, &b);
  int result = 0;
  if (b > a){
    result = a;
  } else {
    while (a >= b) {
      a = a - b;
      result += b;
      a++;
    }
    result += a;
  }
  printf("%d", result);
  fflush(stdout);
}
