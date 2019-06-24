// heap.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<algorithm>
#include<string>
#include<ctime>
#include<cmath>
#include<cassert>
using namespace std;
template<typename Item>
class MaxHeap {
private:
	Item *data;
	int count;
	int capacity;
	const void shiftup(int k) {
		while (k>1&&data[k / 2] < data[k]) {
			swap(data[k / 2], data[k]);  
			k /= 2;
		}
	}
	void shiftdown(int k) {
		while (2 * k <= count) {
			int j = 2 * k;
			if (j + 1 <= count&&data[j+1]>data[j]) {//右孩子大于左孩子
				j += 1;
			}
			if (data[k] >= data[j]) break;
			swap(data[k], data[j]);
			k = j;
		}
	}
public:
	MaxHeap(int capacity) {
		data = new Item[capacity + 1];
		count = 0;
		this->capacity = capacity;
	}
	~MaxHeap() {
		delete[]data;
	}
	int size() {
		return count;
	}
	bool isEmpty() {
		return count == 0;
	}
	void insert(Item item) {
		assert(count + 1 <= capacity);
		data[count+1] = item;//索引从1开始
		count++;
		shiftup(count);
	}
	Item extractMax() {//取出最大值
		assert(count > 0);
		Item ret = data[1];
		swap(data[1], data[count]);
		count--;
		shiftdown(1);
		return ret;

	}
};
int main()
{
	MaxHeap<int>maxheap = MaxHeap<int>(100);
//	cout << maxheap.size()<<endl;

	srand(time(NULL));
	for (int i = 0; i < 15; i++) {
		maxheap.insert(rand() % 100);
	}
	
//	cout << maxheap.size() << endl;

	while (!maxheap.isEmpty()) {
		cout << maxheap.extractMax() << endl;
	}
	
	system("pause");
    return 0;
}

