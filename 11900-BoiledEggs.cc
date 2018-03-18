#include <cstdio>
#include <cstdlib>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
  int T;
  int n, P, Q;
  int i, inp;
  int ans, count;
  int t = 1;
  vector<int> vi;

  scanf("%d", &T);
  while (T--) {
    vi.clear();
    scanf("%d %d %d", &n, &P, &Q);
    for (i = 0; i < n; i++) {
      scanf("%d", &inp);
      vi.push_back(inp);
    }
    count = 0;
    ans = 0;
    for (i = 0; i < n; i++) {
      if (count + vi[i] <= Q && ans < P) {
        count += vi[i];
        ans++;
      } else
        break;
    }
    printf("Case %d: %d\n", t++, ans);
  }
  return 0;
}
