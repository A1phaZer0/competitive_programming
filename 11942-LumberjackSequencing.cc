#include <cstdio>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
  int tc;
  int a, b;
  int up, down;
  int i;

  scanf("%d\n", &tc);
  printf("Lumberjacks:\n");
  while (tc--) {
    b = 0;
    up = down = 0;
    for (i = 0; i < 10; i++) {
      scanf("%d", &a);
      if (b) {
        if (a > b)
          up++;
        else 
          down++;
      }
      b = a;
    }
    if (up == 9 || down == 9)
      printf("Ordered\n");
    else
      printf("Unordered\n");
  }

  return 0;
}
