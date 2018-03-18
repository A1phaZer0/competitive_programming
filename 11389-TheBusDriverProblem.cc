#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
  int n, d, r;
  int i, inp;
  vector<int> morning;
  vector<int> evening;
  int ans;

  while (scanf("%d %d %d", &n, &d, &r) && n) {
    morning.clear();
    evening.clear();
    for (i = 0; i < n; i++) {
      scanf("%d", &inp);
      morning.push_back(inp);
    }
    for (i = 0; i < n; i++) {
      scanf("%d", &inp);
      evening.push_back(inp);
    }
    sort(morning.begin(), morning.end());
    sort(evening.rbegin(), evening.rend());
    ans = 0;
    for (i = 0; i < n; i++)
      if (morning[i] + evening[i] > d) 
        ans += (morning[i] + evening[i] - d) * r;
    printf("%d\n", ans);
  }
  return 0;
}
