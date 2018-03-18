#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
  int i = 1;
  char s[6];
  char h[6] = "Hajj";

  scanf("%s", s);
  while (strcmp(s, "*")) {
    if (!strcmp(s, h)) {
      printf("Case %d: Hajj-e-Akbar\n", i++);
    } else {
      printf("Case %d: Hajj-e-Asghar\n", i++);
    }
    scanf("%s", s);
  }

  return 0;
}
