#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
  int ce[21];
  int tc;
  int n;
  int i, j;
  int d, k;
  long long ans;

  scanf("%d\n", &tc);
  while (tc--) {
    scanf("%d ", &n);
    ans = 0;
    for (i = 0; i <=n; i++) 
      scanf("%d", ce + i);
    scanf("%d", &d);
    scanf("%d", &k);
    for (i = 1; k > 0; i++) 
      k -= d*i;
    i--;
    for (j = 0; j <=n; j++) 
      ans += ce[j] * (long long)pow(i, j);

    printf("%lld\n", ans);
  }

  return 0;
}
