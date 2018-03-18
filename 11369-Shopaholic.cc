#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
  int tc;
  int i, inp;
  int n;
  int ans;
  vector<int> vi;

  scanf("%d\n", &tc);
  while (tc--) {
    vi.clear();
    ans = 0;
    scanf("%d\n", &n);
    for (i = 0; i < n; i++) {
      scanf("%d", &inp);
      vi.push_back(inp);
    }
    sort(vi.rbegin(), vi.rend());
    for (i = 0; i < n; i++)
      if ((i+1) % 3 == 0)
        ans += vi[i];
    printf("%d\n", ans);
  }

  return 0;
}
