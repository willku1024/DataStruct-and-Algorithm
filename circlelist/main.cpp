#include <iostream>
#include "circlelist.h"
using namespace std;

typedef  struct _v
{
    CircleListNode node;
    int v;
}Value;


int main(int argc, const char * argv[])
{
    Value v1,v2,v3,v4;

    v1.v = 1;
    v2.v = 2;
    v3.v = 3;
    v4.v = 4;

    CircleList * clist = CircleList_Create();

    CircleList_Insert(clist, (CircleListNode*) &v1, 0);
    CircleList_Insert(clist, (CircleListNode*) &v2, CircleList_Length(clist));
    CircleList_Insert(clist, (CircleListNode*) &v3, CircleList_Length(clist));
    CircleList_Insert(clist, (CircleListNode*) &v4, CircleList_Length(clist));



    for (int i=0; i<CircleList_Length(clist)+2; i++) {
        Value *pv = (Value*)CircleList_Next(clist);
        cout << pv->v << endl;
    }

    CircleList_Reset(clist);

    for (int i=0; i<CircleList_Length(clist); i++) {
        Value *pv = (Value*)CircleList_Next(clist);
        cout << pv->v << endl;
    }

    CircleList_Reset(clist);

#if 10
    while (CircleList_Length(clist) > 2) {
        Value *pv = NULL;
        for (int i=1; i<3; i++) {
            CircleList_Next(clist);
        }
        pv = (Value*) CircleList_Current(clist);
        cout << "pv->v:" <<pv->v << endl;
        CircleList_DeleteNode(clist, (CircleListNode*)pv);
    }


    for (int i=0; i<6*CircleList_Length(clist); i++) {
        Value *t = (Value*) CircleList_Get(clist, i);
        cout << "left:" <<t->v << endl;
    }

    CircleListNode* n =  CircleList_Delete(clist, 1);

    cout << "v:" <<((Value*) n)->v << endl;

    CircleList_Delete(clist, 0);

    for (int i=0; i<6*CircleList_Length(clist); i++) {
        Value *t = (Value*) CircleList_Get(clist, i);
        cout << "left:" <<t->v << endl;
    }

    cout << CircleList_Length(clist) << endl;
#endif

    CircleList_Destroy(clist);

    return 0;
}

