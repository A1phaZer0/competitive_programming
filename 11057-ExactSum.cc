#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
  int N, M;
  vector<int> vi;
  vector<int>::iterator it;
  vector<int>::iterator tmp;
  int inp;
  int a, b;
  int i;

  while (scanf("%d", &N) != EOF) {
    vi.clear();
    for (i = 0; i < N; i++) {
      scanf("%d", &inp);
      vi.push_back(inp);
    }
    scanf("%d", &M);
    sort(vi.begin(), vi.end());
    it = vi.begin();
    while (*it <= M - *it) {
      tmp = lower_bound(vi.begin(), vi.end(), M - *it);
      if (*tmp == M - *it) {
        a = *it;
        b = M - *it;
      }
      it++;
    }
    printf("Peter should buy books whose prices are %d and %d.\n\n", a, b);
  }
  return 0;
}
