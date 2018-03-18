#include <cstdio>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
  int tc, T;
  int i;
  char command[100001];
  int mem[100];
  int ptr;

  scanf("%d\n", &tc);
  T = tc;
  while (tc--) {
    ptr = 0;
    scanf("%s\n", command);
    for (i = 0; i < 100; i++) 
      mem[i] = 0;
    for (i = 0; command[i] != '\0'; i++) {
      switch(command[i]) {
        case '.':
          break;
        case '+':
          mem[ptr] = (mem[ptr] + 1 + 256) % 256;
          break;
        case '-':
          mem[ptr] = (mem[ptr] - 1 + 256) % 256;
          break;
        case '>':
          ptr = (ptr + 1 + 100) % 100;
          break;
        case '<':
          ptr = (ptr - 1 + 100) % 100;
          break;
        default:
          break;
      }
    }

    printf("Case %d:", T - tc);

    for (i = 0; i < 100; i++)
      printf(" %.2X", mem[i]);
    printf("\n");
  }


  return 0;
}
