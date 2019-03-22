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

// 前序遍历#法建立二叉,通过传入引用，让其在字符串中真实移动(如果不是传入的是引用，会出现问题)
// 124###3#5##
BiTree createBtree(const char *& str)
{
    if(str == NULL || str[0] == '#' )
    {
        return NULL;
    }

    BiTree root = (BiTree)calloc(1, sizeof (BiTNode));
    root->data = str[0];
    root->lchild = createBtree(++str);
    root->rchild = createBtree(++str);

    return root;

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

    const char * str = "124###3#5##";
    BiTree tree = createBtree(str);
    {
        // 前序遍历
        //pntTree(tree, 1);
        //cout << endl;
        list<BiTNode> t = preOrder(tree);
        for (list<BiTNode>::iterator it = t.begin() ; it!=t.end() ; ++it) {
            cout << (char)it->data << " ";
        }
        cout << endl;
    }
    return 0;
}
