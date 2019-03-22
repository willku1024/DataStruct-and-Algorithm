#include <iostream>

#define getParent(n) ((n-1)/2)

#define getLeft(n) (2*n+1)

#define getRight(n) (2*n+2)

using namespace std;

/**
 * @brief upAdjust
 * @param array
 */
void upAdjust(int array[],  int length)
{
    int childIndex =  length - 1;
    int parentIndex = getParent(childIndex);
    int tmp = array[childIndex];
    while( childIndex > 0)
    {
        if(array[parentIndex] > tmp)
        {
            array[childIndex] = array[parentIndex];
            childIndex = parentIndex;
            parentIndex = getParent(childIndex);
        }
    }

    array[childIndex] = tmp;

}


/**
 * @brief downAdjust
 * @param array
 * @param nodeIndex 要下沉的节点
 * @param length 数组的长度
 */
void downAdjust(int array[], int nodeIndex, int length)
{
    int parentIndex = nodeIndex;
    int childIndex = getLeft(parentIndex);
    int tmp = array[parentIndex];

    while(childIndex < length)
    {
        // 有右孩子，并且右比左小，移动
        if(getRight(parentIndex) < length && array[getRight(parentIndex)] < array[getLeft(parentIndex)])
            childIndex++;

        if(tmp <= array[childIndex])
            break;

        array[parentIndex] = array[childIndex];
        parentIndex = childIndex;
        childIndex = getLeft(parentIndex);
    }

    array[parentIndex] = tmp;

}

/**
 * @brief buildHeap
 * @param array
 */
void buildHeap(int array[], int length)
{
    for(int i=length/2; i>=0; i--)
    {
        //从第一个非叶子节点下沉操作
        downAdjust(array, i, length);
    }
}

int main()
{
    {
        int array[] = {1,3,2,6,5,7,8,9,10,0};
        upAdjust(array, sizeof(array)/sizeof(int));

        for(int &i:array)
            cout << i << " ";

    }
    cout << endl;
#if 10
    {
        int array[] = {7,1,3,10,5,2,8,9,6,0};
        buildHeap(array, sizeof(array)/sizeof(int));

        for(int &i:array)
            cout << i << " ";

    }
#endif
    return 0;
}
