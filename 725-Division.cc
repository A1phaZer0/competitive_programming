#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
  int abcde;
  int fghij;
  int n;
  int digits;
  int flag;
  int tmp;
  int blank = 0;

  while (scanf("%d\n", &n) && n) {
    flag = 0;
    if (blank)
      printf("\n");
    for (fghij = 1234; fghij <= 98765 / n; fghij++) {
      digits = (fghij < 10000); // whether fghij gets a leading '0'
      abcde = fghij * n;
      tmp = abcde;
      while (tmp) {
        digits |= (1 << tmp % 10);
        tmp /= 10;
      }
      tmp = fghij;
      while (tmp) {
        digits |= (1 << tmp % 10);
        tmp /= 10;
      }
      if (digits == (1 << 10) - 1) {
        printf("%0.5d / %0.5d = %d\n", abcde, fghij, n);
        flag = 1;
      }
    }
    if (!flag) 
      printf("There are no solutions for %d.\n", n);
    blank = 1;
  }
  return 0;
}
