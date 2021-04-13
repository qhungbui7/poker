#include"additionalFunction.h"
int left(int i) {
	return 2 * i; 
}
int right(int i) {
	return 2 * i + 1;
}
void swap(handTracer& x, handTracer& y) {
	handTracer z = x; 
	x = y; 
	y = z;
	return; 
}
void minHeapfy(int i, int limHeap, handTracer *arr) { // parent must be smaller than right & left child
	int l = left(i), r = right(i), smallest = i;
	if (arr[smallest].val > arr[l].val && l <= limHeap) { // check if there is a disorder
		smallest = l; 
	}
	if (arr[smallest].val > arr[r].val && r <= limHeap) { // check if there is a disorder, get the smallest 
		smallest = r;							// to satisfies the left and the right order
	}
	if (smallest != i) {
		swap(arr[smallest], arr[i]);
		minHeapfy(smallest, limHeap, arr); 
	}
}
void buildMinHeap(int limHeap, handTracer *arr) {
	for (int i = limHeap / 2; i >= 0; i--) { // run to limHeap / 2 beacause if it more than limHeap / 2 it's a leaf
		minHeapfy(i, limHeap, arr);  // run from back to front for less move 
	}
}
void heapSort(handTracer *arr, int n) {
	int limHeap = n - 1;
	int lim = limHeap;
	buildMinHeap(limHeap, arr);
	for (int i = limHeap; i > 0; i--) {
		swap(arr[i], arr[0]); // put the minimum at the moment to the back of array
		lim--; 
		minHeapfy(0,lim,arr); // re-heapfy the heaptree
	}
}