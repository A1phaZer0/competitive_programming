#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int cal(int i)
{
  return (i+1)/2;
}

int main(int argc, char *argv[])
{
  int D, I;
  int tc;
  int v, d;
  int i;

  scanf("%d\n", &tc);
  while (tc--) {
    scanf("%d %d\n", &D, &I);
    v = 1; //current node
    d = 1; //current depth
    for (d = 1; d < D; d++) {
      if (I % 2 == 0) 
        v = v*2 + 1;
      else
        v = v*2;
      I = cal(I);
    }
    printf("%d\n", v);
  }
  return 0;
}
