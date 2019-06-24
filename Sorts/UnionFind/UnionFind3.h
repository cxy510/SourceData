#pragma once
#include <iostream>
#include <cassert>
#include<ctime>
using namespace std;
namespace UF3 {

	class UnionFind {
	private:
		int *parent;
		int *sz;//sz[i]表示以i为根 的元素个数
		int count;//元素个数
	public:
		UnionFind(int count) {
			this->count = count;
			parent = new int[count];
			sz = new int[count];
			for (int i = 0; i < count; i++) {
				parent[i] = i;
				sz[i] = 1;
			}
		}
		~UnionFind() {
			delete[]parent;
			delete[]sz;
		}
		int find(int p) {
			assert(p >= 0 && p < count);
			while (p != parent[p])
				p = parent[p];
			return p;
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
			if (sz[pRoot] <= sz[qRoot]) {
				parent[pRoot] = qRoot;
				sz[qRoot] += sz[pRoot];
			}
			else {
				parent[qRoot] =pRoot;
				sz[pRoot] += sz[qRoot];
			}
		}
	};
};
namespace UnionFindTestHelper3 {
	void testUF3(int n) {
		srand(time(NULL));
		UF3::UnionFind uf(n);
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
		std::cout << "UF3," << 2 * n << " ops," << double(endTime - starttime) / CLOCKS_PER_SEC << endl;
	}
};