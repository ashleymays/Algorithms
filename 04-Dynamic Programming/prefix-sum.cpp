/*
    Prefix Sum Algorithm

    An algorithm to find the sum of values in a range in an array.
    The result is an array where example[i] = example[0] + example[1] + ... + example[i]

    The idea is to start at the second element in the range and add the previous element's value to it.
    We update it and iterate through the array.

    Read more at https://www.geeksforgeeks.org/prefix-sum-array-implementation-applications-competitive-programming/
*/

#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

void display(const vector<int>& vec)
{
    for (int i = 0; i < vec.size(); ++i)
    {
        cout << vec[i] << ' ';
    }
    cout << endl;
}

int main()
{
    vector<int> example = { 10, 20, 30, 40, 50 };

    // the range of elements to work with
    int start = 0;
    int end = 4;

    // check that the start and end are valid indices
    assert(start >= 0 && end <= example.size() - 1 && start <= end);


    // prefix sum algorithm
    for (int i = start + 1; i <= end; ++i)
    {
        example[i] += example[i - 1];
    }

    display(example);

    return 0;
}
