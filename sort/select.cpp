#include <iostream>

void select_sort(int* array, int nLen)
{
    for (size_t i = 0; i < nLen - 1; i++)
    {           
        int min_index = i;
        for (size_t j = i + 1; j < nLen; j++)        
        {
            if (array[j] < array[min_index])
            {                
                min_index = j;
            }            
        }
        if (min_index != i)
        {
            int temp = array[i];
            array[i] = array[min_index];
            array[min_index] = temp;
        }        
        
    }
    
}



int main()
{

    int array[] = {5, 4, 2, 3, 8};
    select_sort(array, _countof(array));
    for (auto &&e : array)
    {
        std::cout << e << ",";
    }
    system("pause");
    return 0;
}
