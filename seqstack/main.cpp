#include <iostream>
#include "seqstack.h"
using namespace std;

int main()
{
    SeqStack* stack = NULL;
    stack =SeqStack_Create(2);

    if(stack == NULL)
    {
        return 2;
    }

    int a[5] = {0};
    for (int i=0; i<5; i++) {
        a[i] = i+1;
        SeqStack_Push(stack, &a[i]);
    }

    cout << "seqstack size:" << SeqStack_Size(stack) << endl;

    cout << "seqstack capaticy:" << SeqStack_Capacity(stack) << endl;

    cout << "seqstack top:" << *(int*)SeqStack_Top(stack) << endl;

    while (SeqStack_Size(stack) > 2) {
        int t = *(int*)SeqStack_Pop(stack);
        cout << "t:" << t << endl;
    }

    cout << "seqstack top:" << *(int*)SeqStack_Top(stack) << endl;
    SeqStack_Pop(stack);
    cout << "seqstack top:" << *(int*)SeqStack_Top(stack) << endl;


    return 0;
}
