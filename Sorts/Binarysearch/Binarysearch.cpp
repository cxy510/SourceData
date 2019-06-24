// Binarysearch.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
using namespace std;

//���ֲ��ҷ�������������arr�У�����target
//����ֵΪ�������Ҳ����Ļ�����-1
template<typename T>
int binarySearch(T arr[], int n, T target) {
	int l=0, r=n-1;//��arr[l...r]�в���target
	while (l <= r) {
		//int mid = (l + r) / 2;
		int mid = l + (r - l) / 2;//��ֹint���ֵ���
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

