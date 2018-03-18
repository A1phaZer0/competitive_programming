#include <cstdio>
#include <cstdlib>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> &lhs, pair<int, int> &rhs)
{
  if (lhs.first == rhs.first)
    return rhs.second < lhs.second;
  return lhs.first < rhs.first;
}

int main(int argc, char *argv[])
{
  int tc;
  int M;
  int L, R;
  int i;
  int start;
  int flag;
  int max, max_i;
  int a = 0;
  vector<pair<int, int> > vii;
  vector<int> ans;

  scanf("%d\n", &tc);
  while (tc--) {
    if (a++)
      printf("\n");
    vii.clear();
    ans.clear();
    flag = 0;
    start = 0;
    max = 0;
    scanf("%d", &M);
    while (scanf("%d %d", &L, &R) && (L || R)) 
      vii.push_back(make_pair(L, R));
    vii.push_back(make_pair(1000000, 1000001));
    sort(vii.begin(), vii.end(), compare);

    i = 0;

    while (i < (int)vii.size()) {
      if (vii[i].first <= start) {
        if (vii[i].second > max) {
          max = vii[i].second;
          max_i = i;
          flag = 1;
        }
      } else {
        if (flag) {
          ans.push_back(max_i);
          start = max;
          flag = 0;
          i--;
        }
      }
      i++;
      if (start >= M)
        break;
    }
    if (start >= M)
      flag = 1;
    else
      flag = 0;

    if (!flag)
      printf("0\n");
    else {
      printf("%d\n", (int)ans.size());
      for (i = 0; i < (int)ans.size(); i++)
        printf("%d %d\n", vii[ans[i]].first, vii[ans[i]].second);
    }
  }
  return 0;
}
