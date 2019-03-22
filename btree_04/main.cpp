#include <iostream>
#include <stddef.h>
#include <stdlib.h>
#include <stack>
#include <list>

using namespace std;

typedef struct BiTNode
{
    uint8_t visit;
    int data;
    struct BiTNode* lchild, *rchild;
}BiTNode, *BiTree;


void pntTree(BiTNode* root, int swt)
{
    if (root == NULL)
        return ;

    if(swt == 1)
        cout << root->data << " ";
    pntTree(root->lchild, swt);

    if(swt == 2)
        cout << root->data << " ";
    pntTree(root->rchild, swt);

    if(swt == 3)
        cout << root->data << " ";
}

// 非递归前序遍历
list<BiTNode> preOrder(BiTNode* root)
{
    list<BiTNode> list;
    stack<BiTNode *> stack;

    if(root == NULL)
        return list;

    while (root !=NULL || !stack.empty()) {
        if(root != NULL)
        {
            list.push_back(*root);
            stack.push(root);
            root = root->lchild;
        }
        else //调整指针的时候
        {
            root = stack.top();
            stack.pop();
            root = root->rchild;
        }
    }
    return list;
}


// 非递归中序遍历
list<BiTNode> inOrder(BiTNode* root)
{
    list<BiTNode> list;
    stack<BiTNode *> stack;

    if(root == NULL)
        return list;

    while (root !=NULL || !stack.empty()) {
        if(root != NULL)
        {

            stack.push(root);
            root = root->lchild;
        }
        else //调整指针的时候
        {
            root = stack.top();
            stack.pop();

            list.push_back(*root);
            root = root->rchild;
        }
    }
    return list;
}


// 非递归后序遍历
list<BiTNode> postOrder(BiTNode* root)
{
    list<BiTNode> list;
    stack<BiTNode *> stack;

    if(root == NULL)
        return list;

    while (root !=NULL || !stack.empty()) {
        if(root != NULL)
        {
            // 第一次访问，置位1
            root->visit = 1;
            stack.push(root);
            root = root->lchild;
        }
        else
        {

            root = stack.top();
            stack.pop();


            if(root->visit == 1)
            {
                // 第二次访问，置位2
                root->visit = 2;
                stack.push(root);
                root = root->rchild;
            }else {
                list.push_back(*root);
                root = NULL;
            }

        }
    }
    return list;
}


// 非递归后序遍历_err
list<BiTNode> postOrder_err(BiTNode* root)
{
    list<BiTNode> list;
    stack<BiTNode *> stack;

    if(root == NULL)
        return list;

    BiTNode* pre = NULL;
    while (root !=NULL || !stack.empty()) {
        if(root != NULL)
        {
            // root->visit = 1;
            pre = root;
            stack.push(root);
            root = root->lchild;
        }
        else //调整指针的时候
        {

            root = stack.top();
            stack.pop();

            if(root == pre)
            {
                pre = NULL;
                stack.push(root);
                root = root->rchild;
            }else {

                pre = stack.top();
                list.push_back(*root);

                root = NULL;
            }

        }
    }
    return list;
}


int main()
{
    BiTNode t2 = {0, 0, NULL, NULL};
    BiTNode t1 = {0, 0, NULL, NULL};
    BiTNode t3 = {0, 0, NULL, NULL};
    BiTNode t4 = {0, 0, NULL, NULL};
    BiTNode t5 = {0, 0, NULL, NULL};

    t1.data = 1;
    t2.data = 2;
    t3.data = 3;
    t4.data = 4;
    t5.data = 5;

    // 建立关系
    t1.lchild = &t2;
    t1.rchild = &t3;
    //t2.lchild = &t4;
    //t3.rchild = &t5;
#if 10
    {
        // 前序遍历
        pntTree(&t1, 1);
        cout << endl;
        list<BiTNode> t = preOrder(&t1);
        for (list<BiTNode>::iterator it = t.begin() ; it!=t.end() ; ++it) {
            cout << it->data << " ";
        }
        cout << endl;
    }

    {
        // 中序遍历
        pntTree(&t1, 2);
        cout << endl;
        list<BiTNode> t = inOrder(&t1);
        for (list<BiTNode>::iterator it = t.begin() ; it!=t.end() ; ++it) {
            cout << it->data << " ";
        }
        cout << endl;
    }
#endif
    {
        // 后序遍历
        pntTree(&t1, 3);
        cout << endl;
        list<BiTNode> t = postOrder(&t1);
        for (list<BiTNode>::iterator it = t.begin() ; it!=t.end() ; ++it) {
            cout << it->data << " ";
        }
        cout << endl;
    }
    return 0;
}
