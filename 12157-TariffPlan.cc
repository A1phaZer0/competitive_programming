#include <cstdio>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
  int tc;
  int n;
  int tt;
  int mile, juice;
  int d;

  scanf("%d\n", &tc);
  tt = tc;

  while (tc--) {
    scanf("%d\n", &n);
    mile = juice = 0;
    while (n--) {
      scanf("%d", &d);
      mile += (d/30 + 1) * 10;
      juice += (d/60 + 1) * 15;
    }
    printf("Case %d: ", tt-tc);
    if (mile < juice) {
      printf("Mile %d\n", mile);
    } else if (mile > juice) {
      printf("Juice %d\n", juice);
    } else {
      printf("Mile Juice %d\n", mile);
    }
  }
  return 0;
}
