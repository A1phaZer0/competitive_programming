#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
  int a;
  vector<int> vi;
  int i;
  int j;
  int tmp;
  int min;
  int n;

  scanf("%d\n", &n);
  vi.resize(n);
  for (i = 0; i < n; i++) {
    scanf("%d", &a);
    printf("%d ", a);
    vi[i] = a;
  }
  printf("\n");

  for (i = 0; i < n - 1; i++) {
    min = i;
    for (j = i; j < n; j++) {
      if (vi[j] < vi[min]) {
        min = j;
      }
    }
    tmp = vi[i];
    vi[i] = vi[min];
    vi[min] = tmp;
  }



  for (i = 0; i < n; i++)
    printf("%d ", vi[i]);
  printf("\n");

  return 0;
}
