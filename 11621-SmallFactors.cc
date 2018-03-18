#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
  vector<unsigned long long> exp2;
  vector<unsigned long long> exp3;
  vector<unsigned long long> exp23;
  vector<unsigned long long>::iterator it;
  unsigned long long i, j, N;
  for (i = 0; i <= 31; i++)
    exp2.push_back((unsigned long long)pow(2,i));
  for (j = 0; j <= 20; j++)
    exp3.push_back((unsigned long long)pow(3,j));
  for (i = 0; i <= 31; i++)
    for (j = 0; j <= 20; j++) 
      exp23.push_back(exp2[i] * exp3[j]);

  sort(exp23.begin(), exp23.end());

  while (scanf("%llu", &N) && N) {
    it = lower_bound(exp23.begin(), exp23.end(), N); 
    printf("%llu\n", *it);
  }
  return 0;
}
