#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
  int n;
  int tc;
  vector<int> vi;
  unsigned int i;
  int ans;
  int h;
  int a;

  tc = 1;
  while (scanf("%d\n", &n) && n) {
    ans = 0;
    vi.clear();
    for (i = 0; i < n; i++) {
      scanf("%d", &a);
      ans += a;
      vi.push_back(a);
    }
    h = ans/n;
    ans = 0;
    for (i = 0; i < vi.size(); i++) {
      if (vi[i] > h)
        ans += vi[i] - h;
    }
    printf("Set #%d\n", tc++);
    printf("The minimum number of moves is %d.\n", ans);
    printf("\n");
  }
  return 0;
}
