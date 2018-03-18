#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
  int k;
  int x, y;
  int n;

  while (scanf("%d\n", &k) != EOF) {
    n = 0;
    for (y = k + 1; y <= k*2; y++) {
      if (!(k * y % (y - k))) {
        n++;
      }
    }
    printf("%d\n", n);
    for (y = k + 1; y <= k*2; y++) {
      if (!(k * y % (y - k))) {
        x = k * y / (y - k);
        printf("1/%d = 1/%d + 1/%d\n", k, x, y);
      }
    }
  }

  return 0;
}
