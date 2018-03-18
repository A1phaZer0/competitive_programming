#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
  vector<int> v;
  int n;
  int i;
  int inp;
  int a[6];
  int flag = 0;

  while (scanf("%d", &n) && n) {
    if (flag++)
      printf("\n");
    v.clear();
    for (i = 0; i < n; i++) {
      scanf("%d", &inp);
      v.push_back(inp);
    }
    for (a[0] = 0; a[0] <= n-6; a[0]++) {
      for (a[1] = a[0] + 1; a[1] <= n-5; a[1]++) {
        for (a[2] = a[1] + 1; a[2] <= n-4; a[2]++) {
          for (a[3] = a[2] + 1; a[3] <= n-3; a[3]++) {
            for (a[4] = a[3] + 1; a[4] <= n-2; a[4]++) {
              for (a[5] = a[4] + 1; a[5] <= n-1; a[5]++) {
                printf("%d %d %d %d %d %d\n", v[a[0]], v[a[1]], v[a[2]],
                    v[a[3]], v[a[4]], v[a[5]]);
              }
            }
          }
        }
      }
    }
  }
  return 0;
}
