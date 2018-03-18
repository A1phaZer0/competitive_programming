#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
  int T, N;
  int n, inp, i;
  vector<int> vi;
  int ans;

  scanf("%d", &T);
  N = T;
  while (T--) {
    scanf("%d\n", &n);
    vi.clear();
    ans = 0;
    for (i = 0; i < n; i++) {
      scanf("%1c", &inp);
      vi.push_back(inp);
    }

    i = 0;
    while (i < n) {
      if ((char)vi[i] == '.') {
        i += 3;
        ans++;
      } else 
        i++;
    }
    printf("Case %d: %d\n",N - T,  ans);
  }
  return 0;
}
