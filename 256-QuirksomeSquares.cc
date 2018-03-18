#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
  int n;
  long ans;
  long i;
  int k;

  while (scanf("%d\n", &n) != EOF) {
    k = (int)pow(10, n/2);
    i = 0;
    for (ans = 0; ans < (long)pow(10, n); ans = i*i) {
      if (ans == (long)pow(ans / k + ans % k, 2))
        printf("%.*ld\n", n, ans);
      i++;
    }
  }
  return 0;
}
