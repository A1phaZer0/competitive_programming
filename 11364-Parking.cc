#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
  int max, min;
  int c, n;
  int x;

  scanf("%d\n", &c);
  while (c--) {
    scanf("%d\n", &n);
    max = 0;
    min = 99;
    while (n--) {
      scanf("%d ", &x);
      if (x > max)
        max = x;
      if (x < min)
        min = x;
    }
    printf("%d\n", 2 * (max - min));
  }

  return 0;
}
