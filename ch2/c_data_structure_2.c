#include <stdio.h>
#include <stdlib.h>

#define list_size 100

typedef int data_type;

//顺序表的实现
typedef struct 
{
    data_type list[list_size];
    int length;
} seq_list;

void init_list (seq_list * L)
{
    L->length = 0;    
}

//判断书序表是否为空
int list_empty(seq_list * L)
{
    if(L->length == 0)
        return 1;
    else
        return 0;    
} 

//根据下标获得一个元素
int get_elem(seq_list * L, int i, data_type * elem)
{
    if(i < 1 || i > L->length)
        return 0;
    *elem = L->list[i - 1];
    
    return 1;
}

//根据指定位置插入一个元素
int insert_list(seq_list * L, int index, data_type elem)
{
    if(index < 1 || index > (L->length + 1))
        return 0;
    else if(L->length >= list_size)
    {
        return 0;
    }
    else
    {
        //在书本的地方没有加大括号，这是不规范的
        for(int i = L->length;i > index ;i--)
        {
            L->list[i] = L->list[i - 1];
        }
        //赋值
        L->list[index - 1] = elem;
        L->length = L->length + 1;
        return 1;
    }
}

//根据index删除
int delete_list_by_index(seq_list * L, int index, data_type * elem)
{
    if( L-> length <= 0) 
    {
        return 0;        
    } 
    else if(index < 1 || index > L->length)
    {
        printf("请重新选择位置，超出范围\n");
        return 0;
    }
    else
    {
        *elem=L->list[index - 1];
        for(int i = index; i < L->length; i++)
        {
            L->list[i - 1] = L->list[i];
        }
        L->length--;
        return 1;
    }
}

int list_length(seq_list * L)
{
    return L->length;    
}

void clear_list(seq_list * L)
{
    L->length = 0;
}


int main()
{
    seq_list list;
    init_list(&list);

    int arr[10] = {1, 1, 2, 3, 4, 5, 6, 8} ;

    for(int i = 1;i < 8;i++)
    {
        insert_list(&list, i, arr[i]);
    }

    for(int i = 0;i < (&list)->length;i++)
    {
        printf("%d\n", (&list)->list[i]);
    }

    data_type elem = 0;
    delete_list_by_index(&list, 2, &elem);

    printf("\n");

    for(int i = 0;i < (&list)->length;i++)
    {
        printf("%d\n", (&list)->list[i]);
    }

    return 0;
}
