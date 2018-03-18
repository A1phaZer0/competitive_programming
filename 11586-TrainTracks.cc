#include <cstdio>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
  int tc;
  int M, F;
  char c;

  scanf("%d\n", &tc);
  while (tc--) {
    M = F = 0;
    while ((c = getchar()) != '\n') {
      if (c == 'M')
        M++;
      if (c == 'F')
        F++;
    }
    if (M == F && M != 1)
      printf("LOOP\n");
    else
      printf("NO LOOP\n");
  }

  return 0;
}
