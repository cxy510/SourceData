// ShortestPath.cpp : �������̨Ӧ�ó������ڵ㡣
//
#include"stdafx.h"
#include <iostream>
#include "weightSparseGraph.h"
#include "weightDenseGraph.h"
#include "ReadGraph.h"
#include "Dijkstra.h"

using namespace std;

// �������ǵ�Dijkstra���·���㷨
int main() {

	string filename = "testG1.txt";
	int V = 5;

	WSparseGraph<int> g =WSparseGraph<int>(V, true);
	// Dijkstra���·���㷨ͬ������������ͼ
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