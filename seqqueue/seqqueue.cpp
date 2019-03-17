#include <stddef.h>
#include "seqqueue.h"
#include "seqlist.h"


SeqQueue *SeqQueue_Create(int capacity)
{
    return SeqList_Create(capacity);
}


void SeqQueue_Destroy(SeqQueue *queue)
{
   SeqList_Destroy(queue);
}


void SeqQueue_Clear(SeqQueue *queue)
{
   SeqList_Clear(queue);
}


int SeqQueue_Length(SeqQueue *queue)
{
    return SeqList_Length(queue);
}


int SeqQueue_Append(SeqQueue *queue, SeqQueueNode *node)
{
    return  SeqList_Insert(queue, node, SeqList_Length(queue));
}


SeqQueueNode *SeqQueue_Retrieve(SeqQueue *queue)
{
    return SeqList_Delete(queue, 0);
}


SeqQueueNode *SeqQueue_Header(SeqQueue *queue)
{
    SeqListNode * t = SeqList_Get(queue, 0);
    if(t == NULL)
        return NULL;

    return SeqList_Get(queue, 0);
}


int SeqQueue_Capacity(SeqQueue *queue)
{
    return SeqList_Capacity(queue);
}
