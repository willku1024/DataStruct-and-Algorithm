#include <iostream>
#include <stddef.h>
#include <stdlib.h>
#include <stack>
#include <list>

using namespace std;

typedef struct BiTNode
{
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

    stack.push(root);
    while (!stack.empty()) {
        root = stack.top();
        stack.pop();
        list.push_back(*root);

        if(root->rchild != NULL)
            stack.push((root->rchild));

        if(root->lchild != NULL)
            stack.push((root->lchild));

    }
    return list;
}


// 非递归中序遍历
list<BiTNode> midOrder(BiTNode* root)
{
    list<BiTNode> list;
    stack<BiTNode *> stack;

    BiTNode* cur = root;
    // 当访问最后一个节点的时候停止，此时rchild为NULL，队列为空
    while (cur != NULL || false==stack.empty()) {
        if (cur != NULL) {
            stack.push(cur);
            cur = cur->lchild;
        } else {
            cur = stack.top();
            stack.pop();
            list.push_back(*cur);
            cur = cur->rchild;
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

    stack.push(root);

    while (!stack.empty()) {
        root = stack.top();
        stack.pop();
        if(root->lchild != NULL) stack.push((root->lchild));
        if(root->rchild != NULL) stack.push((root->rchild));
        //list.push_back(*root);
        list.push_front(*root);
    }
    return list;
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
#if 1
    {
        // 中序遍历
        pntTree(&t1, 2);
        cout << endl;
        list<BiTNode> t = midOrder(&t1);
        for (list<BiTNode>::iterator it = t.begin() ; it!=t.end() ; ++it) {
            cout << it->data << " ";
        }
        cout << endl;
    }

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
#endif
    return 0;
}
