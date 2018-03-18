#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
  int H, K;
  vector<int> heads, knights;
  vector<int>::iterator it;
  int i, inp;
  int doomed;
  int ans;

  while (scanf("%d %d", &H, &K) && H) {
    heads.clear();
    knights.clear();
    doomed = 0;
    ans = 0;
    for (i = 0; i < H; i++) {
      scanf("%d", &inp);
      heads.push_back(inp);
    }
    for (i = 0; i < K; i++) {
      scanf("%d", &inp);
      knights.push_back(inp);
    }
    if (H > K) {
      printf("Loowater is doomed!\n");
      continue;
    }
    sort(heads.begin(), heads.end());
    sort(knights.begin(), knights.end());
    for (i = 0; i < H; i++) {
      it = lower_bound(knights.begin(), knights.end(), heads[i]);
      if (it == knights.end()) {
        printf("Loowater is doomed!\n");
        doomed = 1;;
        break;
      }
      ans += *it;
      *it = -1;
    }
    if (!doomed)
      printf("%d\n", ans);
  }
  return 0;
}
