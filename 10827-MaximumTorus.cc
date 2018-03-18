#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
  int tc;
  int N;
  int i, j, k, g, x0, y0, x1, y1;
  int mat[75][75];
  int sum, ans;

  scanf("%d", &tc);
  while (tc--) {
    scanf("%d", &N);
    for (i = 0; i < N; i++) {
      for (j = 0; j < N; j++) {
        scanf("%d", mat[i]+j);
        if (i)
          mat[i][j] += mat[i-1][j];
        if (j)
          mat[i][j] += mat[i][j-1];
        if (i && j)
          mat[i][j] -= mat[i-1][j-1];
      }
    }
    ans = -127*75*75;
    for (i = 0; i < N; i++) {
      for (j = 0; j < N; j++) {
        for (k = 0; k < N; k++) {
          for (g = 0; g < N; g++) {
            if (i <= k && j <= g) {
              sum = mat[k][g];
              if (j)
                sum -= mat[k][j-1];
              if (i)
                sum -= mat[i-1][g];
              if (i && j)
                sum += mat[i-1][j-1];
            } else if (i > k && j <= g) {
              x0 = i; y0 = j; x1 = N - 1; y1 = g;

              sum = mat[x1][y1];
              if (y0) sum -= mat[x1][y0-1];
              if (x0) sum -= mat[x0-1][y1];
              if (x0 && y0) sum += mat[x0-1][y0-1];

              x0 = 0; y0 = j; x1 = k; y1 = g;
              sum += mat[x1][y1];
              if (y0) sum -= mat[x1][y0-1];
              if (x0) sum -= mat[x0-1][y1];
              if (x0 && y0) sum += mat[x0-1][y0-1];
            } else if (i <= k && j > g) {
              x0 = i; y0 = j; x1 = k; y1 = N - 1;

              sum = mat[x1][y1];
              if (y0) sum -= mat[x1][y0-1];
              if (x0) sum -= mat[x0-1][y1];
              if (x0 && y0) sum += mat[x0-1][y0-1];

              x0 = i; y0 = 0; x1 = k; y1 = g;
              sum += mat[x1][y1];
              if (y0) sum -= mat[x1][y0-1];
              if (x0) sum -= mat[x0-1][y1];
              if (x0 && y0) sum += mat[x0-1][y0-1];

            } else {
              x0 = 0; y0 = 0; x1 = k; y1 = g;

              sum = mat[x1][y1];
              if (y0) sum -= mat[x1][y0-1];
              if (x0) sum -= mat[x0-1][y1];
              if (x0 && y0) sum += mat[x0-1][y0-1];

              x0 = 0; y0 = j; x1 = k; y1 = N - 1;
              sum += mat[x1][y1];
              if (y0) sum -= mat[x1][y0-1];
              if (x0) sum -= mat[x0-1][y1];
              if (x0 && y0) sum += mat[x0-1][y0-1];
              
              x0 = i; y0 = 0; x1 = N - 1; y1 = g;
              sum += mat[x1][y1];
              if (y0) sum -= mat[x1][y0-1];
              if (x0) sum -= mat[x0-1][y1];
              if (x0 && y0) sum += mat[x0-1][y0-1];
              
              x0 = i; y0 = j; x1 = N - 1; y1 = N - 1;
              sum += mat[x1][y1];
              if (y0) sum -= mat[x1][y0-1];
              if (x0) sum -= mat[x0-1][y1];
              if (x0 && y0) sum += mat[x0-1][y0-1];
            }
            ans = std::max(ans, sum);
          }
        }
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
