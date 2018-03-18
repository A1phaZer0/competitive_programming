#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>

using namespace std;

int ROW[8];
int row[8];
int MIN;

int check(int r, int c)
{
  int i;

  for (i = 0; i < c; i++) 
    if (r == row[i] || abs(c-i) == abs(r-row[i]))
      return 0;
  return 1;
}

void backtrack(int c)
{
  int i;
  int sum;

  for (i = 0; i < 8; i++) {
    if (check(i, c)) {
      row[c] = i;
      backtrack(c+1);
    }
  }

  if (c == 8) {
    sum = 0;
    for (i = 0; i < 8; i++)
      sum += row[i]+1-ROW[i]?1:0;
    if (sum < MIN)
      MIN = sum;
  }
}

int main(int argc, char *argv[])
{
  int tc = 1;
  while (scanf("%d %d %d %d %d %d %d %d\n", 
        ROW, ROW+1, ROW+2, ROW+3, ROW+4, ROW+5, ROW+6, ROW+7) != EOF) {
    MIN = 9999;
    backtrack(0);
    printf("Case %d: %d\n", tc++, MIN);
  }
  return 0;
}
