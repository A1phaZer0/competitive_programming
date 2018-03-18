#include <cstdio>
#include <cstdlib>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> lhs, pair<int, int> rhs)
{
  int a, b;
  a = lhs.first + (rhs.first > lhs.second ? rhs.first : lhs.second) + rhs.second;
  b = rhs.first + (lhs.first > rhs.second ? lhs.first : rhs.second) + lhs.second;
  return a < b;
}

int main(int argc, char *argv[])
{
  int a, b, i, j;
  int N;
  vector<pair<int, int> > vii;
  vector<int> vi;
  int times;
  int timeg;
  int ans;

  while (scanf("%d", &N) != EOF) {
    times = timeg = 0;
    vi.clear();
    vii.clear();
    for (i = 0; i < N; i++) {
      scanf("%d", &a);
      vi.push_back(a);
    }
    for (i = 0; i < N; i++) {
      scanf("%d", &b);
      vii.push_back(make_pair(vi[i], b));
    }
    sort(vii.begin(), vii.end(), compare);
    times = 0;
    timeg = 0;
    ans = 0;
    j = 0;
    for (i = 0; i < N; i++) {
      times += vii[i].first;
      if (timeg >= times) {
        timeg += vii[i].second;
      } else {
        timeg = times + vii[i].second;
      }
    }
    printf("%d\n", timeg);
  }
  return 0;
}
