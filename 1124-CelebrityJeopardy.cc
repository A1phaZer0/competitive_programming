#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
  char a[100];
  char c;
  int i = 0;

  while ((c = getchar()) != EOF) {
    if (c != '\n') {
      a[i++] = c;
    } else {
      a[i] = '\0';
      i = 0;
      printf("%s\n", a);
    }
  }

  return 0;
}
