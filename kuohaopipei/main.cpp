#include <iostream>
#include <string>
#include <sstream>
#include <iterator>
#include "linkstack.h"

using namespace std;

bool isLeft(char str)
{
    bool flag;
    switch (str) {
    case '(':
    case '{':
    case '<':
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
    case '}':
    case '>':
        flag = true;
        break;
    default:
        flag = false;
        break;
    }

    return flag;
}

bool isMatch(char right, char left)
{
    bool flag;
    switch (left) {
    case '(':
        flag = (right == ')');
        break;
    case '{':
        flag = (right == '}');
        break;
    case '<':
        flag = (right == '>');
        break;
    default:
        flag = false;
        break;
    }

    return flag;
}


bool scanner2(string text)
{
    istringstream s(text);

    istream_iterator<char> is(s);
    istream_iterator<char> eof;

    LinkStack* stack = LinkStack_Create();
#if 10
    while (is!=eof) {
        char str = *is++;//++;
        cout << &is << endl;
        if (isLeft(str))
        {
            LinkStack_Push(stack, (void*) &(is));
        }
        if(isRight(str))
        {
            char STR = *(char *)LinkStack_Pop(stack);
            if(!isMatch(str, STR))
                break;
        }

        //++is;
    }

    if( (is==eof) && (LinkStack_Size(stack)==0))
    {
        return true;
    }else {
        return false;
    }

#else
    for (int i=0; i < text.length(); i++) {
        cout << text.at(i);
    }
#endif

}


bool scanner(const char *text)
{
    cout << strlen(text) << endl;

    LinkStack* stack = LinkStack_Create();

    unsigned int i = 0;
    for (; i<strlen(text); i++) {
        if (isLeft(text[i]))
        {
            LinkStack_Push(stack, (void*) &text[i]);
        }
        if(isRight(text[i]))
        {
            char STR = *(char *)LinkStack_Pop(stack);
            if(!isMatch(text[i], STR))
                break;
        }
    }

    if( (i == strlen(text)) && (LinkStack_Size(stack)==0))
    {
        return true;
    }else {
        return false;
    }

}
int main()
{
    //const char * code ="#include <iostream> int main() { char * code ='';return 0; }";
    const char * code ="{23;}()(";

    bool ret = scanner(code);

    if(ret)
    {
        cout << "ok!" << endl;
    }
    else {
        cout << "fail!" << endl;
    }

    return 0;
}
