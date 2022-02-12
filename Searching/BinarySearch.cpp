/*
	Binary Search (both iterative and recursive versions)

	Purpose(s): find elements in a sorted list

	Time Complexity: O(log n)
	Space Complexity:
		- Iterative Version: O(1)
		- Recursive Version: O(log n)
*/


#include <iostream>
#include <vector>
using namespace std;




// Iterative Version

int binarySearch(const vector<int>& arr, int value)
{
	int l = 0;
	int r = arr.size() - 1;
	int mid;

	while (l <= r)
	{
		mid = (l + r) / 2;

		// value was found -> return index mid
		if (value == arr[mid])
		{
			return mid;
		}

		// value is in the lower half of the array -> move r to cut the search interval 
		// in half (subtract 1 to avoid infinite loop that can happen when we're searching
		// for elements at the ends of the array)
		else if (value < arr[mid])
		{
			r = mid - 1;
		}

		// value is in the upper half of the array -> move l to cut the search interval in 
		// half (add 1 to avoid infinite loop that can happen when we're searching
		// for elements at the ends of the array)
		else
		{
			l = mid + 1;
		}
	}
	return -1;
}




// Recursive Version

int binarySearch(const vector<int>& arr, int value, int l, int r)
{
	int mid = (l + r) / 2;

	// value was found -> return index mid
	if (value == arr[mid])
	{
		return mid;
	}

	// if l and r cross, then we're done searching
	else if (l > r)
	{
		return -1;
	}

	// value is in the lower half of the array -> change r to cut the search interval 
	// in half (subtract 1 to avoid infinite loop that can happen when we're searching
	// for elements at the ends of the array)
	else if (value < arr[mid])
	{
		return binarySearch(arr, value, l, mid - 1);
	}

	// value is in the upper half of the array -> change l to cut the search interval
	// in half (add 1 to avoid infinite loop that can happen when we're searching
	// for elements at the ends of the array)
	else
	{
		return binarySearch(arr, value, mid + 1, r);
	}
}



int main()
{
	vector<int> arr = { 1, 4, 14, 16, 72, 452 };

	cout << binarySearch(arr, 15) << endl;		// Iterative Ver.
	cout << binarySearch(arr, 15, 0, arr.size() - 1);	// Recursive Ver.

	return 0;
}