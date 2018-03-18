#include <cstdio>
#include <algorithm>

using namespace std;

int main (int argc, char *argv[])
{
  int np, b, nh, nw;
  int price;
  int bn;
  int mina;
  int s;
  int i, j;

  s = scanf("%d %d %d %d\n", &np, &b, &nh, &nw);
  while (s != EOF) {
    mina = b + 1;
    for (j = 0; j < nh; j++) {
      scanf("%d\n", &price);
      for (i = 0; i < nw; i++) {
        scanf("%d", &bn);
        
        if ((bn >= np) && (np * price < mina))
          mina = np * price;
      }
    }
    if (mina <= b)
      printf("%d\n", mina);
    else
      printf("stay home\n");
    s = scanf("%d %d %d %d\n", &np, &b, &nh, &nw);
  }
  return 0;
}
