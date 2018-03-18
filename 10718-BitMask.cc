#include <cstdio>
#include <cstdlib>
#include <vector>
#include <bitset>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
  unsigned int N;
  unsigned int L, U, LA;
  int i;
  unsigned int a;
  unsigned int ans;

  while (scanf("%u %u %u", &N, &L, &U) != EOF) {
    a = 1; // rightmost
    ans = L;
    for (i = 0; i < 31; i++) {
      if (((N & a) | (L & a)) == 0) {
        ans += a;
      } 
      a *= 2;
    }
    a = 1 << 31;
    for (i = 0; i < 31; i++) {
      if ((N & a) | (L & a)) {
        if (ans - a >= L)
          ans -= a;
      }
      a /= 2;
    }
    printf("%u\n", ans);
  }
  return 0;
}
