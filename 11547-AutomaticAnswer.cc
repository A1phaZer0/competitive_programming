#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
  int tc;
  long ans, org;
  long x;
  int digit;


  scanf("%d\n", &tc);
  while (tc--) {
    digit = 1;
    scanf("%ld\n", &x);
    ans = x * 567;
    ans /= 9;
    ans += 7492;
    ans *= 235;
    ans /= 47;
    ans -= 498;

    /* calculation */
    ans /= 10;
    org = ans;
    ans = ans / 10 * 10;
    digit = org - ans;
    printf("%d\n", abs(digit));
  }
  return 0;
}
