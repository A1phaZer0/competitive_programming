#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
  int tc;
  int a, b, c;
  int n;

  scanf("%d\n", &tc);
  n = tc;
  while (tc--) {
    scanf("%d %d %d\n", &a, &b, &c);
    if ((a-b) * (a-c) < 0)
      printf("Case %d: %d\n", n-tc, a);
    else if ((b-a) * (b-c) < 0)
      printf("Case %d: %d\n", n-tc, b);
    else
      printf("Case %d: %d\n", n-tc, c);
  }
  return 0;
}
