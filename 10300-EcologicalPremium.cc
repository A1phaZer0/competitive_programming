#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
  int tc, n;
  int a, b, ans;

  scanf("%d\n", &tc);
  while (tc--) {
    ans = 0;
    scanf("%d\n", &n);
    while (n--) {
      scanf("%d %*d %d\n", &a, &b);
      ans += a * b;
    }
    printf("%d\n", ans);
  }
  return 0;
}
