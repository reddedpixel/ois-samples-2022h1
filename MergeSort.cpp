/*
Merge sorting
* Complexity - N* logN
* It is impossible to sort data faster using only comparisons.One of the fastest sorts.
* The idea is to divide the array by halves and sort each half. And then by merging we get one of them.
* Merge algorithm : in each sorted array, the pointer is placed on the first element.Then compared. After than
- the smaller one goes to the beginning of the new array.In this array, the pointer is shifted.
At the end, when one pointer reaches the end of the array, just the remainder of the other array to the end.
In total, at each step we make one comparisonand write one element to the array.The complexity of the merge is the number of elements.
Now - sorting the halves. We divide it in half every time. And we divide by halves logN times.

Implementation :
	From top to bottom.A recursive function that takes the left half calls itself for it.Similarly with the right.
	Then it starts the merge process.
	From bottom to top.Merge every two adjacent elements.Then merge arrays already.

	When merging, an additional array is needed.Requires N memory.
*/

#include <iostream>
#include <vector>
using namespace std;

// takes an array, the starting position in the array and the ending position +1
void mergeSort(vector<int> &a, size_t start, size_t end)
{
	// if there are less than 2 elements (1 or 0), then you don't need to sort
	if (end - start < 2)
		return;
	// if there are 2 elements, simply swap them
	if (end - start == 2)
	{
		if (a[start] > a[start + 1])
			swap(a[start], a[start + 1]);
		return;
	}
	// divide the array into 2 parts and sort them separately
	mergeSort(a, start, start + (end - start) / 2);
	mergeSort(a, start + (end - start) / 2, end); // начинается на половину от размера массива
	// merging
	vector<int> b; // array for merging
	size_t b1 = start; // beginning of the first half
	size_t e1 = start + (end - start) / 2; // end of the first half
	size_t b2 = e1; // beginning of the second half
	// we transfer elements from array a to array b until the size of array b is equal to the number of elements being transferred
	while (b.size() < end - start)
	{
		// if b1 is out of the array or if the element in the second array is smaller than the corresponding element in the first
		if (b1 >= e1 || (b2 < end && a[b2] < a[b1]))
		{
			b.push_back(a[b2]);
			++b2;
		}
		else
		{
			b.push_back(a[b1]);
			++b1;
		}
	}
	// rewrite the result from array b back to array a
	for (size_t i = start; i < end; i++)
		a[i] = b[i - start];
}


int main()
{
	vector<int> v;
	for (int i = 0; i <= 20; i++) 
	{
		v.push_back(i);
	}
	for (size_t i = 0; i < v.size(); i++)
	{
		swap(v[i], v[rand() % (v.size() - i) + i]);
	}
	for (auto i: v)
	{
		cout << i << " ";
	}
	cout << endl;
	mergeSort(v, 0, v.size());
	for (auto i : v)
	{
		cout << i << " ";
	}
	cout << endl;
}





