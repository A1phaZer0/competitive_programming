#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
  int N;
  int i, inp;
  vector<int> vi;
  int sum, ans;

  while (scanf("%d", &N) && N) {
    vi.clear();
    for (i = 0; i < N; i++) {
      scanf("%d", &inp);
      vi.push_back(inp);
    }
    sum = ans = 0;
    for (i = 0; i < (int)vi.size(); i++) {
      sum += vi[i];
      ans = std::max(ans, sum);
      if (sum < 0)
        sum = 0;
    }
    if (ans > 0)
      printf("The maximum winning streak is %d.\n", ans);
    else
      printf("Losing streak.\n");
  }
  return 0;
}
