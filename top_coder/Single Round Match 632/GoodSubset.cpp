#include <vector>
#include <list>
#include <fstream>
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
#include <ctime>
#include <iterator>

#if DEBUG
#include "prettyprint.hpp"
#define print_container(c) cout << c << endl;
#endif

#define MOD 1000000007

using namespace std;

class GoodSubset {
  public: int numberOfSubsets(int goodValue, vector<int> d);
};

int GoodSubset::numberOfSubsets(int goodValue, vector<int> d) {
  queue<pair<int, vector<int> > > q;
  vector<int> empty = {};
  q.push(make_pair(goodValue, empty));
  int one_count = count(d.begin(), d.end(), 1);
  int one_result = 1;
  for (int i = 0; i < one_count; ++i) {
    one_result = (one_result * 2) % MOD;
  }

  if (goodValue == 1) {
    return one_result - 1;
  }

  int result = 0;
  while (!q.empty()) {
    pair<int, vector<int>> p = q.front();
    q.pop();
    if (p.first == 1) {
      result = (result + one_result) % MOD;
    }
    for (int i = 0; i < d.size(); ++i) {
      if (find(p.second.begin(), p.second.end(), i) == p.second.end()) {
        if (p.second.size() > 0 && i < p.second[p.second.size() - 1]) {
          continue;
        }
        if (p.first % d[i] == 0 && d[i] != 1) {
          vector<int> tmp = p.second;
          tmp.push_back(i);
          q.push(make_pair(p.first / d[i], tmp));
        }
      }
    }
  }
  return result;
}

// CUT begin
ifstream data("GoodSubset.sample");

string next_line() {
    string s;
    getline(data, s);
    return s;
}

template <typename T> void from_stream(T &t) {
    stringstream ss(next_line());
    ss >> t;
}

void from_stream(string &s) {
    s = next_line();
}

template <typename T> void from_stream(vector<T> &ts) {
    int len;
    from_stream(len);
    ts.clear();
    for (int i = 0; i < len; ++i) {
        T t;
        from_stream(t);
        ts.push_back(t);
    }
}

template <typename T>
string to_string(T t) {
    stringstream s;
    s << t;
    return s.str();
}

string to_string(string t) {
    return "\"" + t + "\"";
}

bool do_test(int goodValue, vector<int> d, int __expected) {
    time_t startClock = clock();
    GoodSubset *instance = new GoodSubset();
    int __result = instance->numberOfSubsets(goodValue, d);
    double elapsed = (double)(clock() - startClock) / CLOCKS_PER_SEC;
    delete instance;

    if (__result == __expected) {
        cout << "PASSED!" << " (" << elapsed << " seconds)" << endl;
        return true;
    }
    else {
        cout << "FAILED!" << " (" << elapsed << " seconds)" << endl;
        cout << "           Expected: " << to_string(__expected) << endl;
        cout << "           Received: " << to_string(__result) << endl;
        return false;
    }
}

int run_test(bool mainProcess, const set<int> &case_set, const string command) {
    int cases = 0, passed = 0;
    while (true) {
        if (next_line().find("--") != 0)
            break;
        int goodValue;
        from_stream(goodValue);
        vector<int> d;
        from_stream(d);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(goodValue, d, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1409915675;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 1000 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(2);
    set<int> cases;
    bool mainProcess = true;
    for (int i = 1; i < argc; ++i) {
        if ( string(argv[i]) == "-") {
            mainProcess = false;
        } else {
            cases.insert(atoi(argv[i]));
        }
    }
    if (mainProcess) {
        cout << "GoodSubset (1000 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end