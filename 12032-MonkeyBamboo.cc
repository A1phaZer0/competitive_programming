#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> vi;

int simulate(int k)
{
  int i;
  for (i = 1; i < (int)vi.size(); i++) {
    if (vi[i] - vi[i-1] > k)
      return 0;
    else if (vi[i] - vi[i-1] == k) 
      k--;
    else 
      ;
  }
  return 1;
}

int main(int argc, char *argv[])
{
  int tc, N;
  int n;
  int i;
  int h;
  int lo, hi, mid;
  int ans;

  scanf("%d\n", &tc);
  N = tc;
  while (tc--) {
    vi.clear();
    vi.push_back(0);
    scanf("%d\n", &n);
    for (i = 0; i < n; i++) {
      scanf("%d", &h);
      vi.push_back(h);
    }
    lo = 1;
    hi = vi[n];
    while (lo <= hi) {
      mid = lo + (hi - lo)/2;
      if (simulate(mid)) {
        hi = mid - 1;
        ans = mid;
      }
      else
        lo = mid + 1;
    }
    printf("Case %d: %d\n", N - tc, ans);  
  }
  return 0;
}
