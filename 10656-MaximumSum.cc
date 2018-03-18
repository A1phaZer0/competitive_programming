#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
  int n;
  int i, inp;
  vector<int> vi;
  int count;
  
  while (scanf("%d", &n) && n) {
    vi.clear();
    count = 0;
    for (i = 0; i < n; i++) {
      scanf("%d", &inp);
      if (inp) {
        count++;
        if (count > 1)
          printf(" %d", inp);
        else
          printf("%d", inp);
      }
    }
    if (!count)
      printf("0\n");
    else
      printf("\n");
  }
  return 0;
}
