#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
  int tc;
  int n;
  int i, inp;
  int total, ans;
  vector<int> vi;

  scanf("%d\n", &tc);
  while (tc--) {
    scanf("%d\n", &n);
    vi.clear();
    for (i = 0; i < n; i++) {
      scanf("%d", &inp);
      vi.push_back(inp);
    }
    total = 0;
    ans = 0;
    for (i = 0; i < n - 1; i++) {
      if (total + vi[i] < vi[i+1]) {
        total += vi[i];
        ans++;
      }
    }
    ans++; // get last one in count;
    printf("%d\n", ans);
  }
  return 0;
}
