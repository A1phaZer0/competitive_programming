#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> lhs, pair<int, int> rhs)
{
  int a, b;

  a = max(lhs.first + rhs.first + rhs.second, lhs.first + lhs.second);
  b = max(rhs.first + lhs.first + lhs.second, rhs.first + rhs.second);

  return a < b;
}

int main(int argc, char *argv[])
{
  int N;
  int i, a, b;
  vector<pair<int, int> >vii;
  int ans;
  int sum;
  int t = 1;

  while (scanf("%d", &N) && N) {
    vii.clear();
    for (i = 0; i < N; i++) {
      scanf("%d %d", &a, &b);
      vii.push_back(make_pair(a, b));
    }
    sort(vii.begin(), vii.end(), compare);
    ans = 0;
    sum = 0;
    for (i = 0; i < N; i++) {
      if (vii[i].first + vii[i].second + sum > ans) 
        ans = vii[i].first + vii[i].second + sum;
      sum += vii[i].first;
    }
    printf("Case %d: %d\n", t++, ans);
  }
  return 0;
}
