#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
  int L;
  int i;
  char dir[3];
  int xyz;
  enum {XP, XN, YP, YN, ZP, ZN};



  while (scanf("%d\n", &L) && L) {
    xyz = XP; // parallel or not

    for (i = 1; i <= L - 1; i++) {
      scanf("%s", dir);
      if (!strcmp(dir, "+z")) {
        switch(xyz) {
          case XP:
            xyz = ZP;
            break;
          case XN:
            xyz = ZN;
            break;
          case ZP:
            xyz = XN;
            break;
          case ZN:
            xyz = XP;
            break;
          default: break;
        }
      } else if (!strcmp(dir, "-z")) {
        switch(xyz) {
          case XP:
            xyz = ZN;
            break;
          case XN:
            xyz = ZP;
            break;
          case ZP:
            xyz = XP;
            break;
          case ZN:
            xyz = XN;
          default:
            break;
        }
      } else if (!strcmp(dir, "+y")) {
        switch(xyz) {
          case XP:
            xyz = YP;
            break;
          case XN:
            xyz = YN;
            break;
          case YP:
            xyz = XN;
            break;
          case YN:
            xyz = XP;
            break;
          default:
            break;
        }
      } else if (!strcmp(dir, "-y")) {
        switch(xyz) {
          case XP:
            xyz = YN;
            break;
          case XN:
            xyz = YP;
            break;
          case YP:
            xyz = XP;
            break;
          case YN:
            xyz = XN;
            break;
          default:
            break;
        }
      } else
        ;
    }
    if (xyz == XP)
      printf("+x\n");
    else if (xyz == XN)
      printf("-x\n");
    else if (xyz == YP)
      printf("+y\n");
    else if (xyz ==  YN)
      printf("-y\n");
    else if (xyz == ZP)
      printf("+z\n");
    else 
      printf("-z\n");
  }

  return 0;
}
