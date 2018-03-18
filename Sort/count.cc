#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
  int a;
  vector<int> vi;
  vector<int> aux;
  vector<int> out;
  int i;
  int j;
  int tmp;
  int max;
  int n;

  scanf("%d\n", &n);
  vi.resize(n);
  out.resize(n);
  max = 0;
  for (i = 0; i < n; i++) {
    scanf("%d", &a);
    printf("%d ", a);
    vi[i] = a;
    if (a > max)
      max = a;
  }
  printf("\n");

  aux.resize(max + 1);
  for (i = 0; i <= max; i++)
    aux[i] = 0;
  for (i = 0; i < n; i++) {
    aux[vi[i]]++;
  }
  for (i = 1; i <= max; i++) 
    aux[i] += aux[i-1];
  
  for (i = 0; i < n; i++) {
    out[aux[vi[i]] - 1] = vi[i];
    aux[vi[i]]--;
  }

  for (i = 0; i < n; i++)
    printf("%d ", out[i]);
  printf("\n");

  return 0;
}
