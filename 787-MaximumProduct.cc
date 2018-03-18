#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
  int i;
  long long max_pos, min_neg, max_neg, ans;
  long long product;
  long long inp;
  vector<long long> vi;

  while (scanf("%lld", &inp) != EOF) {
    if (inp == -999999) {
      max_neg = -999999;
      min_neg = 0;
      max_pos = vi[0];
      product = 1;
      for (i = 0; i < (int)vi.size(); i++) {
        if (vi[i] == 0) {
          max_neg = -999999;
          min_neg = 0;
          max_pos = 0;
          product = 1;
        } else {
          product *= vi[i];
          if (product < 0) {
            if (product > max_neg)
              max_neg = product;
            if (product < min_neg)
              min_neg = product;
          } else {
            if (product > max_pos)
              max_pos = product;
          }
        }
        ans = std::max(max_pos, min_neg / max_neg != 1 ? min_neg / max_neg : \
            min_neg);
      }
      printf("%lld\n", ans);
      vi.clear();
    } else {
      vi.push_back(inp);
    }
  }
  return 0;
}
