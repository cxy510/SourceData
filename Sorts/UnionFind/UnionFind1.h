#pragma once
#include <iostream>
#include <cassert>
#include<ctime>
using namespace std;
namespace UF1 {

	class UnionFind {
	private:
		int *id;
		int count;//ÔªËØ¸öÊý
	public:
		UnionFind(int n) {
			count = n;
			id = new int[n];
			for (int i = 0; i < n; i++) {
				id[i] = i;
			}
		}
		~UnionFind() {
			delete[]id;
		}
		int find(int p) {
			assert(p >= 0 && p < count);
			return id[p];
		}
		bool isConnected(int p, int q) {
			return find(p) == find(q);
		}
		void unionElements(int p, int q) {
			int pID = find(p);
			int qID = find(q);
			if (pID == qID) {
				return;
			}
			for (int i = 0; i < count; i++) {
				if (id[i] == pID) {
					id[i] = qID;
				}
			}
		}
	};
};
namespace UnionFindTestHelper {
	void testUF1(int n) {
		srand(time(NULL));
		UF1::UnionFind uf(n);
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
		std::cout << "UF1," << 2 * n << " ops," << double(endTime - starttime) / CLOCKS_PER_SEC << endl;
	}
};