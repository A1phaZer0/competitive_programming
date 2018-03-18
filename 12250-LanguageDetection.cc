#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
  char en[15] = "HELLO";
  char sp[15] = "HOLA";
  char ge[15] = "HALLO";
  char fr[15] = "BONJOUR";
  char it[15] = "CIAO";
  char ru[15] = "ZDRAVSTVUJTE";
  char hi[15];
  int n = 1;

  scanf("%s\n", hi);
  while (strcmp(hi, "#")) {
    if (strcmp(hi, en) == 0)
      printf("Case %d: %s\n", n++, "ENGLISH");
    else if (strcmp(hi, sp) == 0)
      printf("Case %d: %s\n", n++, "SPANISH");
    else if (strcmp(hi, ge) == 0)
      printf("Case %d: %s\n", n++, "GERMAN");
    else if (strcmp(hi, fr) == 0)
      printf("Case %d: %s\n", n++, "FRENCH");
    else if (strcmp(hi, it) == 0)
      printf("Case %d: %s\n", n++, "ITALIAN");
    else if (strcmp(hi, ru) == 0)
      printf("Case %d: %s\n", n++, "RUSSIAN");
    else
      printf("Case %d: %s\n", n++, "UNKNOWN");
    scanf("%s\n", hi);
  }
  return 0;
}
