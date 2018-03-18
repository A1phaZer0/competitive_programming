#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
  int n, a, b;

  scanf("%d\n", &n);
  while (n--) {
    scanf("%d %d\n", &a, &b);
    if (a-b > 0)
      printf(">\n");
    else if (a-b < 0)
      printf("<\n");
    else
      printf("=\n");
  }
  return 0;
}
