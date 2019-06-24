#pragma once
#include <iostream>
#include <cassert>
#include<ctime>
using namespace std;
namespace UF5 {
	//并查集 路径压缩优化
	class UnionFind {
	private:
		int *parent;
		int *rank;//rank[i]表示以i为根 的层数
		int count;//元素个数
	public:
		UnionFind(int count) {
			this->count = count;
			parent = new int[count];
			rank = new int[count];
			for (int i = 0; i < count; i++) {
				parent[i] = i;
				rank[i] = 1;
			}
		}
		~UnionFind() {
			delete[]parent;
			delete[]rank;
		}
		int find(int p) {
			assert(p >= 0 && p < count);
			while (p != parent[p]){
				parent[p] = parent[parent[p]];
		    	p = parent[p];
			}
			 return p;
			
			/*if (p != parent[p])
				parent[p] = find(parent[p]);
			return parent[p];*/
		}
		bool isConnected(int p, int q) {
			return find(p) == find(q);
		}
		void unionElements(int p, int q) {
			int pRoot = find(p);
			int qRoot = find(q);
			if (pRoot == qRoot) {
				return;
			}
			if (rank[pRoot] < rank[qRoot]) {//层数不变
				parent[pRoot] = qRoot;
			}
			else if (rank[pRoot] > rank[qRoot]) {
				parent[qRoot] = pRoot;
			}
			else {
				parent[pRoot] = qRoot;
				rank[qRoot] += 1;
			}
		}
	};
};
namespace UnionFindTestHelper5 {
	void testUF5(int n) {
		srand(time(NULL));
		UF5::UnionFind uf(n);
		time_t starttime = clock();
		for (int i = 0; i < n; i++) {
			int a = rand() % n;
			int b = rand() % n;
			uf.unionElements(a, b);
		}
		for (int i = 0; i < n; i++) {
			int a = rand() % n;
			int b = rand() % n;
			uf.isConnected(a, b);
		}
		time_t endTime = clock();
		std::cout << "UF5," << 2 * n << " ops," << double(endTime - starttime) / CLOCKS_PER_SEC << endl;
	}
};
