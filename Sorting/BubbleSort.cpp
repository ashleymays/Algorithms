/*
    Bubble Sort

    Time Complexity: O(n^2)
    Space Complexity: O(1)
*/



#include <iostream>
#include <vector>
#include <cstdlib>

void bubbleSort(std::vector<int>& vec)
{
    int tmp;
    for (int i = 0; i < vec.size() - 1; ++i)
    {
        // assume vec[i] is the minimum
        for (int j = i + 1; j < vec.size(); ++j)
        {
            // whenever there's a smaller element "vec[j]" in the subarray, swap vec[i] with it
            if (vec[j] < vec[i])
            {
                tmp = vec[i];
                vec[i] = vec[j];
                vec[j] = tmp;
            }
        }
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
    bubbleSort(vec);
    display(vec);


    return 0;
}