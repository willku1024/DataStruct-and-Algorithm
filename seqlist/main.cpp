#include <iostream>
#include "seqlist.h"
#include <string>
using namespace std;

typedef  struct _teacher
{
    char name[12];
    int age;
}Teacher;

int main()
{

    Teacher t1 = {"t1", 11};
    Teacher t2 = {"t2", 12};
    Teacher t3 = {"t3", 13};
    Teacher t4 = {"t4", 14};
    Teacher t5 = {"t5", 15};

    SeqList * slist = SeqList_Create(4);
    SeqList_Insert(slist, &t1, 0);
    SeqList_Insert(slist, &t2, 0);
    SeqList_Insert(slist, &t3, 0);
    SeqList_Insert(slist, &t4, 0);
    SeqList_Insert(slist, &t5, 0);
    cout << SeqList_Length(slist) << endl;
    cout << SeqList_Capacity(slist) << endl;


    for(int i=0; i< SeqList_Length(slist); i++)
    {

        Teacher *n = (Teacher*)SeqList_Get(slist,i);
        cout <<"age:" << (*n).age << endl;
        cout <<"name:" << n->name << endl;
    }


    cout<< "====" << endl;
    SeqList_Delete(slist, 1);

    for(int i=0; i< SeqList_Length(slist); i++)
    {

        Teacher *n = (Teacher*)SeqList_Get(slist,i);
        cout <<"age:" << (*n).age << endl;
        cout <<"name:" << n->name << endl;
    }

    return 0;
}
