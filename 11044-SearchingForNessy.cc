#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;


int main(int argc, char *argv[])
{
  int r, c, n;
  int a, b;

  scanf("%d\n", &n);
  while (n--) {
    scanf("%d %d\n", &r, &c);
    a = (r-2)%3 ? (r-2)/3 + 1 : (r-2)/3;
    b = (c-2)%3 ? (c-2)/3 + 1 : (c-2)/3;
    printf("%d\n", a*b);
  }

  return 0;
}
