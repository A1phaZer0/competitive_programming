#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
  int M, N;
  int i, j, k, g;
  int mat[100][100];
  int ans, sum;

  memset(mat, 0, sizeof(mat));
  while (scanf("%d %d", &M, &N) && M) {
    for (i = 0; i < M; i++) {
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
    ans = 0;
    for (i = 0; i < M; i++) {
      for (j = 0; j < N; j++) {
        for (k = i; k < M; k++) {
          for (g = j; g < N; g++) {
            sum = mat[k][g];
            if (i)
              sum -= mat[i-1][g];
            if (j)
              sum -= mat[k][j-1];
            if (i && j)
              sum += mat[i-1][j-1];
            if (!sum) {
              sum = (k-i+1)*(g-j+1);
              ans = std::max(sum, ans);
            }
          }
        }
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
