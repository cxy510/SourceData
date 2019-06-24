// Binarysearch.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;

//二分查找法，在有序数组arr中，查找target
//返回值为索引，找不到的话返回-1
template<typename T>
int binarySearch(T arr[], int n, T target) {
	int l=0, r=n-1;//在arr[l...r]中查找target
	while (l <= r) {
		//int mid = (l + r) / 2;
		int mid = l + (r - l) / 2;//防止int最大值溢出
		if (arr[mid] == target) {
			return mid;
		}
		if (target < arr[mid]) {
			r = mid - 1;
		}
		else if(target > arr[mid]) {
			r = mid + 1;
		}
	}
	return -1;
}
int main()
{
    return 0;
}

