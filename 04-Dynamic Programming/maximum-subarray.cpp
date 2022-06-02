/*
    Kadane's Algorithm - Maximum Subarray Problem

    Problem: Given an integer array nums, find
    the contiguous subarray (containing at least
    one number) which has the largest sum and return
    its sum. A subarray is a contiguous part of an array.
*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;


int maxSumArray(const vector<int>& arr)
{
    // Declare "currSum" to keep track of the sum thus far
    // Declare "maxSum" to keep track of the overall maximum sum
        // Set maxSum equal to INT_MIN so that the first if-statement
        // in the loop works in the first pass.
    int currSum = 0;
    int maxSum = INT_MIN;

    for (int i = 0; i < arr.size(); ++i)
    {
        // Keep track of the current sum of the subarray.
        currSum += arr[i];


        // If the current sum is greater than the maximum sum,
        // then update the maximum sum.
        if (currSum > maxSum)
        {
            maxSum = currSum;
        }

        // If the current sum is negative, then reset it to zero
        // since we assume there is at least one positive number in the
        // array. If there is at least one positive number, then there is
        // a subarray whose sum is positive, even if it is just
        // that one positive number.
        if (currSum < 0)
        {
            currSum = 0;
        }
    }

    return maxSum;
}

int main()
{
    vector<int> arr = { -2,1,-3,4,-1,2,1,-5,4 };
    cout << maxSumArray(arr) << endl;

    return 0;
}