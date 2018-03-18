#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

int range(int v)
{
  int i = 0;

  while (v) {
    v /= 10;
    i++;
  }

  return i;
}

int main(int argc, char *argv[])
{
  int sum = 0;
  int i = 1;
  vector<int> s;

  s.push_back(0);
  while (sum < 2147483647) {
    s.push_back(s[i-1]+range(i));
    sum += s[i];
    i++;
  }
  printf("%d", i);
  return 0;
}
