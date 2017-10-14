#include <iostream>

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int *array, int left, int right, int pivot)
{
    int store_index;
    int pivot_val;
    int i;
    store_index = left;
    pivot_val = array[pivot];
    swap(&array[pivot], &array[right]);
    for(i=left; i<right; ++i) {
        if(array[i] <= pivot_val) {
            swap(&array[store_index], &array[i]);
            store_index++;
        }
    }
    swap(&array[store_index], &array[right]);
    return store_index;
}

void quick_sort(int *array, int left, int right)
{
    int pivot;
    if(left < right) {
        //pivot = left;
        //pivot = right;
        pivot = (right+left)/2;
        pivot = partition(array, left, right, pivot);
        quick_sort(array, left, pivot-1);
        quick_sort(array, pivot+1, right);
    }
}

void print_array(int *array, int len)
{
    int i;
    for(i=0; i<len-1; ++i) {
        std::cout << array[i] << ",";
    }
    std::cout << array[i] << std::endl;
}

int main()
{
    int array[20] = {1, 9, 7, 3, 15,
                     12, 10, 18, 13, 20,
                     19, 22, 16, 29, 17,
                     21, 11, 25, 14, 23};
    std::cout << "Before quick-sort:" << std::endl;
    print_array(array, 20);

    quick_sort(array, 0, 19);

    std::cout << "After quick-sort:" << std::endl;
    print_array(array, 20);

    return 0;
}

