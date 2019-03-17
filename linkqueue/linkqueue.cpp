#include <stddef.h>
#include <stdlib.h>
#include "linkqueue.h"
#include "linklist.h"

typedef struct _tag_LinkQueueNode
{
    LinkListNode node;
    void* item;
}TLinkQueueNode;

LinkQueue *LinkQueue_Create()
{
    return LinkList_Create();
}

void LinkQueue_Destroy(LinkQueue *queue)
{
    LinkQueue_Clear(queue);
    LinkList_Destroy(queue);
}

void LinkQueue_Clear(LinkQueue *queue)
{
    while (LinkQueue_Length(queue) > 0) {
        LinkQueue_Retrieve(queue);
    }

    LinkList_Clear(queue);
}

int LinkQueue_Length(LinkQueue *queue)
{
    return LinkList_Length(queue);
}

int LinkQueue_Append(LinkQueue *queue, LinkQueueNode *item)
{
    TLinkQueueNode* t = (TLinkQueueNode*)calloc(1, sizeof (TLinkQueueNode));
    if(t == NULL)
        return -1;

    t->item = item;

    return LinkList_Insert(queue, (LinkListNode*)t, LinkList_Length(queue));

}

LinkQueueNode *LinkQueue_Header(LinkQueue *queue)
{
    TLinkQueueNode* t = (TLinkQueueNode*)LinkList_Get(queue, 0);

    if(t == NULL)
        return NULL;

    return t->item;
}

LinkQueueNode *LinkQueue_Retrieve(LinkQueue *queue)
{
    TLinkQueueNode* t = (TLinkQueueNode*)LinkList_Delete(queue, 0);

    if(t == NULL)
        return NULL;

    LinkQueueNode* node = t->item;

    free(t);

    return node;
}
