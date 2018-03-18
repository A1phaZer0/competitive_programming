#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
  int tc;
  int i, j, n;
  int inp;
  int dis, min;
  vector<int> v;

  scanf("%d\n", &tc);
  while (tc--) {
    v.clear();
    min = 300000000;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
      scanf("%d\n", &inp);
      v.push_back(inp);
    }

    for (i = 0; i < n; i++) {
      dis = 0;
      for (j = 0; j < n; j++) 
        dis += abs(v[j] - v[i]);
      if (dis < min)
        min = dis;
    }
    printf("%d\n", min);
  }
  return 0;
}
