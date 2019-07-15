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

int quick_partition(int* array, int low, int high)
{
    int pivot = high;
    while (low < high)
    {
        while (low < high && array[low] < array[pivot])
        {
            low++;
        }
        while (low < high && array[high] >= array[pivot])
        {
            high--;
        }
        if (low < high)
        {
            int temp = array[low];
            array[low] = array[high];
            array[high] = temp;
        }       
    }
    
    return low; 
}

void quick_sort(int* array, int low, int high)
{
    if (low <= high)
    {
        return;
    }
    
    int pivot = quick_partition(array, low, high);
    quick_sort(array, low, pivot - 1);
    quick_sort(array, pivot + 1, high);
}

void quick_sort(int* array, int len)
{
    quick_sort(array, 0, len - 1);
}

int main()
{

    // int array[] = {5, 4, 2, 3, 8};
     int array[] = {8, 9, 1, 7, 2, 3, 5, 4, 6, 0};
    quick_sort(array, _countof(array));
    for (auto &&e : array)
    {
        std::cout << e << ",";
    }
    system("pause");
    return 0;
}