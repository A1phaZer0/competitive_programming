#include <cstdio>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
  int tc, n;
  int y1, y2;
  int k = -1;

  scanf("%d\n", &tc);
  while (tc--) {
    k = -1;
    scanf("%d\n", &n);
    while (n--) {
      scanf("%d %d\n", &y1, &y2);
      if (k == -1)
        k = y1 - y2;
      else if ((y1 - y2) != k) {
        if (tc == 0)
          printf("no\n");
        else 
          printf("no\n\n");
        k = -2;
        break;
      } else {
        ;
      }
    }
    if (k != -2) {
      if (tc == 0)
        printf("yes\n");
      else
        printf("yes\n\n");
    }

    
  }
  return 0;
}
