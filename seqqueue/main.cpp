#include <iostream>
#include "seqqueue.h"

using namespace std;

int main()
{
    SeqQueue* queue = SeqQueue_Create(10);

    int a[10] = {0};
    for (int i=0; i<5 ;i++) {
        a[i] = i + 1;
        SeqQueue_Append(queue, &a[i]);
    }

    cout << "len:" << SeqQueue_Length(queue) << endl;

    cout << "header:" << *(int*)SeqQueue_Header(queue) << endl;
    cout << "capacity:" << SeqQueue_Capacity(queue) << endl;

    while (SeqQueue_Length(queue) > 0) {
        cout << "header:" << *(int*)SeqQueue_Header(queue) << endl;
        int t = *(int*)SeqQueue_Retrieve(queue);
        cout << "t:" << t << endl;
    }
    SeqQueue_Destroy(queue);




    return 0;
}
