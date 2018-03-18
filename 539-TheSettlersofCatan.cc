#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <algorithm>

using namespace std;

int N, M;
int MAT[25][25];
int MAX;
int ans;

void backtrack(int k)
{
  int i;
  for (i = 0; i < N; i++)
    if (MAT[k][i] == 1) {
      MAT[k][i] = 0;
      MAT[i][k] = 0;
      ans += 1;
      if (ans > MAX)
        MAX = ans;
      backtrack(i);
      ans -= 1;
      MAT[k][i] = 1;
      MAT[i][k] = 1;
    }
}

int main(int argc, char *argv[])
{
  int a, b;
  int i, j;
  while (scanf("%d %d\n", &N, &M) && (N || M)) {
    MAX = 0;
    for (i = 0; i < 25; i++)
      for (j = 0; j < 25; j++)
        MAT[i][j] = 0;
    for (i = 0; i < M; i++) {
      scanf("%d %d\n", &a, &b);
      MAT[a][b] = MAT[b][a] = 1;
    }

    for (i = 0; i < N; i++) {
      ans = 0;
      backtrack(i);
    }
    printf("%d\n", MAX);
  }
  return 0;
}
