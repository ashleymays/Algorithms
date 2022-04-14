/*
	Quick Sort - Start Pivot

	Time Complexity: O(n log(n))
	Space Complexity: O(n)
*/

#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;


int partition(vector<int>& arr, int start, int end)
{
	int pivot = arr[start];									// Using the first element as the pivot
	int j = start;											// Have a counter that points to one space after 
															// where we will move the pivot at the end of the function
	int tmp;

	for (int i = start + 1; i <= end; ++i)
	{
		if (arr[i] < pivot)									// arr[i] needs to be in the first half of the array, so
		{													// update the counter, and swap the current value arr[i] with
			++j;											// arr[j] (Note: arr[j] will always point to a value larger 
			tmp = arr[i];									// than the pivot until after the for loop
			arr[i] = arr[j];
			arr[j] = tmp;
		}
	}

	tmp = arr[j];											// Now j is where the pivot element should be, so
	arr[j] = arr[start];									// swap the pivot element (arr[end]) with the one at index j
	arr[start] = tmp;

	return j;
}


void quickSort(vector<int>& arr, int start, int end)
{
	if (start < end)
	{
		int piv = partition(arr, start, end);			// Find the pivot element	
		quickSort(arr, start, piv - 1);					// Sort the elements before the pivot
		quickSort(arr, piv + 1, end);					// Sort the elements after the pivot
	}
}

// Start the algorithm
void quickSort(vector<int>& arr)
{
	quickSort(arr, 0, arr.size() - 1);
}

// Display the elements
void display(const vector<int>& arr)
{
	cout << "Data: ";
	for (int i = 0; i < arr.size(); ++i)
	{
		cout << arr[i] << ' ';
	}
	cout << endl;
}

// Initialize the array
void init(vector<int>& arr, int size)
{
	srand(time(NULL));
	for (int i = 0; i < size; ++i)
	{
		arr.push_back(rand() % (size * 4));
	}
}

int main()
{
	int size;
	cout << "Enter the size of the array: ";
	cin >> size;
	cout << endl;

	vector<int> arr;

	init(arr, size);
	display(arr);
	quickSort(arr);
	display(arr);

	return 0;
}