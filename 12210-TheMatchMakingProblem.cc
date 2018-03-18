#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
  int B, S;
  vector<int> b, s;
  int i, inp;
  int t = 1;

  while (scanf("%d %d", &B, &S) && (B || S)) {
    b.clear();
    s.clear();
    for (i = 0; i < B; i++) {
      scanf("%d", &inp);
      b.push_back(inp);
    }
    for (i = 0; i < S; i++) {
      scanf("%d", &inp);
      s.push_back(inp);
    }
    sort(b.rbegin(), b.rend());
    sort(s.rbegin(), s.rend());
    printf("Case %d: %d", t++, B-S > 0 ? B-S : 0);
    if (B-S > 0)
      printf(" %d", b[B-1]);
    printf("\n");
  }
  return 0;
}
