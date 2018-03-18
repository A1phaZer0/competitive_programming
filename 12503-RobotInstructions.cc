#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
  int tc;
  int m[101];
  int i, n, k;
  char c[20];
  int ans;

  scanf("%d\n", &tc);
  while (tc--) {
    ans = 0;
    for (i = 0; i < 101; i++)
      m[i] = 0;
    scanf("%d\n", &n);
    for (i = 1; i <= n; i++) {
      scanf("%s", c);
      if (!strcmp(c, "LEFT"))
        m[i] = -1;
      else if (!strcmp(c, "RIGHT"))
        m[i] = 1;
      else {
        scanf("%*s %d", &k);
        m[i] = m[k];
      }
    }
    for (i = 1; i <= n; i++) 
      ans += m[i];
    printf("%d\n", ans);
  }
  return 0;
}
