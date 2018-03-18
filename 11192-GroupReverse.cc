#include <cstdio>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
  char s[101];
  string s1;
  int g;
  int i, j;

  while (scanf("%d", &g) && g) {
    scanf("%s\n", s);
    s1 = s;
    for (j = 0; j <= s1.length() - s1.length() / g; j += s1.length() / g) {
      for (i = j + s1.length() / g - 1; i >= j; i--)
        printf("%c", s[i]);
    }
    printf("\n");
  }
  return 0;
}
