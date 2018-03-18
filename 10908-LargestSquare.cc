#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
  int T;
  int M, N, Q;
  char RECT[100][101];
  int i, j, k;
  int r, c;
  int l;
  int found;

  scanf("%d\n", &T);
  while (T--) {
    scanf("%d %d %d\n", &M, &N, &Q);
    printf("%d %d %d\n", M, N, Q);
    for (i = 0; i < M; i++) 
      scanf("%s\n", RECT[i]);
    for (i = 0; i < Q; i++) {
      scanf("%d %d\n", &r, &c);
      l = std::min(std::min(r, c), std::min(N-c-1, M-r-1));
      while (l >= 0) {
        found = 1;
        for (j = r - l; j <= r + l && found; j++) {
          for (k = c - l; k <= c + l && found; k++) {
            if (RECT[j][k] != RECT[r][c])
              found = 0;
          }
        }
        if (found) {
          printf("%d\n", (l)*2 + 1);
          break;
        }
        l--;
      }
    }
  }
  return 0;
}
