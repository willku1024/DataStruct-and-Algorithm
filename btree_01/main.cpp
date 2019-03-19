#include <iostream>
#include <stddef.h>

using namespace std;

typedef struct BiTNode
{
    int data;
    struct BiTNode* lchild, *rchild;
}BiTNode, *BiTree;


void preOrder(BiTNode* root)
{
    if (root == NULL)
        return ;
    cout << root->data << " ";
    preOrder(root->lchild);
    preOrder(root->rchild);
}

void midOrder(BiTNode* root)
{

    if (root == NULL)
        return ;

    midOrder(root->lchild);
    cout << root->data << " ";
    midOrder(root->rchild);
}

void postOrder(BiTNode* root)
{
    if (root == NULL)
        return ;

    postOrder(root->lchild);
    postOrder(root->rchild);
    cout << root->data << " ";
}

int main()
{
    BiTNode t1 = {0, NULL, NULL};
    BiTNode t2 = {0, NULL, NULL};
    BiTNode t3 = {0, NULL, NULL};
    BiTNode t4 = {0, NULL, NULL};
    BiTNode t5 = {0, NULL, NULL};

    t1.data = 1;
    t2.data = 2;
    t3.data = 3;
    t4.data = 4;
    t5.data = 5;

    // 建立关系
    t1.lchild = &t2;
    t1.rchild = &t3;
    t2.lchild = &t4;
    t3.rchild = &t5;

    // 打印
    preOrder(&t1);
    cout << endl;
    midOrder(&t1);
    cout << endl;
    postOrder(&t1);

    return 0;
}
