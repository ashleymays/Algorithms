/*
	Selection Sort

	Time Complexity: O(n^2)
	Space Complexity: O(1)
*/


#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

void selectionSort(vector<int>& arr)
{
	int min, tmp;
	for (int i = 0; i < arr.size() - 1; ++i)
	{
		min = i;									// Assume that the minimum is at index i

		for (int j = i + 1; j < arr.size(); ++j)	// Read all the elements after the one at index i
		{

			if (arr[min] > arr[j])					// If there is an element at index j that is smaller
			{										// than the one at index i, we re-assign min
				min = j;
			}
		}

		tmp = arr[min];								// Swap the elements so that the smaller element gets 
		arr[min] = arr[i];							// moved to its correct position in the array
		arr[i] = tmp;
	}
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
		arr[i] = rand() % (arr.size() * 4);
	}
}



int main()
{
	int size;
	cout << "Enter size of the array: ";
	cin >> size;
	cout << endl;

	vector<int> arr(size);

	init(arr);
	display(arr);
	selectionSort(arr);
	display(arr);

	return 0;
}
