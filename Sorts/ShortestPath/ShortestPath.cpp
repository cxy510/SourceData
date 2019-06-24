// ShortestPath.cpp : 定义控制台应用程序的入口点。
//
#include"stdafx.h"
#include <iostream>
#include "weightSparseGraph.h"
#include "weightDenseGraph.h"
#include "ReadGraph.h"
#include "Dijkstra.h"

using namespace std;

// 测试我们的Dijkstra最短路径算法
int main() {

	string filename = "testG1.txt";
	int V = 5;

	WSparseGraph<int> g =WSparseGraph<int>(V, true);
	// Dijkstra最短路径算法同样适用于有向图
	//SparseGraph<int> g = SparseGraph<int>(V, false);
	ReadGraph<WSparseGraph<int>, int> readGraph(g, filename);

	cout << "Test Dijkstra:" << endl << endl;
	Dijkstra<WSparseGraph<int>, int> dij(g, 0);
	for (int i = 0; i < V; i++) {
		if (dij.hasPathTo(i)) {
			cout << "Shortest Path to " << i << " : " << dij.shortestPathTo(i) << endl;
			dij.showPath(i);
		}
		else
			cout << "No Path to " << i << endl;

		cout << "----------" << endl;
	}
	system("pause");
	return 0;
}