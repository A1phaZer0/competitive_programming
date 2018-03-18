#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

void merge(vector<int> &v, int start, int mid, int end)
{
  vector<int> a;
  int i;
  int p, q, k;

  p = start;
  q = mid + 1;

  a.resize(end - start + 1);
  k = 0;
  for (i = start; i <= end; i++) {
    if (p > mid)
      a[k++] = v[q++]; 
    else if (q > end)
      a[k++] = v[p++];
    else if (v[p] < v[q]) 
      a[k++] = v[p++];
    else
      a[k++] = v[q++];
  }

  for (i = start; i <= end; i++) 
    v[i] = a[i - start];
}

void merge_sort(vector<int> &v, int start, int end)
{
  int mid;
  if (start < end) {
    mid = start + (end - start) / 2;
    merge_sort(v, start, mid);
    merge_sort(v, mid+1, end);
    merge(v, start, mid, end);
  }
}


  
int main(int argc, char *argv[])
{
  int a;
  vector<int> vi;
  int i;
  int j;
  int tmp;
  int n;

  scanf("%d\n", &n);
  vi.resize(n);
  for (i = 0; i < n; i++) {
    scanf("%d", &a);
    printf("%d ", a);
    vi[i] = a;
  }
  printf("\n");

  merge_sort(vi, 0, n - 1);

  for (i = 0; i < n; i++)
    printf("%d ", vi[i]);
  printf("\n");

  return 0;
}
