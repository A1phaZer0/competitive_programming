#include <stdio.h>
#include <stdlib.h>

void max_heapify(int *heap, int i,  int n)
{
	int l;
	int r;
	int t;
	int tmp;

	while (1) {
		l = 2*i;
		r = 2*i + 1;
		t = i;
		if (l <= n && heap[i] < heap[l]) {
			t = l;
		} 
		if (r <= n && heap[t] < heap[r]) {
			t = r;
		}
		if (t == i) // already heapified
			break;

		tmp = heap[t];
		heap[t] = heap[i];
		heap[i] = tmp;

		i = t;
	}
}

void buildheap(int *heap, int n)
{
	int i;

	for (i = n / 2; i >= 1; i--) {
		max_heapify(heap, i, n);
	}
}



int main(int argc, char *argv[])
{
	int n;
	int *heap;
	int i;
	int inp;
	int tmp;

	scanf("%d\n", &n);
	printf("%d\n", n);
	heap = (int *)malloc(sizeof(*heap) * (n+1));
	for (i = 0; i < n; i++) {
		scanf("%d", &inp);
		printf("%d ", inp);
		heap[i+1] = inp;
	}
	printf("\n");
	buildheap(heap, n);
	for (i = 0; i < n; i++) {
		tmp = heap[1];
		heap[1] = heap[n - i];
		heap[n - i] = tmp;
		max_heapify(heap, 1, n - i - 1);
	}
	for (i = 1; i <= n; i++)
		printf("%d ", heap[i]);
	printf("\n");
	return 0;
}
