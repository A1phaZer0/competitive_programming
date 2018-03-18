#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
  int n;
  char s[6];

  scanf("%d\n", &n);
  while (n--) {
    scanf("%s\n", s);
    if (strlen(s) == 5) 
      printf("3\n");
    else {
      if ((abs(s[0] - 'o') > 0) + (abs(s[1] - 'n') > 0) + (abs(s[2] - 'e') > 0) <= 1)
        printf("1\n");
      else
        printf("2\n");
    }
  }
  return 0;
}
