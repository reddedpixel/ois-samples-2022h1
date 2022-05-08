// CPP program for merge sorting with multithreading
#include <iostream>
#include <thread>
#include "SimpleTimer.h"
#define MAX 5000 // number of elements in the array
#define THREAD_MAX 4 // number of threads
using namespace std;

int a[MAX]; // array of size MAX

int part = 0; // variable for the thread


// merging two parts function
void merge(int low, int mid, int high)
{
	int* left = new int[mid - low + 1];
	int* right = new int[high - mid];
	// n1 is the size of the left part, and n2 is the size of the right part
	int n1 = mid - low + 1, n2 = high - mid, i, j;
	// saving the values in the left part
	for (i = 0; i < n1; i++)
		left[i] = a[i + low];
	// saving the values in the right part
	for (i = 0; i < n2; i++)
		right[i] = a[i + mid + 1];

	int k = low;
	i = j = 0;

	// combine left and right in ascending order
	while (i < n1 && j < n2) {
		if (left[i] <= right[j])
			a[k++] = left[i++];
		else
			a[k++] = right[j++];
	}

	// insert the remaining values on the left
	while (i < n1) {
		a[k++] = left[i++];
	}

	// insert the remaining values on the right
	while (j < n2) {
		a[k++] = right[j++];
	}
}


// combine sorting function
void merge_sort(int low, int high)
{
	// calculating the middle of an array
	int mid = low + (high - low) / 2;
	if (low < high) {
		// calling the first half
		merge_sort(low, mid);
		// calling the second half
		merge_sort(mid + 1, high);
		// merging the two halves
		merge(low, mid, high);
	}
}

// thread function for multithreading
void merge_sort2()
{
	// which part of the 4 parts
	int thread_part = part++;

	int low = thread_part * (MAX / THREAD_MAX);
	int high = (thread_part + 1) * (MAX / THREAD_MAX) - 1;
	// counting the middle
	int mid = low + (high - low) / 2;
	if (low < high) {
		merge_sort(low, mid);
		merge_sort(mid + 1, high);
		merge(low, mid, high);
	}
	//return;
}


int main()
{
	// Timer
	SimpleTimer timer;
	// generating random values in the array
	for (int i = 0; i < MAX; i++)
		a[i] = rand() % 100;

	cout << "Unsorted array: ";
	// Merge sort
	for (int i = 0; i<MAX; i++)
		cout << a[i] << " ";
	cout << endl;

	thread threads[THREAD_MAX];
	// creating 4 threads
	for (int i = 0; i < THREAD_MAX; i++)
		threads[i] = thread(merge_sort2);


	// waiting for all the threads finished
	for (int i = 0; i < THREAD_MAX; i++)
		threads[i].join();

	// merging the last 4 parts
	merge(0, (MAX / 2 - 1) / 2, MAX / 2 - 1);
	merge(MAX / 2, MAX / 2 + (MAX - 1 - MAX / 2) / 2, MAX - 1);
	merge(0, (MAX - 1) / 2, MAX - 1);

	// displaying a sorted array
	cout << "Sorted array: ";
	for (int i = 0; i < MAX; i++)
		cout << a[i] << " ";
	cout << endl;
	return 0;
}