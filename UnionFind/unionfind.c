#include <stdio.h>
#include <stdlib.h>

int root(int *arr, int a)
{
	while (arr[a] != a) {
		a = arr[arr[a]];
	}
	return a;
}

int find(int *arr, int a, int b)
{
	if (root(arr, a) == root(arr, b))
		return 1;
	else
		return 0;
}

void unionm(int *arr, int *size, int a, int b)
{
	int root_a = root(arr, a);
	int root_b = root(arr, b);
	int size_a = size[root_a];
	int size_b = size[root_b];

	if (size_a > size_b) {
		arr[root_b] = root_a;
		size[root_a] += size[root_b];
	} else {
		arr[root_a] = root_b;
		size[root_b] += size[root_a];
	}
}

int main(int argc, char *argv[])
{
	int n, m;
	int a, b;
	int *size;
	int *arr;
	int i;

	scanf("%d %d\n", &n, &m);
	size = (int *)malloc(sizeof(*size)*n);
	arr = (int *)malloc(sizeof(*size)*n);

	for (i = 0; i < n; i++) {
		size[i] = 1;
		arr[i] = i;
	}

	for (i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		unionm(arr, size, a, b);
	}

	for (i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	for (i = 0; i < n; i++) {
		printf("%d ", size[i]);
	}
	printf("\n");

	for (i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		if (find(arr, a, b)) {
			printf("%d %d: connected\n", a, b);
		} else {
			printf("%d %d: not connected\n", a, b);
		}
	}

	return 0;
}
