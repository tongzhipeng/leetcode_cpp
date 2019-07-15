#include <iostream>




void merge_sort(int* array, int len)
{
    if (len == 1)
    {
        return;
    }
    
    int mid = len / 2;
    int len1 = mid;
    int len2 = len - mid;
    merge_sort(array, len1);
    merge_sort(array + mid, len2);
    int* sorted1 = array;
    int* sorted2 = array + mid;
    int* merged = new int[len];
    for (size_t i = 0, j = 0, k = 0; k < len; k++)
    {
        if (i < len1 && j < len2)
        {
            if (sorted1[i] < sorted2[j])
            {
                merged[k] = sorted1[i++];                
            }
            else
            {
                merged[k] = sorted2[j++];
            }           
        }
        else if (i == len1)
        {
            merged[k] = sorted2[j++];
        }
        else
        {
            merged[k] = sorted1[i++];
        }
    }
    for (size_t i = 0; i < len; i++)
    {
        array[i] = merged[i];
    }
    delete[] merged;    
    
}


int main()
{

    //int array[] = {9, 11, 6, 5, 10, 4, 7, 1, 15, 2, 3, 8};
    int array[] = {8, 9, 1, 7, 2, 3, 5, 4, 6, 0};
    merge_sort(array, _countof(array));
    for (auto &&e : array)
    {
        std::cout << e << ",";
    }
    system("pause");
    return 0;
}
