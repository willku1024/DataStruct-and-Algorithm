#include <iostream>
#include "linklist.h"

typedef  struct _teacher
{
    LinkListNode node;
    char name[12];
    int age;
}Teacher;


using namespace std;

int main()
{
    Teacher t1;
    Teacher t2;
    Teacher t3;
    Teacher t4;

    t1.age = 11;
    t2.age = 12;
    t3.age = 13;
    t4.age = 14;

    LinkList* llist = LinkList_Create();

    cout << "len:" << LinkList_Length(llist) << endl;

    LinkList_Insert(llist, (LinkListNode *) &t1, LinkList_Length(llist));
    LinkList_Insert(llist, (LinkListNode *) &t2, LinkList_Length(llist));
    LinkList_Insert(llist, (LinkListNode *) &t3, 0);
    LinkList_Insert(llist, (LinkListNode *) &t4, 0);


    for (int i=0; i<LinkList_Length(llist) ; i++) {
        Teacher * t = (Teacher *)LinkList_Get(llist, i);
        cout<< t->age << endl;
    }

    LinkList_Delete(llist, 3);

    for (int i=0; i<LinkList_Length(llist) ; i++) {
        Teacher * t = (Teacher *)LinkList_Get(llist, i);
        cout<< t->age << endl;
    }
    return 0;
}
