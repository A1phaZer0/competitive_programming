#include <cstdio>
#include <cstdlib>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

bool comparea(pair<int, int> lhs, pair<int, int> rhs)
{
  if (lhs.first == rhs.first)
    return lhs.second < rhs.second;
  return lhs.first < rhs.first;
}

bool compareb(pair<int, int> lhs, pair<int, int> rhs)
{
  if (lhs.second == rhs.second)
    return lhs.first < rhs.first;
  return lhs.second < rhs.second;
}

int main(int argc, char *argv[])
{
  int N;
  int a, b, i;
  int flag;
  vector<pair<int, int> > va;
  vector<pair<int, int> > vb;

  while (scanf("%d", &N) && N) {
    va.clear();
    vb.clear();
    flag = 0;
    for (i = 0; i < N; i++) {
      scanf("%d %d", &a, &b);
      va.push_back(make_pair(a, b));
      vb.push_back(make_pair(a, b));
    }
    sort(va.begin(), va.end(), comparea);
    sort(vb.begin(), vb.end(), compareb);
    for (i = 0; i < N; i++) {
      if (va[i].first != vb[i].second || va[i].second != vb[i].first) {
        flag = 1;
        break;
      }
    }
    if (flag)
      printf("NO\n");
    else
      printf("YES\n");
    
  }
  return 0;
}
