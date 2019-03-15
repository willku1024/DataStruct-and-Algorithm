#include <iostream>
#include "dlinklist.h"

using namespace std;

typedef  struct _v
{
    DLinkListNode node;
    int v;
}Value;


int main(int argc, const char * argv[])
{
    Value v1,v2,v3,v4,v5;

    v1.v = 1;
    v2.v = 2;
    v3.v = 3;
    v4.v = 4;
    v5.v = 5;

    DLinkList * dlist = DLinkList_Create();

    DLinkList_Insert(dlist, (DLinkListNode*) &v1, 0);
    DLinkList_Insert(dlist, (DLinkListNode*) &v2, DLinkList_Length(dlist));
    DLinkList_Insert(dlist, (DLinkListNode*) &v3, DLinkList_Length(dlist));
    DLinkList_Insert(dlist, (DLinkListNode*) &v4, DLinkList_Length(dlist));
    DLinkList_Insert(dlist, (DLinkListNode*) &v5, DLinkList_Length(dlist));



    for (int i=0; i<DLinkList_Length(dlist); i++) {
        Value *pv = (Value*)DLinkList_Get(dlist, i);
        cout << pv->v << endl;
    }

#if 10
    DLinkList_Delete(dlist, DLinkList_Length(dlist)-1);
    DLinkList_Delete(dlist, 0);

    for (int i=0; i<DLinkList_Length(dlist); i++) {
        Value *pv = (Value*)DLinkList_Next(dlist);
        cout << pv->v << endl;
    }

    DLinkList_Reset(dlist); // 2 3 4
    DLinkList_Next(dlist);

    Value *pv1 = (Value*)DLinkList_Current(dlist);
    cout << "pv1->v:" <<pv1->v << endl; //3

    DLinkList_DeleteNode(dlist, (DLinkListNode*)pv1);

    Value *pv2 = (Value*)DLinkList_Current(dlist);
    cout << "pv2->v:" <<pv2->v << endl; // 4

    DLinkList_Prev(dlist);

    Value *pv3 = (Value*)DLinkList_Current(dlist);
    cout << "pv3->v:" <<pv3->v << endl; // 2

    cout << "len:" << DLinkList_Length(dlist) << endl;
    cout << "left:" << endl;

    for (int i=0; i<DLinkList_Length(dlist); i++) {
        Value *pv = (Value*)DLinkList_Next(dlist);
        cout << pv->v << endl;
    }
#endif
    DLinkList_Destroy(dlist);

    return 0;
}

