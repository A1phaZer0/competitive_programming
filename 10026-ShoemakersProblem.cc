#include <cstdio>
#include <cstdlib>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

bool compare(pair<int, pair<int, int> > lhs, pair<int, pair<int, int> > rhs) 
{
  return lhs.second.second * rhs.second.first > rhs.second.second * lhs.second.first;
}

int main(int argc, char *argv[])
{
  int tc;
  int N;
  int T, F;
  int i;
  int flag;
  int flag2;
  vector<pair<int, pair<int, int> > > viii;

  scanf("%d\n", &tc);
  flag2 = 0;
  while (tc--) {
    if (flag2++)
      printf("\n");
    viii.clear();
    scanf("%d\n", &N);
    for (i = 0; i < N; i++) {
      scanf("%d %d", &T, &F);
      viii.push_back(make_pair(i+1, make_pair(T, F)));
    }
    stable_sort(viii.begin(), viii.end(), compare);
    flag = 0;
    for (i = 0; i < N; i++) {
      if (flag++)
        printf(" ");
      printf("%d", viii[i].first);
    }
    printf("\n");

  }
  return 0;
}
