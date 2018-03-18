#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
  int N, S, R;
  vector<int> vi;
  int nice;
  int i;
  int sum, ans;
  int start_tmp, start, end_tmp, end;

  scanf("%d\n", &N);
  R = 1;

  while (N--) {
    scanf("%d\n", &S);
    vi.clear();
    for (i = 1; i < S; i++) {
      scanf("%d\n", &nice);
      vi.push_back(nice);
    }
    sum = 0;
    ans = 0;
    start = 0;
    start_tmp = 0;
    end = 0;
    end_tmp = 0;
    for (i = 0; i < (int)vi.size(); i++) {
      sum += vi[i];
      if (sum >= ans) {
        end_tmp = i;
        if (sum > ans || end_tmp - start_tmp > end - start) {
          start = start_tmp;
          end = i;
        }
      }
      ans = std::max(sum, ans);
      if (sum < 0) {
        sum = 0;
        start_tmp = i+1;
      }
    }
    if (ans <= 0)
      printf("Route %d has no nice parts\n", R++);
    else
      printf("The nicest part of route %d is between stops %d and %d\n", R++, start + 1, end + 2);
    
  }
  return 0;
}
