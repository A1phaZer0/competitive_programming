#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
  int c;
  int n = 0;

  while ((c = getchar()) != EOF) {
    if (c == '\"') {
      if (n % 2 == 0) {
        putchar('`');
        putchar('`');
      } else {
        putchar('\'');
        putchar('\'');
      }
      n++;
    } else {
      putchar(c);
    }
  }
}

