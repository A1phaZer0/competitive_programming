#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
  long long s[18];
  long long ans;
  long long max;
  int n;
  int i, j, k;

  int tc = 1;

  while (scanf("%d\n", &n) != EOF) {
    max = 0;
    for (i = 0; i < n; i++)
      scanf("%lld", s+i);
    for (i = 0; i < n; i++) {
      for (j = 0; j < n; j++) {
        ans = 1;
        for (k = i; k <= j; k++) {
          ans *= s[k];
          if (ans > max)
            max = ans;
        }
      }
    }
    printf("Case #%d: The maximum product is %lld.\n\n", tc, max);
    tc++;
  }
  return 0;
}
