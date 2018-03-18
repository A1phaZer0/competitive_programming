#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> vi;

vi lis;

int main(int argc, char *argv[])
{
  int tc;
  int inp;
  int N;
  int max;
  int pos;

  scanf("%d\n", &tc);

  while (tc--) {
    scanf("%d\n", &N);
    lis.resize(N);
    max = 0;
    while (N--) {
      scanf("%d\n", &inp);
      pos = lower_bound(lis.begin(), lis.begin() + max, inp) - lis.begin();
      lis[pos] = inp;
      if (pos + 1 > max)
        max = pos + 1;
    }
    printf("%d\n", max);
  }
    
  return 0;
}
