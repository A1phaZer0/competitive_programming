#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
  int init, a, b ,c;
  int ans;

  while (1) {
    scanf("%d %d %d %d\n", &init, &a, &b, &c);
    if ((init | a | b | c) == 0)
      break;
    ans = 120 + (40 + init - a) % 40
      + (40 + b - a) % 40
      + (40 + b - c) % 40;
    printf("%d\n", ans * 9);
  }
  return 0;
}
