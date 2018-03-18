#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

vi value;
vvi tmp(100, vi(25001, -1));
vvi memo;

int knapsack(int id, int S)
{
  int ans = 0;


  if (id == (int)value.size())
    return 0;

  if (!S)
    return 0;

  if (memo[id][S] != -1)
    return memo[id][S];

  
  if (S - value[id] >= 0) 
    ans = max(knapsack(id + 1, S), value[id] + knapsack(id + 1, S - value[id]));
  memo[id][S] = ans;

  return ans;
}

int main(int argc, char *argv[])
{
  int tc;
  int inp;
  int n;
  int total;

  scanf("%d\n", &tc);
  while (tc--) {
    scanf("%d\n", &n);
    value.clear();
    memo.clear();
    memo = tmp;
    total = 0;
    while (n--) {
      scanf("%d\n", &inp);
      value.push_back(inp);
      total += inp;
    }
    int S = (total + 1)/2;
    sort(value.begin(), value.end());
    int ans = knapsack(0, S);
    ans = abs(total - ans * 2);
    printf("%d\n", ans);
  }
  return 0;
}
