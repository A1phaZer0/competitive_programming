#include <cstdio>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
  char s[1000001];
  int n;
  int tc;
  int a, b, tmp;
  int flag, i;

  tc = 1;
  while (scanf("%s\n", s) != EOF) {
    scanf("%d\n", &n);
    printf("Case %d:\n", tc++);
    while (n--) {
      flag = 0;
      scanf("%d %d\n", &a, &b);
      if (a > b) {
        tmp = a;
        a = b;
        b = tmp;
      }
      tmp = s[a] - '0';
      for (i = a; i <= b; i++) {
        if (s[i] - '0' == tmp) 
          flag = 1;
        else {
          flag = 0;
          printf("No\n");
          break;
        }
      }
      if (flag)
        printf("Yes\n");
    } 
  }
  return 0;
}
