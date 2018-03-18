#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int *order;
int *stu;
int memo[20];

int dp(int i)
{
  int j;
  int max;
  int val;

  if (!i) 
    memo[i] = 1;

  max = 0;
  for (j = 0; j < i; j++) {
    val = dp(j) + 1;
    if (stu[j] < stu[i] && val > max) {
      max = val;
      memo[i] = val;
    }
  }
  if (!memo[i])
    memo[i] = 1;

  return memo[i];
}

void bottomup(int N)
{
  int i, j;
  for (i = 0; i < N; i++) {
    for (j = 0; j < i; j++) {
      if (stu[j] < stu[i] && memo[j] + 1 > memo[i])
        memo[i] = memo[j] + 1;
    }
    if (!memo[i])
      memo[i] = 1;
  }
}

int main(int argc, char *argv[])
{
  int N;
  int i, j;
  int inp;
  int max;

  scanf("%d\n", &N);
  order = (int *)malloc(sizeof(int) * N);
  stu = (int *)malloc(sizeof(int) * N);

  for (i = 0; i < N; i++) {
    scanf("%d", &inp);
    order[inp-1] = i;
  }
  while (scanf("%d", &inp) != EOF) {
    max = 0;
    stu[inp-1] = 0;
    memset(memo, 0, 20*sizeof(int));
    for (i = 1; i < N; i++) {
      scanf("%d", &inp);
      stu[inp-1] = i;
    }

    for (i = 0; i < N; i++) {
      for (j = 0; j < N; j++) {
        if (stu[i] == order[j]) {
          stu[i] = j;
          break;
        }
      }
    }

    //dp(N-1);
    bottomup(N);
    for (i = 0; i < N; i++)
      if (memo[i] > max) {
        max = memo[i];
      }

    printf("%d\n", max);
  }
  return 0;
}
