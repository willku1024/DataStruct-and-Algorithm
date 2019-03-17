#include <iostream>
#include "linkqueue.h"

using namespace std;

int main()
{
    LinkQueue* queue = LinkQueue_Create();

    int a[5] = {0};
    for (int i=0; i<5; i++) {
        a[i] = i+1;
        LinkQueue_Append(queue, &a[i]);
    }


    cout << "len:" << LinkQueue_Length(queue) << endl;

    while (LinkQueue_Length(queue) > 0) {
        cout << "current len:" << LinkQueue_Length(queue) << endl;
        cout << "header:" << *(int*)LinkQueue_Header(queue) << endl;
        int t = *(int*)LinkQueue_Retrieve(queue);
        cout << "t:" << t << endl;
    }

    LinkQueue_Destroy(queue);

    return 0;
}
