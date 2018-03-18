#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
  int n, a, b;
  int i, tc, x;
  
  scanf("%d\n", &n);
  tc = 1;
  while (n) {
    a = b = 0;
    for (i = 0; i < n; i++) {
      scanf("%d ", &x);
      if (x > 0)
        a++;
      else
        b--;
    }
    printf("Case %d: %d\n", tc++, a + b);
    scanf("%d\n", &n);
  }
  return 0;
}
