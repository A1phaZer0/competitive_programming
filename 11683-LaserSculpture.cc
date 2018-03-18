#include <cstdio>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
  int H, L;
  int i, j;
  int a[10000];
  int max;
  int ans;
  int flag;


  while (scanf("%d %d\n", &H, &L) && H) {
    max = 0;
    ans = 0;
    for (i = 0; i < L; i++) { 
      scanf("%d", a + i);
      if (a[i] > max)
        max = a[i];
    }
    ans += H - max;
    H = max;
    for (i = 0; i < max; i++) {
      flag = 0;
      for (j = 0; j < L; j++) {
        if (a[j] >= H) {
          flag = 0;
        }
        if (a[j] < H && !flag) {
          ans++;
          flag = 1;
        }
      }
      H--;
    }
    printf("%d\n", ans);
  }
  return 0;
}
