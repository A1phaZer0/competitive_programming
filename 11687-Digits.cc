#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
  char m[1000001];
  string s;
  int j;
  unsigned int l, len;

  while (scanf("%s", m) && m[0] != 'E') {
    s = m;
    j = 1;
    l = s.length();
    while (1) {
      if (l == 1 && m[0] == '1') {
        printf("1\n");
        break;
      }
      if (l == 1 && m[0] != '1') {
        printf("2\n");
        break;
      }
      len = 0;
      while (l) {
        l /= 10;
        len++;
      }
      if (len == 1) {
        printf("%d\n", j + 2);
        break;
      }
      l = len;
      j++;
    }
  }
  return 0;
}
