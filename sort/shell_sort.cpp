#include <iostream>



void insert_sort(int* array, int nLen, int gap)
{
    for (size_t i = gap; i < nLen; i+=gap)
    {          
        int insert_value = array[i];  
        int insert_index = i;
        while (i > gap - 1 && array[i - gap] > insert_value)
        {
            array[i] = array[i - gap];
            i -= gap;
        }
        if (insert_index != i)
        {
            array[i] = insert_value;
        }
        
    }
    
}

void shell_sort(int* array, int nLen)
{
    int gap = nLen / 2;
    while (gap > 0)
    {
        for (size_t i = 0; i < gap; i++)
        {
            insert_sort(array + i, nLen - i, gap);
        }  
        gap = gap / 2;
    }    
}

void shell_sort2(int* array, int n)
{
    int h = 1;
    while (h < n /3)
    {
        h = 3 * h + 1;
    }
    while (h >= 1)
    {
        for (size_t i = h; i < n; i++)
        {
            int temp = array[i];
            int j = 0;
            for (j = i; j >= h&&temp < array[j - h]; j -= h)
            {
                array[j] = array[j - h];
            }
            array[j] = temp;            
        }
         h /= 3;  
        //  for (size_t i = 0; i < n; i++)
        //  {
        //      std::cout << array[i] << ",";
        //  }
         std::cout << "\n";               
    }
}

int main()
{

    //int array[] = {9, 11, 6, 5, 10, 4, 7, 1, 15, 2, 3, 8};
    int array[] = {8, 9, 1, 7, 2, 3, 5, 4, 6, 0};
    shell_sort2(array, _countof(array));
    for (auto &&e : array)
    {
        std::cout << e << ",";
    }
    system("pause");
    return 0;
}
