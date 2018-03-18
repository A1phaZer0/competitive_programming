#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>

using namespace std;

int board[8][8];
int row[8];
int MAX;

int check(int r, int c)
{
  int i;
  for (i = 0; i < c; i++) 
    if (row[i] == r || abs(r-row[i]) == abs(c-i))
      return 0;
  return 1;
}
void backtrack(int c, int ans)
{
  int i;
  for (i = 0; i < 8; i++) {
    if (check(i, c)) {
      row[c] = i;
      backtrack(c+1, ans + board[i][c]);
    }
  }
  if (ans > MAX)
    MAX = ans;
}

int main(int argc, char *argv[])
{
  int tc;
  int i, j;

  scanf("%d\n", &tc);
  while (tc--) {
    MAX = 0;
    for (i = 0; i < 8; i++) 
      row[i] = -1;
    for (i = 0; i < 8; i++) {
      for (j = 0; j < 8; j++) {
        scanf("%d ", board[i]+j);
      }
    }
    backtrack(0, 0);
    printf("%5d\n", MAX);
  }

  return  0;
}
