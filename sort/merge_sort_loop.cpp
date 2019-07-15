#include <iostream>




void merge(int* array, int l, int mid, int r)
{
    int len = r - l + 1;
    if (len <= 1)
    {
        return;
    }       
    int merged[len];
    for (size_t i = l, j = mid + 1, k = 0; k < len; k++)
    {
        if (i <= mid && j <= r)
        {
            if (array[i] < array[j])
            {
                merged[k] = array[i++];                
            }
            else
            {
                merged[k] = array[j++];
            }           
        }
        else if (i > mid)
        {
            merged[k] = array[j++];
        }
        else
        {
            merged[k] = array[i++];
        }
    }
    for (size_t i = l; i <= r; i++)
    {
        array[i] = merged[i - l];
    }
    //delete[] merged;        
}

void sort(int* array, int l, int r)
{
    if (r <= l)
    {
        return;
    }

    
    int mid = (r + l) / 2;    
    sort(array, l, mid);
    sort(array, mid + 1, r);
    merge(array, l, mid, r);    
}

void merge_sort(int* array, int len)
{
    int gap = 1;
    while (gap < len)
    {
       for (size_t i = 0; i + gap < len; i += 2 * gap)
       {
           int l = i, mid = i + gap - 1, r = i + 2 * gap - 1;
           if (r > len - 1)
           {
               r = len - 1;
           }                
           merge(array, l, mid, r);
       }       
       gap *= 2;
    }
    
    sort(array, 0, len - 1);
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
