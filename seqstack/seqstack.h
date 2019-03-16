#ifndef SeqStack_H
#define SeqStack_H

typedef void SeqStack;

SeqStack* SeqStack_Create(int capaticy);

void SeqStack_Destroy(SeqStack *stack);

void SeqStack_Clear(SeqStack* stack);

int SeqStack_Push(SeqStack* stack, void* item);

SeqStack* SeqStack_Pop(SeqStack* stack);

SeqStack* SeqStack_Top(SeqStack* stack);

int SeqStack_Size(SeqStack* stack);

int SeqStack_Capacity(SeqStack* stack);


#endif // SeqStack_H
