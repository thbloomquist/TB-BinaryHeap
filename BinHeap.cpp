//
//  BinHeap.cpp
//

#include "BinHeap.h"
#include "Flags.h"

/* **************************************************************** */

#if CONSTRUCTOR || ALL
template <class T>
BinHeap<T>::BinHeap()
{
    // TODO: Allocate initial heap array and store sentinel value
    heapArray = new T[2];
    heapArray[0] = -1;
    maxSize = 1;
    heapSize = 0;
}
#endif

/* **************************************************************** */

#if DESTRUCTOR || ALL
template <class T>
BinHeap<T>::~BinHeap()
{
    // TODO: Deallocate heap array
    delete heapArray;
    heapSize = 0;
}
#endif

/* **************************************************************** */

#if ISEMPTY || ALL
// TODO: isEmpty() method
template <class T>
bool BinHeap<T>::isEmpty() {
    if(heapSize == 0) return true;
    return false;
}
#endif

/* **************************************************************** */

#if MAKEEMPTY || ALL
// TODO: makeEmpty() method
template <class T>
void BinHeap<T>::makeEmpty() {
    delete heapArray;
    heapArray = new T[2];
    heapArray[0] = -1;
    maxSize = 1;
    heapSize = 0;
}
#endif

/* **************************************************************** */

#if RESIZEARRAY || ALL
// TODO: resizeArray() method
template <class T>
void BinHeap<T>::resizeArray(int newSize) {
    maxSize = newSize;
    T *temp = new T[newSize+1];
    for(int i = 0; i <= heapSize; i++) {
     temp[i] = heapArray[i];
    }
    delete[] heapArray;
    heapArray = temp;
}
#endif

/* **************************************************************** */

#if LEFTCHILDINDEX || ALL
// TODO: leftChildIndex() method
template <class T>
int BinHeap<T>::leftChildIndex(int idx) {
    return 2*idx;
}

#endif

/* **************************************************************** */

#if RIGHTCHILDINDEX || ALL
// TODO: rightChildIndex() method
template <class T>
int BinHeap<T>::rightChildIndex(int idx) {
    return 2*idx + 1;
}
#endif

/* **************************************************************** */

#if PARENTINDEX || ALL
// TODO: parentIndex() method
template <class T>
int BinHeap<T>::parentIndex(int idx) {
    return idx/2;
}
#endif

/* **************************************************************** */

#if MINCHILD || ALL
// TODO: minChild() method
template <class T>
int BinHeap<T>::minChild(int idx) {
    int left = leftChildIndex(idx);
    int right = rightChildIndex(idx);
    if((left > heapSize && right > heapSize) || isEmpty()) {
        return -1;
    } else {
        int lnum = heapArray[left];
        int rnum = heapArray[right];
        if(lnum > rnum) {
            return right;
        } else {
            return left;
        }
    }
}
#endif

/* **************************************************************** */

#if INSERT || ALL
// TODO: insert() method
template <class T>
void BinHeap<T>::insert(const T &x) {
    if(heapSize == maxSize) {
        resizeArray(maxSize*2);
    }
    heapSize++;
    heapArray[heapSize] = x;
    percolateUp(heapSize);
}
#endif

/* **************************************************************** */

#if REMOVEMIN || ALL
// TODO: removeMin() method
template <class T>
T BinHeap<T>::removeMin() {
    if(heapSize == 0) {
        return -1;
    }
    int rnum = heapArray[1];
    heapArray[1] = heapArray[heapSize];
    heapSize--;
    percolateDown(1);
    if(heapSize < maxSize/3.0) {
        resizeArray(maxSize/2.0);
    }
    return rnum;
}
#endif

/* **************************************************************** */

#if PERCOLATEUP || ALL
// TODO: percolateUp() method
template <class T>
void BinHeap<T>::percolateUp(int idx) {
    int pNum = parentIndex(idx);
    int cNum = idx;
    while(cNum > 0) {
        int num1 = heapArray[cNum]; // child value
        int num2 = heapArray[pNum]; // parent value
        if(num2 > num1) {
            heapArray[cNum] = num2;
            heapArray[pNum] = num1;
        }
        cNum = pNum;
        pNum = parentIndex(cNum);
    }
    // wow this worked first try
}
#endif

/* **************************************************************** */

#if PERCOLATEDOWN || ALL
// TODO: percolateDown() method
template <class T>
void BinHeap<T>::percolateDown(int idx) {
    int cur = idx;
    int child = minChild(idx);
    while(child != -1) {
        int pNum = heapArray[cur];
        int cNum = heapArray[child];
        if(pNum > cNum) {
           heapArray[child] = pNum;
           heapArray[cur] = cNum;
        }
        cur = child;
        child = minChild(cur);
    }
}
#endif

/* **************************************************************** */

#if BUILDHEAP || ALL
// TODO: buildHeap() method
template <class T>
void BinHeap<T>::buildHeap(const T *arr, int size) {
    resizeArray(size);
    heapSize = size;
    heapArray[0] = -1;
    for(int i = 1; i <= size; i++) {
        heapArray[i] = arr[i-1];
    }
    for(int lNode = heapSize/2; lNode >= 1; lNode--) {
        percolateDown(lNode);
    }
}
#endif

/* **************************************************************** */



/* **************************************************************** */
/* Do NOT modify anything below this line                           */
/* **************************************************************** */

#ifndef BUILD_LIB
template <class T>
void BinHeap<T>::printHeap()
{
    std::stringstream ss;
    printHeapToStream(ss);
    std::cout << ss.str();
}


template <class T>
void BinHeap<T>::printHeapToStream(std::stringstream& ss)
{
    ss << "  Current array size: " << maxSize << std::endl;
    ss << "  Current heap size: " << heapSize << std::endl;
    
    if (!isEmpty()) {
        ss << "  Heap Elements: ";
        // Print heap array
        for (int i = 1; i <= heapSize; i++) {
            ss << heapArray[i] << " ";
        }
    }
    else {
        ss << "  Heap is empty";
    }
    ss << std::endl << std::endl;
}
#endif

template class BinHeap<int>;
