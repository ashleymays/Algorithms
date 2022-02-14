/*
    Bubble Sort

    Time Complexity: O(n^2)
    Space Complexity: O(1)
*/



#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;



void bubbleSort(vector<int>& arr)
{
    int tmp;
    for (int i = 0; i < arr.size() - 1; ++i)
    {
        for (int j = i + 1; j < arr.size(); ++j)    // Assume arr[i] is the minimum
        {
            if (arr[j] < arr[i])                    // Whenever there's a smaller element "arr[j]" 
            {                                       // in the subarray, swap arr[i] with it
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
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
    bubbleSort(arr);
    display(arr);

    return 0;
}