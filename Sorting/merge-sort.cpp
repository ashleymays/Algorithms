/*
	Merge Sort

	Time Complexity: O(n log(n))
	Space Complexity: O(n) due to the creation of the smaller sub-arrays

*/



#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;


void merge(vector<int>& arr, int start, int mid, int end)
{
	int size1 = mid - start + 1;
	int size2 = end - mid;
	vector<int> a1 (size1);				// Create two sub-arrays
	vector<int> a2 (size2);

	for (int i = 0; i < size1; ++i) 		// Initialize the sub-arrays
	{
		a1[i] = arr[i + start];				// arr starts at "i + start" the origianl t
	}										// array doesn't always start at inedx 0 due to
	for (int j = 0; j < size2; ++j)			// the recursive function, you have to
	{
		a2[j] = arr[j + mid + 1];
	}

	int i1 = 0;
	int i2 = 0;
	int i3 = start;

	while (i1 < size1 && i2 < size2) 		// Sort and merge the sub-arrays
	{
		if (a1[i1] < a2[i2])				// If sub-array "a1" has a smaller value
		{									// than sub-array "a2", then put the value
			arr[i3] = a1[i1];				// from "a1" in the original array
			++i1;
		}
		else								// Else, put the value from "a2" into
		{									// the original array
			arr[i3] = a2[i2];
			++i2;
		}
		++i3;
	}

	while (i1 < size1)					// Add any remaining elements from array "a1"
	{									// to the original array, if any
		arr[i3] = a1[i1];
		++i1;
		++i3;
	}

	while (i2 < size2)					// Add any remaining elements from array "a1"
	{									// to the original array, if any
		arr[i3] = a2[i2];
		++i2;
		++i3;
	}
}



void mergeSort(vector<int>& arr, int start, int end)
{
	if (start < end)
	{
		int mid = (start + end) / 2;
		mergeSort(arr, start, mid);
		mergeSort(arr, mid + 1, end);
		merge(arr, start, mid, end);
	}
}



// Start the algorithm
void mergeSort(vector<int>& arr)
{
	mergeSort(arr, 0, arr.size() - 1);
}



// Display the elements in the array
void display(const vector<int>& arr)
{
	for (int i = 0; i < arr.size(); ++i)
	{
		cout << arr[i] << ' ';
	}
	cout << endl;
}


// Initialize array
void init(vector<int>& arr)
{
	srand(time(NULL));
	for (int i = 0; i < arr.size(); ++i)
	{
		arr[i] = rand() % (arr.size() * 5);
	}
}



int main() {
	int size;
	cout << "Enter size of the array: ";
	cin >> size;
	cout << endl;

	vector<int> arr(size);

	init(arr);
	display(arr);
	mergeSort(arr);
	display(arr);

	return 0;
}