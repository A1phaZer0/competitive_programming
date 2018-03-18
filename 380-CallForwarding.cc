#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>

using namespace std;

int forwards[100][5];
int N;

void backtrack(int time, int ext)
{
  int i;
  int flag = 0;
  for (i = 0; i < N; i++) {
    if (forwards[i][0] == ext && time >= forwards[i][1] &&
       time <= forwards[i][1]+forwards[i][2]) {
      if (!forwards[i][4]) {
        flag = 1;
        forwards[i][4] = 1; // visited;
        backtrack(time, forwards[i][3]); 
        forwards[i][4] = 0;
      } else {
        ext = 9999;
      }
      break;
    }
  }
  if (!flag)
    printf("%04d\n", ext);
}



int main(int argc, char *argv[])
{
  int tc;
  int s;
  int i;
  int n = 1;
  int time, ext;
  

  scanf("%d\n", &tc);
  printf("CALL FORWARDING OUTPUT\n");
  while (tc--) {
    printf("SYSTEM %d\n", n++);
    N = 0;
    while (scanf("%d", &s) && s) {
      forwards[N][0] = s;
      forwards[N][4] = 0; // unvisited
      for (i = 1; i < 4; i++) 
        scanf("%d", forwards[N]+i);
      N++;
    }
    while (scanf("%d", &time) && time != 9000) {
      scanf("%d", &ext);
      printf("AT %04d CALL TO %04d RINGS ", time, ext);
      backtrack(time, ext);
    }
  }
  printf("END OF OUTPUT\n");
  return 0;
}
