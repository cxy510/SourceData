//
// Created by liuyubobobo on 9/26/16.
//

#ifndef INC_06_KRUSKAL_ALGORITHM_MINHEAP_H
#define INC_06_KRUSKAL_ALGORITHM_MINHEAP_H

#include <algorithm>
#include <cassert>

using namespace std;

// 最小堆
template<typename Item>
class MinHeap{

private:
    Item *data;
    int count;
    int capacity;

    void shiftUp(int k){
        while( k > 1 && data[k/2] > data[k] ){
            swap( data[k/2], data[k] );
            k /= 2;
        }
    }

    void shiftDown(int k){
        while( 2*k <= count ){
            int j = 2*k;
            if( j+1 <= count && data[j+1] < data[j] ) j ++;
            if( data[k] <= data[j] ) break;
            swap( data[k] , data[j] );
            k = j;
        }
    }

public:

    // 构造函�? 构造一个空�? 可容纳capacity个元�?    
	MinHeap(int capacity){
        data = new Item[capacity+1];
        count = 0;
        this->capacity = capacity;
    }

    // 构造函�? 通过一个给定数组创建一个最小堆
    // 该构造堆的过�? 时间复杂度为O(n)
    MinHeap(Item arr[], int n){
        data = new Item[n+1];
        capacity = n;

        for( int i = 0 ; i < n ; i ++ )
            data[i+1] = arr[i];
        count = n;

        for( int i = count/2 ; i >= 1 ; i -- )
            shiftDown(i);
    }

    ~MinHeap(){
        delete[] data;
    }

    // 返回堆中的元素个�?    
	int size(){
        return count;
    }

    // 返回一个布尔�? 表示堆中是否为空
    bool isEmpty(){
        return count == 0;
    }

    // 向最小堆中插入一个新的元�?item
    void insert(Item item){
        assert( count + 1 <= capacity );
        data[count+1] = item;
        shiftUp(count+1);
        count ++;
    }

    // 从最小堆中取出堆顶元�? 即堆中所存储的最小数�?    
	Item extractMin(){
        assert( count > 0 );
        Item ret = data[1];
        swap( data[1] , data[count] );
        count --;
        shiftDown(1);
        return ret;
    }

    // 获取最小堆中的堆顶元素
    Item getMin(){
        assert( count > 0 );
        return data[1];
    }
};

#endif //INC_06_KRUSKAL_ALGORITHM_MINHEAP_H
