#include <cstdio>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
  int tc, t;
  int max;
  int n, c;

  scanf("%d\n", &tc);
  t = tc;
  while (tc--) {
    max = 0;
    scanf("%d", &n);
    while (n--) {
      scanf("%d", &c);
      if (c > max)
        max = c;
    }
    printf("Case %d: %d\n", t - tc, max);
  }
  return 0;
}
