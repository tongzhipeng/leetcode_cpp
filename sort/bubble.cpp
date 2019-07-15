#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

void bubble_sort(int* array, int nLen)
{
    for (size_t i = 1; i < nLen; i++)
    {
        bool ordered = true;
        for (size_t j = 0; j < nLen - i; j++)
        {
            if (array[j] > array[j + 1])
            {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                ordered = false;
            }            
        }
        if (ordered)
        {
           break;
        }      
    }
    
}

int main()
{

    int array[] = {5, 4, 2, 3, 8};
    bubble_sort(array, _countof(array));
    for (auto &&e : array)
    {
        std::cout << e << ",";
    }
    system("pause");
    return 0;
}