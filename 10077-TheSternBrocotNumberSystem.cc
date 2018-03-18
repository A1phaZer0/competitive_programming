#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
  int m, n;
  int leftm, leftn;
  int rightm, rightn;
  int currm, currn;
  int i;
  vector<char> vc;

  while (scanf("%d %d", &m, &n) && (m != 1 || n != 1)) {
    currm = currn = 1;
    leftm = 0;
    leftn = 1;
    rightm = 1;
    rightn = 0;
    vc.clear();
    while (1) {
      if (currm == m && currn == n) {
        break;
      }
      if (currm * n > currn * m) {
        vc.push_back('L');
        rightm = currm;
        rightn = currn;
        currm += leftm;
        currn += leftn;
      } else if (currm * n < currn * m) {
        vc.push_back('R');
        leftm = currm;
        leftn = currn;
        currm += rightm;
        currn += rightn;
      } 
    }
    for (i = 0; i < (int)vc.size(); i++)
      printf("%c",vc[i]);
    printf("\n");
  }
  return 0;
}
