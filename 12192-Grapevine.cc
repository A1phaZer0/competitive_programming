#include <cstdio>
#include <cstdlib>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
  int N, M, Q;
  int L, U;
  int inp;
  int i, j;
  int x, y;
  int l, h, grid;
  int max;
  int flag;
  vector<int>::iterator it;

  while (scanf("%d %d", &N, &M) && N) {
    vector<vector<int> > vvi(N, vector<int>(M, 0));
    for (i = 0; i < N; i++)
      for (j = 0; j < M; j++) {
        scanf("%d", &inp);
        vvi[i][j] = inp;
      }

    scanf("%d", &Q);
    for (i = 0; i < Q; i++) {
      vector<pair<int, int> > vii;
      scanf("%d %d", &L, &U);
      for (j = 0; j < N; j++) {
        it = lower_bound(vvi[j].begin(), vvi[j].end(), L);
        x = it - vvi[j].begin();
        it = upper_bound(vvi[j].begin(), vvi[j].end(), U);
        y = it - 1 - vvi[j].begin();
        vii.push_back(make_pair(x, y));
      }
      max = 0;
      for (i = 0; i < N; i++) {
        l = vii[i].second - vii[i].first + 1;
        h = N - i;
        grid = l > h ? h : l;
        flag = 0;
        while (grid > 1) {
          for (j = i + 1; j < grid; j++) {
            


    }

  }
  return 0;
}
