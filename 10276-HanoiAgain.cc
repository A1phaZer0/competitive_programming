#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>

using namespace std;

int N;
int pegs[50];
int MAX;


int check(int num)
{
  double x = sqrt(num);
  if (floor(x+0.5) == x)
    return 1;
  return 0;
}

void backtrack(int num)
{
  int i;

  for (i = 0; i < N; i++) {
    if (check(pegs[i] + num) || pegs[i] == -1) {
      pegs[i] = num;
      if (num > MAX)
        MAX = num;
      backtrack(num + 1);
      break;
    }
  }
}

int main(int argc, char *argv[])
{
  int T;
  int i;

  scanf("%d\n", &T);
  while (T--) {
    MAX = 0;
    scanf("%d", &N);
    for (i = 0; i < N; i++)
      pegs[i] = -1;
    backtrack(1);
    printf("%d\n", MAX);
  }

  return 0;
}
