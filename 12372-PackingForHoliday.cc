#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
  int tc;
  int N;
  int l, w, h;

  scanf("%d\n", &tc);
  N = tc;
  while (tc--) {
    scanf("%d %d %d\n", &l, &w, &h);
    if (l <= 20 && w <= 20 && h <= 20)
      printf("Case %d: good\n", N - tc);
    else
      printf("Case %d: bad\n", N - tc);
  }

  return 0;
}
