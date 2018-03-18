#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>

using namespace std;

int D, N;
int dur[20];
int MIN;
int NUM;
int SUM;
int mindur[20];
int visited[20];
int flag;


int backtrack(int sum, int track, int j)
{

  int flag = 0;
  int i;
  int a = 8888;
  int ret[N];

  for (i = track; i < N; i++) 
    if (sum + dur[i] <= D)
      flag = 1;

  if (!flag) {
    if (D - sum < MIN) {
      MIN = D - sum;
      NUM = j;
      SUM = sum;
    }
    return sum;
  }

  if (flag) {
    for (i = track; i < N; i++) {
      if (sum + dur[i] <= D) 
        ret[i] = backtrack(sum + dur[i], i+1, j+1);
    }
    for (i = track; i < N; i++) {
      if (sum + dur[i] <= D) {
        if (D - ret[i] == MIN) {
          a = ret[i];
          if (!visited[j]) {
            mindur[j] = dur[i];
            visited[j] = 1;
          }
          break;
        }
      }
    }
  }

  return a;
}


int main(int argc, char *argv[])
{
  int i;
  int flag = 0;

  while (scanf("%d %d", &D, &N) != EOF) {
    if (flag++)
      printf("\n");
    MIN = D;
    for (i = 0; i < N; i++)
      scanf("%d", dur+i);
    for (i = 0; i < N; i++) {
      mindur[i] = 0;
      visited[i] = 0;
    }
    backtrack(0, 0, 0);
    for (i = 0; i < NUM; i++)
      printf("%d ", mindur[i]);
    printf("sum:%d", SUM);
  }
  return 0;
}
