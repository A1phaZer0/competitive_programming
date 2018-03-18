#include <cstdio>
#include <cstdlib>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> lhs, pair<int, int> rhs)
{
  return lhs.second > rhs.second;
}

int main(int argc, char *argv[])
{
  int M, T;
  int i, j, inp;
  int flag;
  vector<int> vm;
  vector<pair<int, int> > vt;
  vector<vector<int> > vvi;

  while (scanf("%d %d", &M, &T) && M) {
    vm.clear();
    vt.clear();
    vvi.clear();
    vvi.resize(M, vector<int> (0));
    for (i = 0; i < M; i++) {
      scanf("%d", &inp);
      vm.push_back(inp);
    }
    for (i = 0; i < T; i++) {
      scanf("%d", &inp);
      vt.push_back(make_pair(i + 1, inp));
    }
    sort(vt.begin(), vt.end(), compare);

    flag = 1;
    for (i = 0; i < M; i++) {
      for (j = 0; j < T; j++) 
        if (vm[i] && vt[j].second) {
          vm[i]--;
          vt[j].second--;
          vvi[i].push_back(vt[j].first);
        }
      if (vm[i]) {
        flag = 0;
        break;
      }
    }
    if (!flag)
      printf("0\n");
    else {
      printf("1\n");
      for (i = 0; i < M; i++) {
        printf("%d", vvi[i][0]);
        for (j = 1; j < (int)vvi[i].size(); j++)
          printf(" %d", vvi[i][j]);
        printf("\n");
      }
    }
  }
  return 0;
}
