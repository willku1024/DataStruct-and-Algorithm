#ifndef DLINKLIST_H
#define DLINKLIST_H

typedef void DLinkList;

typedef struct _tag_DLinkListNode
{
    struct _tag_DLinkListNode* next;
    struct _tag_DLinkListNode* prev;
}DLinkListNode;

DLinkList* DLinkList_Create();

void DLinkList_Destroy(DLinkList* list);

void DLinkList_Clear(DLinkList* list);

int DLinkList_Length(DLinkList* list);

int DLinkList_Insert(DLinkList* list, DLinkListNode* node, int pos);

DLinkListNode* DLinkList_Get(DLinkList* list, int pos);

DLinkListNode* DLinkList_Delete(DLinkList* list, int pos);

// add

DLinkListNode* DLinkList_Next(DLinkList* list);
DLinkListNode* DLinkList_Prev(DLinkList* list);
DLinkListNode* DLinkList_Current(DLinkList* list);
DLinkListNode* DLinkList_Reset(DLinkList* list);
DLinkListNode* DLinkList_DeleteNode(DLinkList* list, DLinkListNode* node);


#endif // DLINKLIST_H
