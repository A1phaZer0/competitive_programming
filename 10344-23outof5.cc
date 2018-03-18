#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <algorithm>

using namespace std;

int a[5];
int flag;

void backtrack(int ans, int i)
{
  if (i < 5) {
    backtrack(ans + a[i], i+1);
    backtrack(ans * a[i], i+1);
    backtrack(ans - a[i], i+1);
  } else {
    if (ans == 23)
      flag = 1;
  }
}

int main(int argc, char *argv[])
{

  int m = 0;
  while (scanf("%d %d %d %d %d\n", a, a+1, a+2, a+3, a+4) && (a[0] || a[1]
        || a[2] || a[3] || a[4])) {
    if (m++)
      printf("\n");
    flag = 0;
    sort(a, a+5);
    while (next_permutation(a, a+5)) 
      backtrack(a[0], 1);
    if (flag)
      printf("Possible");
    else
      printf("Impossible");
  }
  return 0;
}
