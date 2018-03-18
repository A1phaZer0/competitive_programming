#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
  int N;
  int i, j, inp;
  int k, g;
  vector<vector<int> > vvi;
  int sub, ans;

  while (scanf("%d", &N) != EOF) {
  vvi.clear();
  vvi.resize(N, vector<int> (N, 0));
  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      scanf("%d", &inp);
      vvi[i][j] += inp;
      if (i > 0)
        vvi[i][j] += vvi[i-1][j];
      if (j > 0)
        vvi[i][j] += vvi[i][j-1];
      if (i > 0 && j > 0)
        vvi[i][j] -= vvi[i-1][j-1];
    }
  }
  ans = -127*100*100;
  for (k = 0; k < N; k++) {
    for (g = 0; g < N; g++) {
      for (i = k; i < N; i++) {
        for (j = g; j < N; j++) {
          sub = vvi[i][j];
          if (k > 0)
            sub -= vvi[k-1][j];
          if (g > 0)
            sub -= vvi[i][g-1];
          if (k > 0 && g > 0)
            sub += vvi[k-1][g-1];
          ans = std::max(sub, ans);
        }
      }
    }
  }
  printf("%d\n", ans);
  }
  return 0;
}
