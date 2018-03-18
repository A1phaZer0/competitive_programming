#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[]) 
{
  int L, H, R;
  int i;
  int pre;
  int min, max;
  int flag = 0;
  vector<int> v(10001, 0);

  min = 50010;
  max = 0;
  while (scanf("%d %d %d\n", &L, &H, &R) != EOF) {
    for (i = L; i < R; i++) 
      if (v[i] < H)
        v[i] = H;
    if (L < min)
      min = L;
    if (R > max)
      max = R;
  }
  pre = 0;
  for (i = min; i <= max; i++) {
    if (v[i] != pre) {
      if (flag++)
        printf(" ");
      printf("%d %d", i, v[i]);
      pre = v[i];
    }
  }
  printf("\n");

  return 0;
}
