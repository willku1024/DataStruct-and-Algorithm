#ifndef SEQQUEUE_H
#define SEQQUEUE_H

typedef void SeqQueue;
typedef void SeqQueueNode;

SeqQueue* SeqQueue_Create(int capacity);

void SeqQueue_Destroy(SeqQueue* queue);

void SeqQueue_Clear(SeqQueue* queue);

int SeqQueue_Length(SeqQueue* queue);

int SeqQueue_Capacity(SeqQueue* queue);

int SeqQueue_Append(SeqQueue *queue, SeqQueueNode* node);

SeqQueueNode* SeqQueue_Header(SeqQueue* queue);

SeqQueueNode* SeqQueue_Retrieve(SeqQueue* queue);


#endif // SEQQUEUE_H
