#pragma once
#include <iostream>
#include <cassert>
#include<ctime>
using namespace std;
namespace UF2 {

	class UnionFind {
	private:
		int *parent;
		int count;//ÔªËØ¸öÊý
	public:
		UnionFind(int count) {
			this->count =count;
			parent = new int[count];
			for (int i = 0; i < count; i++) {
				parent[i] = i;
			}
		}
		~UnionFind() {
			delete[]parent;
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
			parent[pRoot] = qRoot;
		}
	};
};
namespace UnionFindTestHelper2 {
	void testUF2(int n) {
		srand(time(NULL));
		UF2::UnionFind uf(n);
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
		std::cout << "UF2," << 2 * n << " ops," << double(endTime - starttime) / CLOCKS_PER_SEC << endl;
	}
};