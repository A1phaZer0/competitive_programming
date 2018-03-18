#include <cstdio>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
  int m;
  int ans;

  while (1) {
    scanf("%d\n", &m);
again:
    if (m == 0)
      break;
    ans = 0;
    while (m != 0) {
      ans += m - m / 10 * 10;
      m /= 10;
    }
    if (ans / 10 == 0)
      printf("%d\n", ans);
    else {
      m = ans;
      goto again;
    }
  }
  return 0;
}
