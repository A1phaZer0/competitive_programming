#include <cstdio>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
  int N, M, C;
  int c[21];
  int s[21]; // state , initially off;
  int i, j;
  int total;
  int n = 1;
  int max;

  while (1) {
    max = 0;
    scanf("%d %d %d\n", &N, &M, &C);
    total = 0;
    if (!N)
      break;
    for (i = 1; i <= N; i++) {
      scanf("%d\n", c + i);
      s[i] = 0;
    }
    for (i = 1; i <= M; i++) {
      scanf("%d\n", &j);
      if (s[j]) {
        s[j] = 0;
        total -= c[j];
      } else {
        s[j] = 1;
        total += c[j];
        if (total > max)
          max = total;
      }
    }
    if (max > C) {
        printf("Sequence %d\n", n);
        printf("Fuse was blown.\n");
    } else {
      printf("Sequence %d\n", n);
      printf("Fuse was not blown.\n");
      printf("Maximal power consumption was %d amperes.\n", max);
    }
    n++;
    printf("\n");
  }


  return 0;
}
