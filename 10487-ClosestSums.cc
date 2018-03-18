#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char * argv[])
{
  int n, m;
  int i, j, k;
  int inp;
  vector<int> v;
  int tc = 1;
  int sum, min;

  while (scanf("%d\n", &n) && n) {
    v.clear();
    for (i = 0; i < n; i++) {
      scanf("%d\n", &inp);
      v.push_back(inp);
    }
    scanf("%d\n", &m);
    printf("Case %d:\n", tc++);
    for (k = 0; k < m; k++) {
      min = 100000009;
      scanf("%d\n", &inp);
      for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
          if (i != j) {
            if (abs(v[i] + v[j] - inp) < min) {
              min = abs(v[i] + v[j] - inp);
              sum = v[i] + v[j];
            }
          }
        }
      }
      printf("Closest sum to %d is %d.\n", inp, sum);
    }
  }
  return 0;
}
