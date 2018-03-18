#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

vi numbers;
vvi tmp;

int subsum(int id, int sum)
{
  return 0;
}

int main(int argc, char *argv[])
{
  int N, Q, D, M;
  int sum;
  int s = 0;
  while (scanf("%d %d\n", &N, &Q) && N) {
    numbers.clear();
    sum = 0;
    printf("SET %d:\n", ++s);
    for (int i = 0; i < N; i++) {
      int inp;
      scanf("%d\n", &inp);
      sum += inp;
      numbers.push_back(inp);
    }
    for (int i = 0; i < Q; i++) {
      int ans = 0;
      scanf("%d %d\n", &D, &M);
      sum = sum / D * D;
      while (sum > 0) {
        ans += subsum(0, sum);
        sum -= D;
      }

    }
  }
  return 0;
}
