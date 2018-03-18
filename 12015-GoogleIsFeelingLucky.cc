#include <cstdio>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
  int tc;
  int n;
  char s[10][101];
  int v[10];
  int max;
  int i;

  scanf("%d\n", &tc);
  n = tc;
  while (tc--) {
    max = 0;
    for (i = 0; i < 10; i++) {
      scanf("%s %d\n", s[i], v + i);
      if (v[i] > max)
        max = v[i];
    }
    printf("Case #%d:\n", n-tc);
    for (i = 0; i < 10; i++)
      if (v[i] == max)
        printf("%s\n", s[i]);
  }
  return 0;
}
