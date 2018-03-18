#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

void Eratosthenes(int sieve[])
{
  int i, j;

  i = 2;
  while (i <= 1000) {
    if (sieve[i]) {
      j = i;
      while (i * j <= 1000) {
        sieve[i*j] = 0;
        j++;
      }
    }
    i++;
  }
}

int nod(int n, vector<int> sieve)
{
  int sum = 0;
  int divisors = 1;
  vector<int>::iterator it;
  vector<int>::iterator j;

  it = lower_bound(sieve.begin(), sieve.end(), n);
  if (*it == n)
    return 2;


  j = sieve.begin();
  while ((*j) * (*j) <= n) {
    sum = 0;
    while (n % *j == 0) {
      sum++;
      n /= *j;
    } 
    divisors *= (sum + 1);
    j++;
  }

  if (n != 1)
    divisors *= 2;

  return divisors;
}

int main(int argc, char *argv[])
{
  int tc; 
  int caseid = 1;
  int A, B;
  vector<int> vi;
  vector<int>::iterator a, b;
  vector<int> sieve;
  int mat[1000001];
  int sum, i;

  for (i = 2; i <= 1000000; i++)
    mat[i] = 1;
  Eratosthenes(mat);
  for (i = 2; i <= 1000; i++)
    if (mat[i]) {
      sieve.push_back(i);
    }

  vi.push_back(1);
  sum = 1;
  while (sum <= 1000000) {
    sum += nod(sum, sieve);
    vi.push_back(sum);
  }


  scanf("%d\n", &tc);
  while (tc--) {
    printf("Case %d: ", caseid++);
    scanf("%d %d", &A, &B);
    a = lower_bound(vi.begin(), vi.end(), A);
    b = lower_bound(vi.begin(), vi.end(), B);
    if (*b > B)
      b--;
    printf("%d\n", b-a+1);

  }
  return 0;
}
