#include "seqlist.h"
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <iostream>
using namespace std;


//创建并且返回一个空的线性表
SeqList* SeqList_Create(int capacity)
{
    TSeqList *t = NULL;

    t = (TSeqList*)calloc(1, sizeof (TSeqList));

    if(t == NULL)
    {
        return NULL;
    }

    t->capacity = capacity;
    t->length = 0;
    t->node = (unsigned int **)calloc(capacity, sizeof (unsigned int *));

    if(t->node == NULL)
    {
        return NULL;
    }

    return t;
}

//销毁一个线性表 list
void SeqList_Destroy(SeqList* list)
{
    if(list == NULL)
    {
        return ;
    }

    TSeqList *t = (TSeqList *)list;
    if(t->node != NULL)
    {
        free (t->node);
    }

    free(t);

    return ;
}

//将一个线性表 list 中的所有元素清空, 线性表回到创建时的初始状态
void SeqList_Clear(SeqList* list)
{
    if(list == NULL)
    {
        return ;
    }

    TSeqList *t = (TSeqList *)list;
    t->length = 0;

    return ;
}

//返回一个线性表 list 中的所有元素个数
int SeqList_Length(SeqList* list)
{
    if(list == NULL)
    {
        return -1;
    }

    TSeqList *t = (TSeqList *)list;

    return t->length;

}

int SeqList_Capacity(SeqList* list)
{
    if(list == NULL)
    {
        return -1;
    }

    TSeqList *t = (TSeqList *)list;

    return t->capacity;
}

//向一个线性表 list 的 pos 位置处插入新元素 node
int SeqList_Insert(SeqList *list, SeqListNode* node, int pos)
{
    if(list == NULL || node == NULL || pos < 0)
    {
        puts("insert error");
        return -1;
    }

    TSeqList *t = (TSeqList *)list;

    // 修正越界pos
    if (pos >= t->length)
    {
        pos = t->length;
    }


    // 空间如果不够，放大2倍
    if(t->length+1 > t->capacity)
    {
        t->capacity *= 2;

        unsigned int **addr = (unsigned int**)realloc(t->node, t->capacity*sizeof (unsigned int *));

        t->node = addr;
    }


    for (int i = t->length; i > pos; i--) {
        t->node[i] = t->node[i-1];
    }

    t->node[pos] = (unsigned int *)node;
    t->length++;

    return 0;
}

//获取一个线性表 list 的 pos 位置处的元素
SeqListNode* SeqList_Get(SeqList* list, int pos)
{
    TSeqList *t = (TSeqList*) list;
    if(list == NULL || pos < 0 || pos > t->length)
    {
        return NULL;
    }

    return (t->node[pos]);
}

//删除一个线性表 list的pos位置处的元素 返回值为被删除的元素，NULL表示删除失败
SeqListNode* SeqList_Delete(SeqList* list, int pos)
{
    if(list == NULL || pos < 0)
    {
        return NULL;
    }

    SeqList *node = SeqList_Get(list, pos);

    TSeqList *t = (TSeqList *)list;

    for (int i = pos; i < t->length-1; i++) {
        t->node[i] = t->node[i+1];
    }

    t->length--;

    return node;
}
