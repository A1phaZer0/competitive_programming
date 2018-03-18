#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
  int C, S;
  vector<int> s;
  int i, inp;
  int t = 1;
  double avg;
  double ans;

  while (scanf("%d %d", &C, &S) != EOF) {
    s.clear();
    avg = ans = 0;
    for (i = 0; i < S; i++) {
      scanf("%d", &inp);
      s.push_back(inp);
      avg += inp;
    }
    avg /= C;
    for (; i < 2*C; i++)
      s.push_back(0); // dummy
    sort(s.begin(), s.end());
    printf("Set #%d\n", t++);
    for (i = 0; i < C; i++) {
      printf(" %d:", i);
      if (s[2*C-1-i])
        printf(" %d", s[2*C-1-i]);
      if (s[i])
        printf(" %d", s[i]);
      printf("\n");
      ans += abs((double)s[i] + (double)s[2*C-1-i] - (double)avg);
    }
    printf("IMBALANCE = %.5f\n\n", ans);
  }
  return 0;
}
