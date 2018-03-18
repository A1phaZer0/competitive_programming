#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
  int tc, n;
  vector<int> v;
  int i, j, inp;
  int ans, b;

  scanf("%d\n", &tc);
  while (tc--) {
    scanf("%d\n", &n);
    v.clear();
    v.resize(n);
    for (i = 0; i < n; i++) {
      scanf("%d", &inp);
      v[i] = inp;
    }
    ans = 0;
    for (i = 1; i < n; i++) {
      b = 0;
      for (j = 0; j < i; j++) {
        if (v[j] <= v[i])
          b++;
      }
      ans += b;
    }
    printf("%d\n", ans);
  }
  return 0;
}
