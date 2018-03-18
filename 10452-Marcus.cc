#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>

using namespace std;

char stones[8][9];
char s[8] = {'@', 'I', 'E', 'H', 'O', 'V', 'A', '#'};
int M, N;

void backtrack(int r, int c, int i)
{
  if (i < 6) {
    if (c > 0 && stones[r][c-1] == s[i+1]) {
      printf("left ");
      backtrack(r, c-1, i + 1);
    }
    if (c < N - 1 && stones[r][c+1] == s[i+1] ) {
      printf("right ");
      backtrack(r, c+1, i + 1);
    }
    if (r > 0 && stones[r-1][c] == s[i+1] ) {
      printf("forth ");
      backtrack(r-1, c, i + 1);
    }
  } else {
    if (c > 0 && stones[r][c-1] == '#')
      printf("left\n");
    if (c < N-1 && stones[r][c+1] == '#')
      printf("right\n");
    if (r > 0 && stones[r-1][c] == '#')
      printf("forth\n");
  }
}
int main(int argc, char *argv[])
{
  int tc;
  int i;
  int begin, end;

  scanf("%d\n", &tc);
  while (tc--) {
    scanf("%d %d\n", &M, &N);
    for (i = 0; i < M; i++) 
      scanf("%s\n", stones[i]);
    for (i = 0; i < N; i++) {
      if (stones[M - 1][i] == '@')
        begin = i;
      if (stones[0][i] == '#')
        end = i;
    }
    backtrack(M-1, begin, 0);
  }

  return 0;
}
