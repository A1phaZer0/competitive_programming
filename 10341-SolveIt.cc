#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int p, q, r, s, t, u;

double func(double x)
{
  return p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u; 
}



int main(int argc, char *argv[])
{
  vector<double> vd;
  vector<double>::iterator it;
  double i;
  int lo, hi, mid;
  double f;
  int ans;
  int flag = 0;

  for (i = 0.0000; i <= 1.0000; i += 0.0001) {
    vd.push_back(i);
  }

  while (scanf("%d %d %d %d %d %d", &p, &q, &r, &s, &t, &u) != EOF) {
    lo = 0;
    hi = 10000;
    flag = 0;
    if (func(0) > 0 && func(1) > 0) {
      printf("No solution\n");
      continue;
    } 
    if (func(0) < 0 && func(1) < 0) {
      printf("No solution\n");
      continue;
    }
    while (lo <= hi) {
      mid = lo + (hi - lo) / 2;
      f = func(vd[mid]);
      if (f > 0)
        lo = mid + 1;
      else if (f < 0)
        hi = mid - 1;
      else
        break;
    }
    if (abs(func(vd[mid])) < 0.01) {
      ans = mid;
      if (mid > 0)
        ans = abs(func(vd[mid])) > abs(func(vd[mid-1])) ? mid - 1 : mid;
      if (mid < 10000)
        ans = abs(func(vd[ans])) > abs(func(vd[mid+1])) ? mid + 1 : ans; 
        printf("%.4lf\n",  vd[ans]);
    } else {
      printf("No solution\n");
    }
  }
    
  return 0;
}
