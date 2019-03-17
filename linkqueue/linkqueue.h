#ifndef LINKQUEUE_H
#define LINKQUEUE_H

typedef void LinkQueue;
typedef void LinkQueueNode;

LinkQueue* LinkQueue_Create();

void LinkQueue_Destroy(LinkQueue* queue);

void LinkQueue_Clear(LinkQueue* queue);

int LinkQueue_Length(LinkQueue* queue);

int LinkQueue_Append(LinkQueue *queue, LinkQueueNode* item);

LinkQueueNode* LinkQueue_Header(LinkQueue* queue);

LinkQueueNode* LinkQueue_Retrieve(LinkQueue* queue);

#endif // LINKQUEUE_H
