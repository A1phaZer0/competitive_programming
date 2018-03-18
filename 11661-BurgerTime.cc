#include <cstdio>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
  int L;
  char c;
  char pre;
  int p;
  int pre_p;
  int min;

  while (scanf("%d\n", &L) && L) {
    p = 0;
    pre_p = 0;
    min = 2000000;
    pre = ' ';
    while (L--) {
      c = getchar();
      p++;
      if (c == 'Z') {
        min = 0;
      } else if (c == 'R') {
        if (pre == 'D') {
          if (p - pre_p < min) 
            min = p - pre_p;
        }
        pre_p = p;
        pre = 'R';
      } else if (c == 'D') {
        if (pre == 'R') {
          if (p - pre_p < min)
            min = p - pre_p;
        }
        pre_p = p;;
        pre = 'D';
      } else
        ;
    }
    printf("%d\n", min);
  }
  return 0;
}
