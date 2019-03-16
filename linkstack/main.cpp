#include <iostream>
#include "linkstack.h"


using namespace std;

int main()
{
    LinkStack* stack = LinkStack_Create();

    int a[6] = {0};
    for (int i=0; i<6 ; i++) {
        a[i] = i+1;
        LinkStack_Push(stack, &a[i]);
    }

#if 1

    cout << "size:" << LinkStack_Size(stack) << endl;
    cout << "top:" << *(int *)LinkStack_Top(stack) << endl;

    while (LinkStack_Size(stack) > 0) {
        int t = *(int *)LinkStack_Pop(stack);
        cout << "t:" << t << endl;
    }

#endif
    LinkStack_Destroy(stack);

    return 0;
}
