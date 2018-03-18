#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
  int a, b;

  while (1) {
    scanf("%d %d\n", &a, &b);
    if (a == -1)
      break;
    if (abs(a - b) > 50)
      printf("%d\n", 100 - abs(a - b));
    else
      printf("%d\n", abs(a - b));
  }
  return 0;
}
