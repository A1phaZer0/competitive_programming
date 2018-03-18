#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
  int T, R, H;
  int **t;
  int **r;
  int **h;
  int i, j, k;
  int p;
  int min;
  int a, b, c;

  while (scanf("%d %d %d\n", &T, &R, &H) != EOF) {
    t = (int **)malloc(sizeof(*t) * T);
    for (i = 0; i < T; i++)
      t[i] = (int *)malloc(sizeof(int) * (R+1));
    r = (int **)malloc(sizeof(*r) * R);
    for (i = 0; i < R; i++) 
      r[i] = (int *)malloc(sizeof(int) * (H+1));
    h = (int **)malloc(sizeof(*h) * H);
    for (i = 0; i < H; i++) 
      h[i] = (int *)malloc(sizeof(int) * (T+1));

    for (i = 0; i < T; i++)
      for (j = 0; j < R + 1; j++)
        scanf("%d", t[i]+j);
    for (i = 0; i < R; i++)
      for (j = 0; j < H + 1; j++)
        scanf("%d", r[i]+j);
    for (i = 0; i < H; i++)
      for (j = 0; j < T + 1; j++)
        scanf("%d", h[i]+j);

    min = 10000009;

    for (i = 0; i < T; i++) {
      for (j = 1; j < R+1; j++) {
        if (t[i][j] == 0) {
          for (k = 1; k < H+1; k++) {
            if (r[j-1][k] == 0 && h[k-1][i+1] == 0) {
              p = t[i][0] + r[j-1][0] + h[k-1][0];
              if (p < min) {
                min = p;
                a = i;
                b = j-1;
                c = k-1;
              }
            }
          }
        }
      }
    }

    if (min == 10000009)
      printf("Don't get married!\n");
    else 
      printf("%d %d %d:%d\n", a, b, c, min);
  }
  return 0;
}
