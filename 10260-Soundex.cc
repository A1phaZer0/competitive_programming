#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
  char s[21];
  int i;
  int pre;

  while (scanf("%s", s) != EOF) {
    pre = -1;
    for (i = 0; s[i] != '\0'; i++) {
      switch(s[i]) {
      case 'B':
      case 'F':
      case 'P':
      case 'V': 
        if (pre == 1)
          break;
        printf("1");
        pre = 1;
        break;
      case 'C':
      case 'G':
      case 'J':
      case 'K':
      case 'Q':
      case 'S':
      case 'X':
      case 'Z': 
        if (pre == 2)
          break;
        printf("2");
        pre = 2;
        break;
      case 'D':
      case 'T': 
        if (pre == 3)
          break;
        printf("3");
        pre = 3;
        break;
      case 'L': 
        if (pre == 4)
          break;
        printf("4");
        pre = 4;
        break;
      case 'M':
      case 'N': 
        if (pre == 5)
          break;
        printf("5");
        pre = 5;
        break;
      case 'R': 
        if (pre == 6)
          break;
        printf("6");
        pre = 6;
        break;
      default: 
        pre = -1;
        break;
      }
    }
    printf("\n");
  }
  return 0;
}
