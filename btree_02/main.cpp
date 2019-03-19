#include <iostream>
#include <stddef.h>
#include <stdlib.h>

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


// 求叶子节点的个数
void leaf(BiTNode *root, int count[])
{
    if(root == NULL)
        return ;

    if( (!root->lchild) && (!root->rchild) )
    {
        count[0]++;
        cout << root->data << endl;
    }

    leaf(root->lchild, count);
    leaf(root->rchild, count);
}

// 求树的深度
int deep(BiTNode *root)
{
    int deepleft = 0;
    int deepright = 0;
    int deepval = 0;

    if(root == NULL)
    {
        return deepval;
    }

    deepleft = deep(root->lchild);
    deepright = deep(root->rchild);

    deepval = 1 + (deepleft > deepright?deepleft:deepright);

    return deepval;
}

// 拷贝二叉
BiTree copyTree(BiTree root)
{
    BiTree newRoot = NULL;
    BiTNode * left = NULL;
    BiTNode * right = NULL;

    if(root == NULL)
        return  NULL;


    newRoot = (BiTree)calloc(1, sizeof (BiTNode));
    newRoot->data = root->data;

    if(root->lchild)
    {
        newRoot->lchild = root->lchild;
        copyTree(root->lchild);
    }

    if(root->rchild)
    {
        newRoot->rchild = root->rchild;
        copyTree(root->rchild);
    }

    return newRoot;
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
    t4.rchild = &t5;

    preOrder(&t1);
    cout << endl;

    // 打印叶子节点数目
    int leafcount = 0;
    leaf(&t1, &leafcount);
    cout << "leaf count:" << leafcount << endl;


    // 打印树的深度
    int h = deep(&t1);
    cout << "height:" << h << endl;

    // 拷贝树
    BiTree tree = copyTree(&t1);
    preOrder(tree);
    cout << endl;

    return 0;
}
