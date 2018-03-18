#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>

using namespace std;

int line = 1;
int check(int *row, int r, int c)
{
  int i;

  for (i = 0; i < c; i++)
    if (row[i] == r || abs(row[i] - r) == abs(i - c))
      return 0;
  return 1;
}

void backtrack(int *row, int c, int a, int b)
{
  int i;
  if (c == 8 && row[b] == a) {
    printf("%2d      %d", line++, row[0]+1);
    for (i = 1; i < 8; i++)
      printf(" %d", row[i]+1);
    printf("\n");
  }
  for (i = 0; i < 8; i++)
    if (check(row, i, c)) {
      row[c] = i;
      backtrack(row, c+1, a, b);
    }
}

int main(int argc, char *argv[])
{
  int row[8];
  int a, b;
  int tc;
  int flag = 0;
  int i;

  scanf("%d\n", &tc);
  while (tc--) {
    line = 1;
    for (i = 0; i < 8; i++)
      row[i] = -1;
    if (flag++) 
      printf("\n");
    scanf("%d %d\n", &a, &b);  
    printf("SOLN       COLUMN\n");
    printf(" #      1 2 3 4 5 6 7 8\n\n");
    backtrack(row, 0, a-1, b-1);
  }
  return 0;
}
