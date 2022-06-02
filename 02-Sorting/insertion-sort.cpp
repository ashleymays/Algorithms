
/*
    Insertion Sort

    Time Complexity: O(n^2)
    Space Complexity: O(1)
*/



#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;


void insertionSort(vector<int>& arr)
{
    int j, key;
    for (int i = 1; i < arr.size(); ++i)
    {
        j = i - 1;
        key = arr[i];

        // Exits when index j is invalid or the key is
        // larger than the lower part of the array.
        // Shift the array over so that there will be 
        // space at the index where the key should be
        while (j >= 0 && key < arr[j])
        {
            arr[j + 1] = arr[j];
            --j;
        }

        // Put the key at the right index
        arr[j + 1] = key;
    }
}



// Display elements in the array
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
    insertionSort(arr);
    display(arr);

    return 0;
}