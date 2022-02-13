
/*
    Insertion Sort

    Time Complexity: O(n^2)
    Space Complexity: O(1)
*/



#include <iostream>
#include <vector>
#include <cstdlib>



void insertionSort(std::vector<int>& arr)
{
    int j, key;
    for (int i = 1; i < arr.size(); ++i)
    {
        j = i - 1;
        key = arr[i]; // save the value at index i b/c the value at index i will change during the while loop

        // exits when j is invalid or the key is larger than the lower part of the array
        while (j >= 0 && key < arr[j])
        {
            // shift the array over so that there will be space at the index where the key should be
            arr[j + 1] = arr[j];
            --j;
        }
        // put the key at the right index
        arr[j + 1] = key;
    }
}



// display the elements in the array
void display(const std::vector<int>& arr)
{
    for (int i = 0; i < arr.size(); ++i)
    {
        std::cout << arr[i] << ' ';
    }
    std::cout << std::endl;
}



int main()
{
    srand(time(NULL));
    std::vector<int> arr;

    for (int i = 0; i < 5; ++i)
    {
        arr.push_back(rand() % 25);
    }

    display(arr);
    insertionSort(arr);
    display(arr);


    return 0;
}
