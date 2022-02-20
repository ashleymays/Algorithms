
// Array - Library Implementation
// Read more at https://www.cplusplus.com/reference/array/array/

#include <iostream>
#include <array>

void display(const std::array<int, 5>& arr)
{
    for (int i = 0; i < arr.size(); ++i)
    {
        std::cout << arr[i] << ' ';
    }
    std::cout << std::endl;
}

int main()
{
    std::array<int, 5> arr = { 1,2,3,4,5 };
    std::cout << "Front: " << arr.front() << std::endl;
    std::cout << "Back: " << arr.back() << std::endl;
    std::cout << "Size: " << arr.size() << std::endl;

    display(arr);

    return 0;
}
