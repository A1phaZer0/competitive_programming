#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
  int B, N; // banks and debentures
  int rsv[21];
  int i;
  int dbtor, crdtor, v;
  int flag;

  scanf("%d %d\n", &B, &N);
  while (1) {
    if (B == 0 && N == 0)
      break;
    flag = 0;
    for (i = 1; i <= B; i++) 
      scanf("%d", rsv + i);
    for (i = 0; i < N; i++) {
      scanf("%d %d %d\n", &dbtor, &crdtor, &v);
      rsv[dbtor] -= v;
      rsv[crdtor] += v;
    }
    for (i = 1; i <= B; i++)
      if (rsv[i] < 0) {
        printf("N\n");
        flag = 1;
        break;
      }
    if (!flag)
      printf("S\n");
    scanf("%d %d\n", &B, &N);
  }
  return 0;
}
