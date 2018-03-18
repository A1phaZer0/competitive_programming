#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

void Eratosthenes(int * sieve)
{
  int i, j;
  for (i = 0; i <= 1000000; i++)
    sieve[i] = 1;
  i = 2;
  while (i <= 1000) {
    for (j = 0; i*(i+j) <= 1000000; j++) 
      sieve[i*(i+j)] = 0;
    i++;
    while (i <= 1000 && !sieve[i])
      i++;
  }
}

int main(int argc, char *argv[])
{
  int sieve[1000001];
  vector<int> vi;
  vector<int>::iterator it;
  vector<int>::iterator tmp;
  int i;
  long long count = 0;
  int tgt;
  Eratosthenes(sieve);

  for (i = 2; i <= 1000000; i++)
    if (sieve[i])
      vi.push_back(i);
  i = 1;

  while (scanf("%d\n", &tgt) && tgt) {
    printf("Case %d: ", i++);
    count = 0;
    it = lower_bound(vi.begin(), vi.end(), tgt);
    if (*it != tgt)
      it--;
    while (it > vi.begin()) {
      if (tgt - *it == 1) {
        tmp = vi.begin() - 1;
      } else if (tgt - *it > *it) {
        tmp = it - 1;
      } else if (tgt - *it < *it) {
        tmp = lower_bound(vi.begin(), vi.end(), tgt - *it);
        if (*tmp > tgt - *it)
          tmp--;
      } else { //tgt - *it == *it
        tmp = it - 1;
      }
      count += (long long)(tmp - vi.begin() + 1);
      it--;
    }
    printf("%lld\n", count);
  }

  return 0;
}
