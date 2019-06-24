// selectsort.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include<string>
#include "heapSort.h"
#include "SortTestHelper.h"
using namespace std;
#define min(a,b) (((a) < (b)) ? (a) : (b))
template <typename T>
void selectsort(T nums[], int n) {//选择排序

	for (int i = 0; i < n; i++) {
		int t_index = i;
		for (int j = i + 1; j < n; j++) {
			if (nums[j] < nums[t_index]) {
				t_index = j;
			}
		}
		swap(nums[t_index], nums[i]);
	}
}
template <typename T>
void insertsort(T nums[], int n) {//插入排序
	for (int i = 1; i < n; i++) {
		T e = nums[i];
		int j;//j保存元素e应该插入的位置
		for (j = i; e< nums[j - 1] && j>0; j--) {
			nums[j] = nums[j - 1]; //
		}
		nums[j] = e;
	}
}
template <typename T>
void insertionsort(T nums[], int l,int r) {//插入排序  让归并使用
	for (int i = l+1; i <=r; i++) {
		T e = nums[i];
		int j;//j保存元素e应该插入的位置
		for (j = i; e< nums[j - 1] && j>l; j--) {
			nums[j] = nums[j - 1]; //
		}
		nums[j] = e;
	}
}
              //冒泡排序
              //希尔排序
template <typename T>
void __merge(T arr[], int l, int mid, int r) {
	T *aux=new T[r-l+1];
	for (int i = l; i <= r; i++) {
		aux[i - l] = arr[i];
	}
	int i = l,j = mid + 1;
	for (int k = l; k <= r; k++) {
		if (i > mid) {
			arr[k] = aux[j - l];
			j++;
		}
		else if(j>r) {
			arr[k] = aux[i - l];
			i++;
		}
		else if (aux[i - l] < aux[j - l]) {
			arr[k] = aux[i - l];
			i++;
		}
		else {
			arr[k] = aux[j - l];
			j++;
		}

	}
	delete[] aux;
	
}
template <typename T>
void __mergeSort(T arr[], int l,int r)//归并排序,使用递归，对arr[l...r]的范围进行排序
{
	//if (l >= r)return;
	if (r - l <= 15) {
		insertionsort(arr, l, r);
		return;
	}

	int mid = (l + r) / 2;
	__mergeSort(arr, l, mid);
	__mergeSort(arr,  mid+1,r);
	if (arr[mid] > arr[mid + 1]) {//有序数列的优化步骤
		__merge(arr, l, mid, r);
	}
}
template <typename T>
void mergeSort(T arr[], int n) {	//自顶向下进行归并
	__mergeSort(arr, 0, n - 1);
}

template <typename T>
void mergeSortBU(T arr[], int n) {	//自底向上进行归并
	for (int sz = 1; sz <= n; sz += sz) {
		for (int i = 0; i < n; i += sz + sz) {
			__merge(arr, i, i + sz - 1, min(i + sz + sz - 1,n-1));
		}
	}
}
//返回p,使得arr[l...p-1]<arr[p],arr[p+1...r]>arr[p]
template <typename T>
int  __partition(T arr[], int l, int r) {
	swap(arr[l],arr[rand()%(r-l+1)+l]);
	T v = arr[l];
	//arr[l+1...j]<v  arr[j+1...r]>v
	int j = l;
	for (int i = l + 1; i <= r; i++) {
		if (arr[i] < v) {
			swap(arr[j + 1], arr[i]);
				j++;
		}
	}
	swap(arr[l], arr[j]);
	return j;
}
template <typename T>
void __quickSort(T arr[], int l, int r) {
	/*if (l >= r) return;*/
	//优化1 小于16时 使用插入排序
	if (r - l <= 15) {
		insertionsort(arr, l, r);
		return;
	}
	int p = __partition(arr, l, r);
	__quickSort(arr, l, p - 1);
	__quickSort(arr, p+1, r);
}
template <typename T>
void quickSort(T arr[], int n) {	//快速排序
	srand(time(NULL));//随机种子
	__quickSort(arr, 0, n - 1);
}



template <typename T>
int  __partition2(T arr[], int l, int r) {
	swap(arr[l], arr[rand() % (r - l + 1) + l]);
	T v = arr[l];
	//arr[l+1...j]<v  arr[j+1...r]>v
	//arr[l+1...j]<=v;arr[j...r]>=v
	int i = l + 1, j = r;
	while (true) {
		while (i<=r&&arr[i] < v)i++;
		while (j >= l + 1 && arr[j] > v)j--;
		if (i > j)break;
		swap(arr[i], arr[j]);
		i++; j--;
	}
	swap(arr[l], arr[j]);
	return j;
}
template <typename T>
void __quickSort2(T arr[], int l, int r) {
	/*if (l >= r) return;*/
	//优化1 小于16时 使用插入排序
	if (r - l <= 15) {
		insertionsort(arr, l, r);
		return;
	}
	int p = __partition2(arr, l, r);
	__quickSort2(arr, l, p - 1);
	__quickSort2(arr, p + 1, r);
}
template <typename T>
void quickSort2(T arr[], int n) {	//双路快速排序
	srand(time(NULL));//随机种子
	__quickSort2(arr, 0, n - 1);
}






template <typename T>
//三路快速排序，将arr[l...r]分为三部分  <v =v >v,之后只对<v，>v进行递归处理
void __quickSort3(T arr[], int l, int r) {
	/*if (l >= r) return;*/
	//优化1 小于16时 使用插入排序
	if (r - l <= 15) {
		insertionsort(arr, l, r);
		return;
	}
	//partition
	swap(arr[l], arr[rand() % (r - l + 1) + l]);
	T v = arr[l];
	int lt = l;//[l+1..lt]<v
	int gt = r + 1;//[gt...r]>v
	int i = l + 1; //[lt+1..i)==v
	while (i < gt) {
		if (arr[i] < v) {
			swap(arr[i], arr[lt + 1]);
			lt++;
			i++;
		}
		else if(arr[i] > v) {
			swap(arr[i], arr[gt - 1]);
			gt--;
		}
		else {
			i++;
		}
	}
	swap(arr[l], arr[lt]);
	__quickSort3(arr, l, lt - 1);
	__quickSort3(arr, gt, r);
}
template <typename T>
void quickSort3(T arr[], int n) {	//三路路快速排序
	srand(time(NULL));//随机种子
	__quickSort3(arr, 0, n - 1);
}

template <typename T>
void heapSort1(T arr[], int n) {	//堆排序
	MaxHeap<T>maxheap = MaxHeap<T>(n);
	for (int i = 0; i < n; i++) {
		maxheap.insert(arr[i]);
	}
	for (int i = n - 1; i >= 0; i--) {
		arr[i] = maxheap.extractMax();
	}
}
template <typename T>
void heapSort2(T arr[], int n) {	//Heapify堆排序
	MaxHeap<T>maxheap = MaxHeap<T>(arr,n);
	for (int i = n - 1; i >= 0; i--) {
		arr[i] = maxheap.extractMax();
	}
}
template <typename T>
void __shiftDown(T arr[], int n, int k) {
	while (2*k+1 < n) {
		int j = 2 * k+1;
		if (j + 1 < n&&arr[j + 1]>arr[j]) {//右孩子大于左孩子
			j += 1;
		}
		if (arr[k] >= arr[j]) break;
		swap(arr[k], arr[j]);
		k = j;
	}
}
template <typename T>
void heapSort3(T arr[], int n) {	//原地堆排序
	for (int i = (n - 1)/2; i >= 0; i--) {//heappify 索引从0开始  空间复杂度为1
		__shiftDown(arr, n, i);
	}
	for (int i = n - 1; i > 0; i--) {
		swap(arr[0], arr[i]);
		__shiftDown(arr, i, 0);
	}
}

typedef struct Student{
	string name;
	int score;
	bool operator<(Student&g_s) {
		if (score < g_s.score) {
			return true;
		 }
		else { return false; }
	}
	friend ostream& operator<<(ostream &os, const Student&g_s) {
		os << "student:" << g_s.name << " score:" << g_s.score;
		return os;
	}

}student;


int main()
{
	int n= 1000000;
	int *a = SortTestHelper::generateRandArray(n, 0, n);
	int *b = SortTestHelper::copyIntArray(a, n);
	int *c = SortTestHelper::copyIntArray(a, n);
	int *d = SortTestHelper::copyIntArray(a, n);
	int *e = SortTestHelper::copyIntArray(a, n);
	int *f = SortTestHelper::copyIntArray(a, n);
	int *g = SortTestHelper::copyIntArray(a, n);
	int *h = SortTestHelper::copyIntArray(a, n);
	int *i = SortTestHelper::copyIntArray(a, n);
	int *j = SortTestHelper::copyIntArray(a, n);
	//SortTestHelper::testSort("Selection Sort",selectsort,a,n);
	//SortTestHelper::testSort("Insert Sort", insertsort, b, n); 
	SortTestHelper::testSort("Merge Sort", mergeSort, c, n);
	SortTestHelper::testSort("Merge Sort Bu", mergeSortBU, d, n);
	SortTestHelper::testSort("Quick Sort", quickSort, e, n);
	SortTestHelper::testSort("Quick Sort2", quickSort2, f, n);
	SortTestHelper::testSort("Quick Sort3", quickSort3, g, n);
	SortTestHelper::testSort("Heap Sort1", heapSort1, h, n);
	SortTestHelper::testSort("Heap Sort2", heapSort2, i, n);
	SortTestHelper::testSort("Heap Sort3", heapSort3, j, n);
	delete[] a;
	delete[] b;
	delete[] c;
	delete[] d;
	delete[] e;
	delete[] f;
	delete[] g;
	delete[] h;
	delete[] i;
	delete[] j;
	//基本有序 数据
	cout << "============================" << endl;
	int *ao = SortTestHelper::generateNearlyOrderArray(n, 100);
	int *bo = SortTestHelper::copyIntArray(ao, n);
	int *co = SortTestHelper::copyIntArray(ao, n);
	int *ddo = SortTestHelper::copyIntArray(ao, n);
	int *eo = SortTestHelper::copyIntArray(ao, n);
	int *fo = SortTestHelper::copyIntArray(ao, n);
	int *go = SortTestHelper::copyIntArray(ao, n);
	int *ho = SortTestHelper::copyIntArray(ao, n);
	int *io = SortTestHelper::copyIntArray(ao, n);
	int *jo = SortTestHelper::copyIntArray(ao, n);
	/*SortTestHelper::testSort("Selection Sort order", selectsort, ao, n);
	SortTestHelper::testSort("Insert Sort order", insertsort, bo, n);*/
	SortTestHelper::testSort("Merge Sort order", mergeSort, co, n);
	SortTestHelper::testSort("Merge Sort BU order", mergeSortBU, ddo, n);
	SortTestHelper::testSort("Qucik Sort order", quickSort, eo, n); //这里会报错,进行优化后 选取随机下标（不选取第一个）
	SortTestHelper::testSort("Qucik Sort2 order", quickSort2, fo, n);
	SortTestHelper::testSort("Qucik Sort3 order", quickSort3, go, n);
	SortTestHelper::testSort("Heap order1", heapSort1, ho, n);
	SortTestHelper::testSort("Heap order2", heapSort2, io, n);
	SortTestHelper::testSort("Heap order3", heapSort3, jo, n);
	delete[] ao;
	delete[] bo;
	delete[] co;
	delete[] ddo;
	delete[] eo;
	delete[] fo;
	delete[] go;
	delete[] ho;
	delete[] io;
	delete[] jo;
	//大量重复数据
	cout << "============================" << endl;
	int *ar = SortTestHelper::generateRandArray(n, 0, 3);
	int *br = SortTestHelper::copyIntArray(ar, n);
	int *cr = SortTestHelper::copyIntArray(ar, n);
	int *dr = SortTestHelper::copyIntArray(ar, n);
	int *er = SortTestHelper::copyIntArray(ar, n);
	int *fr = SortTestHelper::copyIntArray(ar, n);
	int *gr = SortTestHelper::copyIntArray(ar, n);
	int *hr = SortTestHelper::copyIntArray(ar, n);
	int *ir = SortTestHelper::copyIntArray(ar, n);
	int *jr = SortTestHelper::copyIntArray(ar, n);
	//SortTestHelper::testSort("Selection Sort r",selectsort,ar,n);
	//SortTestHelper::testSort("Insert Sort r", insertsort, br, n); 
	SortTestHelper::testSort("Merge Sort r", mergeSort, cr, n);
	SortTestHelper::testSort("Merge Sort Bu r" , mergeSortBU, dr, n);
//	SortTestHelper::testSort("Quick Sort r", quickSort, er, n);
	SortTestHelper::testSort("Quick Sort2 r", quickSort2, fr, n);
	SortTestHelper::testSort("Quick Sort3 r", quickSort3, gr, n);
	SortTestHelper::testSort("Heap Sort1 r", heapSort1, hr, n);
	SortTestHelper::testSort("Heap Sort2 r", heapSort2, ir, n);
	SortTestHelper::testSort("Heap Sort3 r", heapSort3, jr, n);
	delete[] ar;
	delete[] br;
	delete[] cr;
	delete[] dr;
	delete[] er;
	delete[] fr;
	delete[] gr;
	delete[] hr;
	delete[] ir;
	delete[] jr;
	Student st[4] = { {"r",22},{"a",11} ,{"g",21},{"b",51}};
	/*selectsort(st, 4);
	SortTestHelper::printarray(st, 4);*/


	system("pause");
    return 0;
}

