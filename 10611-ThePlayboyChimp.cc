#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
  vector<unsigned int> vui;
  vector<unsigned int>::iterator it;
  int N, Q;
  unsigned int inp;
  int i;

  scanf("%d\n", &N);
  for (i = 0; i < N; i++) {
    scanf("%u", &inp);
    vui.push_back(inp);
  }
  scanf("%d\n", &Q);
  while (Q--) {
    scanf("%d", &inp);
    it = lower_bound(vui.begin(), vui.end(), inp);
    if (it == vui.begin())
      printf("X ");
    else
      printf("%u ", *(it-1));
    it = upper_bound(vui.begin(), vui.end(), inp);
    if (it == vui.end())
      printf("X");
    else
      printf("%u", *it);
    printf("\n");
  }
  return 0;
}
