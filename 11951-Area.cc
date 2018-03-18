#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
  long long N, M, K;
  int i, j, k, g;
  int tc;
  int c = 1;
  long long max_area, max_area_price;
  long long mat[100][100];
  long long sum;

  scanf("%d\n", &tc);
  while (tc--) {
    scanf("%lld %lld %lld", &N, &M, &K);
    for (i = 0; i < (int)N; i++) {
      for (j = 0; j < (int)M; j++) {
        scanf("%lld", mat[i]+j);
        if (i)
          mat[i][j] += mat[i-1][j];
        if (j)
          mat[i][j] += mat[i][j-1];
        if (i && j)
          mat[i][j] -= mat[i-1][j-1];
      }
    }
    max_area = 0;
    max_area_price = 10E16;
    for (i = 0; i < (int)N; i++) {
      for (j = 0; j < (int)M; j++) {
        for (k = i; k < (int)N; k++) {
          for (g = j; g < (int)M; g++) {
            sum = mat[k][g];
            if (j)
              sum -= mat[k][j-1];
            if (i)
              sum -= mat[i-1][g];
            if (i && j)
              sum += mat[i-1][j-1];
            if ((sum <= K && (k-i+1)*(g-j+1) > max_area) || ((k-i+1)*(g-j+1) == max_area && sum < max_area_price)) {
              max_area = (k-i+1)*(g-j+1);
              max_area_price = sum;
            }
          }
        }
      }
    }
    printf("Case #%d: %lld %lld\n", c++, max_area,max_area?max_area_price:0);
  }
  return 0;
}
