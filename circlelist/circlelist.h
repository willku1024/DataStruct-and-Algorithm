#ifndef CIRCLELIST_H
#define CIRCLELIST_H


typedef void CircleList;

typedef struct _tag_CircleListNode
{
    struct _tag_CircleListNode* next;
}CircleListNode;

CircleList* CircleList_Create();

void CircleList_Destroy(CircleList* list);

void CircleList_Clear(CircleList* list);

int CircleList_Length(CircleList* list);

int CircleList_Insert(CircleList* list, CircleListNode* node, int pos);

CircleListNode* CircleList_Get(CircleList* list, int pos);

CircleListNode* CircleList_Delete(CircleList* list, int pos);

// add

CircleListNode* CircleList_Next(CircleList* list);
CircleListNode* CircleList_Current(CircleList* list);
void CircleList_Reset(CircleList* list);
void CircleList_DeleteNode(CircleList* list, CircleListNode* node);


#endif // CIRCLELIST_H
