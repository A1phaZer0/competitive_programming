#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
  string s;
  int n;

  scanf("%d\n", &n);
  while (n--) {
    cin >> s;
    if (s == "1" || s == "4" || s == "78") {
      printf("+\n");
    } else {
      if (s[s.length() - 1] == '5' && s[s.length() - 2] == '3') {
        printf("-\n");
      } else if (s[s.length() - 1] == '4' && s[0] == '9') {
        printf("*\n");
      } else {
        printf("?\n");
      }
    }
  }
  return 0;
}
