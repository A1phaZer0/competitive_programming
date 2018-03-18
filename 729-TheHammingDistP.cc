#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <algorithm>

using namespace std;

int N, H;
int MAT[16];

void backtrack(int h, int i)
{
  int j;

  if (h == H && i == N) {
    for (j = 0; j < N; j++)
      printf("%d", MAT[j]);
    printf("\n");
  }

  if (i < N) {
    MAT[i] = 0;
    backtrack(h, i+1);
    MAT[i] = 1;
    backtrack(h+1, i+1);
  }
}


int main(int argc, char *argv[])
{
  int tc;
  int flag = 0;

  scanf("%d\n", &tc);
  while (tc--) {
    if (flag++)
      printf("\n");
    scanf("%d %d\n", &N, &H);
    backtrack(0, 0);
  }

  return 0;
}
