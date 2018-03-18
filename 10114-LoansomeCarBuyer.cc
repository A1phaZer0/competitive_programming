#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
  int t, n;
  double dpmt, value, loan, remain;
  double pmt; // payment
  double dpr[101];
  int m;
  int i;


  scanf("%d %lf %lf %d\n", &t, &dpmt, &loan, &n);
  while (t > 0) {
    for (i = 0; i < 101; i++)
      dpr[i] = 0; // initialize depreciate rate

    value = loan + dpmt; // initial value of car
    remain = loan; // remain of loan
    pmt = loan / t;

    for (i = 0; i < n; i++) { // month i
      scanf("%d ", &m);
      scanf("%lf\n", dpr + m);
    }

    for (i = 1; i < 101; i++)
      if (dpr[i] == 0)
        dpr[i] = dpr[i - 1]; // construct depreciate rate by month

    value *= (1 - dpr[0]); // drive off the lot

    for (i = 1; i < 102; i++) {
      if (remain >= 0 && value > remain) {
        if ((i - 1) != 1)  {
          printf("%d months\n", i - 1);
        }
        else {
          printf("1 month\n");
        }
        break;
      }
      value *= (1 - dpr[i]);
      remain -= pmt;
    }
    scanf("%d %lf %lf %d\n", &t, &dpmt, &loan, &n);
  }
  return 0;
}
