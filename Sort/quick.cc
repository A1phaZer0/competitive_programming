#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int partition(vector<int> &v, int start, int end)
{
  int i, j;
  int piv;
  int tmp;

  i = start + 1;
  piv = v[start];

  for (j = start + 1; j <= end; j++) {
    if (v[j] < piv) {
      tmp = v[j];
      v[j] = v[i];
      v[i] = tmp;
      i++;
    }
  }
  tmp = v[i-1];
  v[i-1] = v[start];
  v[start] = tmp;

  return i - 1;
}

void quick_sort(vector<int> &v, int start, int end)
{
  int piv;
  if (start < end) {
    piv = partition(v, start, end);
    quick_sort(v, start, piv - 1);
    quick_sort(v, piv + 1, end);
  }
}

  
int main(int argc, char *argv[])
{
  int a;
  vector<int> vi;
  int i;
  int n;

  scanf("%d\n", &n);
  vi.resize(n);
  for (i = 0; i < n; i++) {
    scanf("%d", &a);
    printf("%d ", a);
    vi[i] = a;
  }
  printf("\n");

  quick_sort(vi, 0, n - 1);

  for (i = 0; i < n; i++)
    printf("%d ", vi[i]);
  printf("\n");

  return 0;
}
