#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> vi;
vector<int> memo;

int dp(int i)
{
  int j;
  int max;
  int val;

  max = 0;
  for (j = 0; j < i; j++) {
    val = dp(j) + 1;
    if (vi[j] >= vi[i] && val > max)
      max = val;
  }

  memo[i] = std::max(max, memo[i]);

  return memo[i];
}

int main(int argc, char *argv[])
{
  int inp;
  int i, N;
  int max;
  int tc = 1;
  int flag = 0;

  vi.clear();
  N = 0;
  while (scanf("%d", &inp) != EOF) {
    if (inp != -1) { 
      vi.push_back(inp);
      memo.push_back(1);
      N++;
    }
    else {
      if (!N)
        break;
      dp(N-1);
      max = 0;
      if (flag++)
        printf("\n");
      for (i = 0; i < N; i++)
        if (memo[i] > max)
          max = memo[i];
      printf("Test #%d:\n", tc++);
      printf("  maximum possible interceptions: %d\n", max);
      N = 0;
      vi.clear();
      memo.clear();
    }
    
  }
  return 0;
}
