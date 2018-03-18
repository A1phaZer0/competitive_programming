#include <cstdio>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
  int tc, hj, lj;
  int nw; // number of walls
  int h, oh;
  int n;

  scanf("%d\n", &tc);
  n = tc;

  while (tc--) {
    hj = lj = 0;
    scanf("%d\n", &nw);
    scanf("%d", &oh);
    nw--;
    while (nw--) {
      scanf("%d", &h);
      if (h > oh)
        hj++;
      if (h < oh)
        lj++;
      oh = h;
    }
    printf("Case %d: %d %d\n", n-tc, hj, lj);
  }

  return 0;
}
