#include "linklist.h"
#include "linkstack.h"
#include <stdlib.h>

typedef struct _tag_LinkStackNode
{
    LinkListNode node;
    void* item;
}TLinkStackNode;


LinkStack *LinkStack_Create()
{
    return LinkList_Create();
}


void LinkStack_Destroy(LinkStack *stack)
{
    LinkStack_Clear(stack);
    LinkList_Destroy(stack);
}

// 把所有的元素弹出，释放节点
void LinkStack_Clear(LinkStack *stack)
{
    if(stack == NULL)
        return ;

    while (LinkList_Length(stack) > 0) {
        //在这个过程中释放内存
        LinkStack_Pop(stack);
    }

    LinkList_Clear(stack);
}

// 需要转换stack 的业务节点为linklist中的业务节点
int LinkStack_Push(LinkStack *stack, void *item)
{
    TLinkStackNode *t = (TLinkStackNode*)calloc(1, sizeof (TLinkStackNode));
    if(t == NULL)
        return -1;

    t->item = item;

    return LinkList_Insert(stack, (LinkListNode*)t, 0);
}


void *LinkStack_Pop(LinkStack *stack)
{
    TLinkStackNode* t = (TLinkStackNode*)LinkList_Delete(stack, 0);

    if(t == NULL)
    {
        return NULL;
    }

    void* item = t->item;

    // 因为在push节点得时候分配了内存，所以在pop得时候需要释放堆上得内存
    free(t);

    return item;
}


void *LinkStack_Top(LinkStack *stack)
{
   TLinkStackNode* t = (TLinkStackNode*)LinkList_Get(stack, 0);

   if(t == NULL)
   {
       return NULL;
   }

   return t->item;
}


int LinkStack_Size(LinkStack *stack)
{
    return LinkList_Length(stack);
}

