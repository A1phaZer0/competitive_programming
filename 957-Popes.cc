#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

int main (int argc, char *argv[])
{
  int Y, N, year;
  int i;
  int max, start, end;
  int popes;
  vector<int> vi;
  vector<int>::iterator it;
  vector<int>::iterator tmp;

  while (scanf("%d", &Y) != EOF) {
    vi.clear();
    max = 0;
    scanf("%d", &N);
    for (i = 0; i < N; i++) {
      scanf("%d", &year);
      vi.push_back(year);
    }
    it = vi.begin();
    while (it != vi.end()) {
      tmp = upper_bound(it, vi.end(), *it + Y - 1);
      popes = tmp - it;
      if (popes > max) {
        max = popes;
        start = *it;
        end = *(tmp-1);
      }
      it++;
    }
    printf("%d %d %d\n", max, start, end);
  }
  return 0;
}
