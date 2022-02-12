/*
	Selection Sort

	Time Complexity: O(n^2)
	Space Complexity: O(1)
*/


#include <iostream>
#include <vector>
#include <cstdlib>

void selectionSort(std::vector<int>& vec)
{
	int min, tmp;
	for (int i = 0; i < vec.size() - 1; ++i)
	{
		// assume that the minimum is at index i
		min = i;

		// read the sub-array that consists of all the elements after the one at index i
		for (int j = i + 1; j < vec.size(); ++j)
		{
			// if there is an element at index j that is smaller than the one at index i, we re-assign min
			if (vec[min] > vec[j])
			{
				min = j;
			}
		}

		// swap the elements so that the smaller element gets moved to its correct position in the array
		tmp = vec[min];
		vec[min] = vec[i];
		vec[i] = tmp;
	}
}


// display the elements in the array
void display(const std::vector<int>& vec)
{
	for (int i = 0; i < vec.size(); ++i)
	{
		std::cout << vec[i] << ' ';
	}
	std::cout << std::endl;
}



int main()
{
	srand(time(NULL));
	std::vector<int> vec;

	for (int i = 0; i < 5; ++i)
	{
		vec.push_back(rand() % 25);
	}

	display(vec);
	selectionSort(vec);
	display(vec);

	return 0;
}