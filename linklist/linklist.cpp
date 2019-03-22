#include "linklist.h"
#include <stddef.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

typedef struct _tag_LinkList
{
    LinkListNode header;
    int length;
}TLinkList;

LinkList *LinkList_Create()
{
    TLinkList *t = (TLinkList*)calloc(1, sizeof (TLinkList));
    if(t == NULL)
    {
        return NULL;
    }

    t->length = 0;
    t->header.next = NULL;

    return t;
}

void LinkList_Destroy(LinkList *list)
{
    if (list == NULL)
    {
        return ;
    }
    free(list);
    list = NULL;
}

void LinkList_Clear(LinkList *list)
{
    if (list == NULL)
    {
        return ;
    }

    TLinkList *t = (TLinkList*) list;

    t->length = 0;
    t->header.next = NULL;

    return ;
}

int LinkList_Length(LinkList *list)
{
    if (list == NULL)
    {
        return -1;
    }

    TLinkList *t = (TLinkList*) list;

    return t->length;
}

int LinkList_Insert(LinkList *list, LinkListNode *node, int pos)
{
    if(list == NULL || node ==NULL || pos<0)
    {
        return -1;
    }
    TLinkList *t = (TLinkList*) list;
    LinkListNode *current = &t->header;

    // 等价测试
    //LinkListNode *current = (LinkListNode*)list;
    //LinkListNode *current = (LinkListNode*)&t->header;

    //当前节点的前驱
    for (int i=0; i<pos && (current->next!=NULL); i++) {
        current = current->next;
    }

    // 1.把pos指向节点的后继挂上去
    node->next = current->next;
    // 2.当前节点的下个节点为新节点
    current->next = node;
    t->length++;


    return 0;
}

LinkListNode *LinkList_Get(LinkList *list, int pos)
{
    if(list == NULL || pos<0)
    {
        return NULL;
    }
    TLinkList *t = (TLinkList*) list;
    LinkListNode *current = &t->header;


    for (int i=0; i<pos && (current->next!=NULL); i++) {
        current = current->next;
    }

    return current->next;
}

LinkListNode *LinkList_Delete(LinkList *list, int pos)
{
    if(list == NULL || pos<0)
    {
        return NULL;
    }
    TLinkList *t = (TLinkList*) list;
    LinkListNode *current = &t->header;

    for (int i=0; i<pos && (current->next!=NULL); i++) {
        current = current->next;
    }

    LinkListNode *delnode = current->next;

    current->next = delnode->next;

    t->length--;

    return delnode;

}

LinkList *LinkList_Reverse(LinkList *list)
{
    if(list == NULL)
    {
        return NULL;
    }

    TLinkList *t = (TLinkList*) list;
    LinkListNode *current = (&t->header)->next;
    LinkListNode *prev = NULL;

    while (current != NULL) {
        LinkListNode *bck = current->next;
        current->next = prev;
        prev = current;
        current = bck;
    }

    t->header.next = prev;

    return list;
}
