#include <cstdio>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
  double H, U, D, F, h;
  double init;
  int n;

  while (1) {
    scanf("%lf %lf %lf %lf\n", &H, &U, &D, &F);
    init = U;
    if (!H)
      break;
    n = 1;
    h = .0;

    while (1) {
      if (h + U - D < 0) {
        printf("failure on day %d\n", n);
        break;
      } else if (h + U > H) {
        printf("success on day %d\n", n);
        break;
      } else {
        h += U - D;
      }
      U -=  init* F/100;
      if (U < 0)
        U = 0;
      n++;
    }
  }
  return 0;
}
