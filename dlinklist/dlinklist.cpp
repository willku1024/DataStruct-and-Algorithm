#include "dlinklist.h"
#include <stddef.h>
#include <stdlib.h>

#define pass do{}while(0)

typedef struct _tag_DLinkList
{
    DLinkListNode  header;
    DLinkListNode* slider;
    int length;
}TDLinkList;



DLinkList *DLinkList_Create()
{
    TDLinkList* t = (TDLinkList*)malloc(sizeof (TDLinkList));

    if (t == NULL)
        return NULL;

    t->header = {NULL, NULL};
    t->slider = NULL;
    t->length = 0;

    return t;
}


void DLinkList_Destroy(DLinkList *list)
{
    if( list == NULL)
        return ;

    TDLinkList* t = (TDLinkList*)list;
    free(t);

    t = NULL;
}


void DLinkList_Clear(DLinkList *list)
{
    if(list == NULL)
        return ;

    TDLinkList* t = (TDLinkList*)list;

    t->header = {NULL, NULL};
    t->slider = NULL;
    t->length = 0;
}


int DLinkList_Length(DLinkList *list)
{
    if(list == NULL)
        return -1;

    TDLinkList* t = (TDLinkList*)list;
    return t->length;
}


int DLinkList_Insert(DLinkList *list, DLinkListNode *node, int pos)
{
    if(list == NULL)
        return -1;

    TDLinkList* t = (TDLinkList*)list;
    DLinkListNode* current = &t->header;

    for (int i=0; i<pos && (current->next != NULL); i++) {
        current = current->next;
    }

    // node prev
    DLinkListNode* prevNode = current;

    // node next
    DLinkListNode* nextNode = current->next;

    // 后插无特别,前插有例外
    node->next = nextNode;
    prevNode->next = node;

    // 异常点
    // 首个元素的时候有例外
    if (nextNode == NULL)
    {
        pass;

    }else {
        nextNode->prev = node;
    }

    // 异常点
    // 0位置插入例外，其为头结点
    if(prevNode == (DLinkListNode*)list)
    {
        node->prev = NULL;
    }else {
        node->prev = prevNode;
    }

    if(t->length == 0)
        t->slider = node;

    t->length++;

    return 1;
}


DLinkListNode *DLinkList_Get(DLinkList *list, int pos)
{
    if(list == NULL)
        return NULL;

    TDLinkList* t = (TDLinkList*)list;
    DLinkListNode* current = &t->header;

    for (int i=0; i<pos && (current->next != NULL); i++) {
        current = current->next;
    }

    return current->next;

}

DLinkListNode *DLinkList_Delete(DLinkList *list, int pos)
{
    if(list == NULL)
        return NULL;

    TDLinkList* t = (TDLinkList*)list;
    DLinkListNode* current = &t->header;

    for (int i=0; i<pos && (current->next != NULL); i++) {
        current = current->next;
    }

    // node prev
    DLinkListNode* prevNode = current;

    // node pos
    DLinkListNode* node = current->next;

    // node next
    DLinkListNode* nextNode = node->next;

    // 如果没有任何节点
    if(prevNode->next == NULL)
        return NULL;

    // 普通的方法
    prevNode->next = nextNode;


    if(nextNode == NULL)
    {
        //如果链表只有一个节点
        pass;
    }else
    {

        if(current == (DLinkListNode*) list)
        {
            //链表大于两个节点，且删除的不是第一个节点
            nextNode->prev = NULL;
        }else {
            //链表大于两个节点，且删除的是第一个节点
            nextNode->prev = prevNode;
        }
    }

    if(t->slider == node)
        t->slider = node->next;

    t->length--;

    return node;
}

DLinkListNode *DLinkList_Next(DLinkList *list)
{
    if(list == NULL)
        return NULL;

    TDLinkList* t = (TDLinkList*)list;
    DLinkListNode* node = t->slider;

    t->slider = node->next;

    return node;
}

DLinkListNode *DLinkList_Prev(DLinkList *list)
{
    if(list == NULL)
        return NULL;

    TDLinkList* t = (TDLinkList*)list;
    DLinkListNode* node = t->slider;

    t->slider = node->prev;

    return node;

}

DLinkListNode *DLinkList_Reset(DLinkList *list)
{
    if(list == NULL)
        return NULL;

    TDLinkList* t = (TDLinkList*)list;

    t->slider = t->header.next;

    return t->slider;
}



DLinkListNode *DLinkList_Current(DLinkList *list)
{
    if(list == NULL)
        return NULL;

    TDLinkList* t = (TDLinkList*)list;

    return t->slider;
}

DLinkListNode *DLinkList_DeleteNode(DLinkList *list, DLinkListNode *node)
{
    if(list == NULL || node == NULL)
        return NULL;

    TDLinkList* t = (TDLinkList*)list;
    DLinkListNode* current = &t->header;
    DLinkListNode* prev = current;

    for (int i=0; i<DLinkList_Length(list); i++) {
        current = current->next;
        if(current == node)
        {
            // node prev
            DLinkListNode* prevNode = prev;

            // node pos
            DLinkListNode* node = current;

            // node next
            DLinkListNode* nextNode = node->next;

            // 如果没有任何节点
            if(prevNode->next == NULL)
                return NULL;

            // 普通的方法
            prevNode->next = nextNode;


            if(nextNode == NULL)
            {
                //如果链表只有一个节点
                pass;
            }else
            {

                if(current == (DLinkListNode*) list)
                {
                    //链表大于两个节点，且删除的不是第一个节点
                    nextNode->prev = NULL;
                }else {
                    //链表大于两个节点，且删除的是第一个节点
                    nextNode->prev = prevNode;
                }
            }

            if(t->slider == node)
                t->slider = node->next;

            t->length--;

            break;

        }
        prev = current;
    }

    return node;
}
