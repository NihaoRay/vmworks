#include <stdlib.h>
#include <stdio.h>

#define TRUE 1
#define FALSE 0

typedef int STATUS;

/**
 * 顺序查找
 * 顺序查找比较简单，就是从第一个开始，逐渐一个一个过滤 
 */
int sequential_search(int * arr, int arr_size, int key)
{
    for(int i = 0; i < arr_size; i++)
    {
        if(*(arr+i) == key) 
        {
            return i;            
        }
    }
    return FALSE;
}

/**
 * 带有哨兵的顺序查找
 * 第一个元素不要赋值，用于存放key
 */ 
int sequential_search_key(int * arr, int arr_size, int key)
{
    int index = arr_size;
    *(arr) = key;

    while(*(arr + index) != key)
    {
        index--;    
    }

    return index;
}

int main(int argc, char const *argv[])
{
    int arr[19] = {0, 1, 2, 3, 4, 5, 6, 7};
    int key = 5;

    printf("the result-->%d\n", sequential_search_key(arr, 8, key));

    return 0;
}
