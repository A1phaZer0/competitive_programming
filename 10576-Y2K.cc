#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int S, D;
int month[12];
int MAX;

void backtrack(int m)
{
  int i;
  int sum;

  if (m == 12)
    return;

  
  month[m] = S;
  sum = 0;
  if (m-4 >= 0) {
    for (i = m-4; i <= m; i++)
      sum += month[i];
    if (sum < 0) {
      if (m == 11) {
        sum = 0;
        for (i = 0; i < 12; i++)
          sum += month[i];
        if (sum > MAX)
          MAX = sum;
      }
      backtrack(m+1);
    }
  } else
    backtrack(m+1);

  month[m] = -D;
  sum = 0;
  if (m-4 >= 0) {
    for (i = m-4; i <= m; i++) 
      sum += month[i];
    if (sum < 0) {
      if (m == 11) {
        sum = 0;
        for (i = 0; i < 12; i++) 
          sum += month[i];
        if (sum > MAX)
          MAX = sum;
      }
      backtrack(m+1);
    }
  } else
    backtrack(m+1);
}
int main(int argc, char *argv[])
{

  while (scanf("%d %d\n", &S, &D) != EOF) {
    MAX = -1;
    backtrack(0);
    if (MAX >= 0)
      printf("%d\n", MAX);
    else
      printf("Deficit\n");
  }
  return 0;
}
