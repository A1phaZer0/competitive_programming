#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
  int tc, k;
  int total = 0;
  char d[8] = "donate";
  char r[8] = "report";
  char a[8];

  scanf("%d\n", &tc);
  while (tc--) {
    scanf("%s", a);
    if (!strcmp(d, a)) {
      scanf("%d", &k);
      total += k;
    } else {
      printf("%d\n", total);
    }
  }

  return 0;
}
