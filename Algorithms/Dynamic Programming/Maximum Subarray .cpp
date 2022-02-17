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

int maxSumArray(const std::vector<int>& arr)
{
    // Declare "currSum" to keep track of the current sum (used in for loop below).
    // Declare "maxSum" to keep track of the overall maximum sum in the array.
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
        // since we assume there are some positive numbers in the
        // array. If there are positive numbers, then there must
        // be a subarray whose sum is positive, even if it is just
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
    std::vector<int> arr = { -2,1,-3,4,-1,2,1,-5,4 };
    std::cout << maxSumArray(arr) << std::endl;

    return 0;
}
