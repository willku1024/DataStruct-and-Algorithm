#include "circlelist.h"
#include <stddef.h>
#include <stdlib.h>

#include <iostream>

using namespace std;

typedef struct _tag_CircleList
{
    CircleListNode header;
    CircleListNode* slider;
    int length;
}TCircleList;

CircleList *CircleList_Create()
{
    TCircleList *t = (TCircleList*)calloc(1, sizeof (TCircleList));

    if(t == NULL)
    {
        return NULL;
    }

    t->length = 0;
    t->header.next = NULL;
    t->slider = NULL;

    return t;
}

void CircleList_Destroy(CircleList *list)
{
    if (list == NULL)
    {
        return ;
    }
    free(list);
    list = NULL;

}

void CircleList_Clear(CircleList *list)
{
    if (list == NULL)
    {
        return ;
    }

    TCircleList *t = (TCircleList*) list;

    t->length = 0;
    t->header.next = NULL;
    t->slider = NULL;

    return ;
}

int CircleList_Length(CircleList *list)
{
    if (list == NULL)
    {
        return -1;
    }

    TCircleList *t = (TCircleList*) list;

    return t->length;
}

int CircleList_Insert(CircleList *list, CircleListNode *node, int pos)
{
    if(list == NULL || node ==NULL || pos<0)
    {
        return -1;
    }
    TCircleList *t = (TCircleList*) list;
    CircleListNode *current = &t->header;

    //当前节点的前驱
    for (int i=0; i<pos && (current->next!=NULL); i++) {
        current = current->next;
    }

    // 通用操作
    // 1.把pos指向节点的后继挂上去
    node->next = current->next;
    // 2.当前节点的下个节点为新节点
    current->next = node;

    // 异常点:
    // 如果插入的是第一个节点，即头插法需要有变化
    // 判断头插法的方法是找pos的结果和头结点中的header一致
    if(current == (CircleListNode*) list)
    {
        // 1.获取当前的尾节点
        CircleListNode* last = CircleList_Get(list, CircleList_Length(list));
        // 2.让最后一个节点的末尾指向第一个元素（也即：last->next = node;）
        last->next = current->next;
    }

    // 如果第一次插入，需要初始化游标
    if(t->length == 0)
    {
        t->slider = node;
    }

    t->length++;
    return 0;
}

CircleListNode *CircleList_Get(CircleList *list, int pos)
{
    if(list == NULL || pos<0)
    {
        return NULL;
    }
    TCircleList *t = (TCircleList*) list;
    CircleListNode *current = &t->header;


    for (int i=0; i<pos && (current->next!=NULL); i++) {
        current = current->next;
    }

    return current->next;
}

//获取游标所指的元素，游标向后移动
CircleListNode *CircleList_Next(CircleList *list)
{
    TCircleList *t = (TCircleList *)list;
    CircleListNode *node = t->slider;

    if(t->slider!=NULL)
        t->slider = node->next;

    return node;
}

CircleListNode *CircleList_Current(CircleList *list)
{

    TCircleList *t = (TCircleList *)list;

    return  t->slider;
}

void CircleList_Reset(CircleList *list)
{

    TCircleList *t = (TCircleList *)list;

    t->slider = t->header.next;

}

void CircleList_DeleteNode(CircleList *list, CircleListNode *node)
{
    if(list == NULL || node == NULL)
    {
        return ;
    }

    TCircleList *t = (TCircleList*) list;
    CircleListNode *current = &t->header;
    CircleListNode *prev = current;

    for (int i=0; i<CircleList_Length(list); ++i) {

        current = current->next;

        if(current == node)
        {

            // 异常点：
            // 如果为第一个节点
            if(node == ((CircleListNode*)list)->next)
            {

                CircleListNode* last = CircleList_Get(list, CircleList_Length(list)-1);
                last->next = node->next;
            }

            prev->next = node->next;

            // 如果要删除的元素是slider，要下移slider
            if(t->slider == node)
            {

                t->slider = node->next;
            }

            t->length--;

            // 如果len为0
            if(t->length == 0)
            {
                t->slider = NULL;
                t->header.next = NULL;
            }
            break;
        }

        prev = current;

    }

}


CircleListNode* CircleList_Delete(CircleList *list, int pos)
{
    if(list == NULL || pos < 0)
    {
        return NULL;
    }

    TCircleList *t = (TCircleList*) list;
    CircleListNode *current = &t->header;


    for (int i=0; i<pos; i++) {
        current = current->next;
    }

    CircleListNode* prev = current;
    CircleListNode* node = current->next;

    // 如果为第一个节点,循环未执行，current仍然指向header
    if(current == (CircleListNode*)list)
    {
        CircleListNode* last = CircleList_Get(list, CircleList_Length(list)-1);
        last->next = node->next;
    }

    prev->next = node->next;


    // 如果要删除的元素是slider，要下移slider
    if(t->slider == node)
    {

        t->slider = node->next;
    }

    t->length--;

    // 如果len为0
    if(t->length == 0)
    {
        t->slider = NULL;
        t->header.next = NULL;

    }

    return node;

}

