#include <iostream>
#include <ctype.h>
#include <sstream>
#include "linkstack.h"

using namespace std;

#define MODE 10

#if MODE == 0
static stringstream ss;
#endif

/*
 * 此demo有不足，只能支持个位数，0-9的计算，如果为123+59*10，则会出问题
 */


bool isLeft(char str)
{
    bool flag;
    switch (str) {
    case '(':
        flag = true;
        break;
    default:
        flag = false;
        break;
    }

    return flag;
}

bool isRight(char str)
{
    bool flag;
    switch (str) {
    case ')':
        flag = true;
        break;
    default:
        flag = false;
        break;
    }

    return flag;
}

void output(char str)
{
#if MODE
    cout << str;
#else
    ss << str;
#endif
}


bool isOperator(char str)
{
    switch (str) {
    case '+':
    case '-':
    case '*':
    case '/':
        return true;
    default:
        return false;
    }
}

int priority(char str)
{
    switch (str) {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    default:
        return 0;
    }
}

void transform(const char* exp)
{
    LinkStack* stack = LinkStack_Create();

    unsigned int i=0;
    for (;i<strlen(exp); i++) {
        if(isdigit(exp[i]))
        {
            output(exp[i]);
        }
        else if(isOperator(exp[i]))
        {
            // TODO: 此处的top会返回NULL;这里用逻辑短路解决，不是最佳的方案
            while ( LinkStack_Size(stack)>0 && priority(exp[i]) <= priority(*(char *)LinkStack_Top(stack))) {
                output(*(char*)LinkStack_Pop(stack));
            }
            LinkStack_Push(stack, (void *)&exp[i]);
        }
        else if(isLeft(exp[i]))
        {
            LinkStack_Push(stack, (void *)&exp[i]);
        }
        else if(isRight(exp[i]))
        {
            while (!isLeft(*(char*)LinkStack_Top(stack))) {
                output(*(char*)LinkStack_Pop(stack));
            }
            LinkStack_Pop(stack);
        }else {
            cout << endl;
            cout << "bad expression, quit and destroy linkstack" ;
            LinkStack_Destroy(stack);
            return ;
        }
    }

    while(LinkStack_Size(stack) >0 && (i == strlen(exp)))
    {
        output(*(char*)LinkStack_Pop(stack));
    }

    LinkStack_Destroy(stack);

}

int express(long left, long right, char opt)
{
    switch (opt) {
    case '+':
        return left + right;
        break;
    case '-':
        return left - right;
        break;
    case '*':
        return left * right;
        break;
    case '/':
        return left / right;
        break;
    default:
        return -999;
        break;
    }
}

int compute(const char * exp)
{
    LinkStack* stack = LinkStack_Create();
    int ret = -999;

    unsigned int i=0;
    for (;i<strlen(exp); i++) {
        if(isdigit(exp[i]))
        {
            LinkStack_Push(stack, (void *)(exp[i] - '0'));
        }
        else if(isOperator(exp[i]))
        {
            long right =  (long)LinkStack_Pop(stack);
            long left  =  (long)LinkStack_Pop(stack);
            long result = express(left, right, exp[i]);

            LinkStack_Push(stack, (void *)result);

        }else {
            cout << endl;
            cout << "bad expression, quit and destroy linkstack" ;
            LinkStack_Destroy(stack);
            return ret;
        }
    }


    while( (1 == LinkStack_Size(stack)) && (i == strlen(exp)))
    {
        ret = (long)LinkStack_Pop(stack);
    }

    LinkStack_Destroy(stack);
    return  ret;

}

int main()
{
    // 单独测试
#if MODE
    transform("1+2*3+(6+5)");
    int ret = compute("123*+65++");
    cout << endl;
    cout << "expression result:" << ret << endl;
#else
    transform("1+2*3+(6+5)");
    int ret = compute(ss.str().c_str());
    cout << "expression result:" << ret << endl;
#endif

    return 0;
}
