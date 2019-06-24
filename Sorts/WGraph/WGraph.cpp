// WGraph.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iomanip>
#include "ReadGraph.h"
#include "weightDenseGraph.h"
#include "weightSparseGraph.h"
#include "LazyPrimMST.h"
#include "KruskalMST.h"
int main()
{
	string filename = "testWG1.txt";
	int V = 8;
	cout << fixed << setprecision(2);

	WDenseGraph<double>g1 = WDenseGraph<double>(V, false);
	ReadGraph<WDenseGraph<double>, double>readGraph1(g1, filename);
	g1.show();
	cout << endl;

	WSparseGraph<double>g2 = WSparseGraph<double>(V, false);
	ReadGraph<WSparseGraph<double>, double>readGraph2(g2, filename);
	g2.show();
	cout << endl;
	//Lazy prim算法
	cout << "Lazy Prim:" << endl;
	LazyPrimMST<WSparseGraph<double>,double>lz(g2);
	vector<Edge<double>>mst = lz.mstEdges();
	for (int i = 0; i < mst.size(); i++) {
		cout << mst[i] << endl;
	}
	cout << "The MST weight is:" << lz.result() << endl;
	cout << endl;

	//Kruskal算法
	//cout << "Kruskal" << endl;
	//KruskalMST<WSparseGraph<double>, double>kruskalmst(g2);
	//mst = kruskalmst.mstEdges();
	//for (int i = 0; i < mst.size(); i++) {
	//	cout << mst[i] << endl;
	//}
	//cout << "The MST weight is:" << kruskalmst.result() << endl;
	// Test Kruskal MST
	cout << "Test Kruskal MST:" << endl;
	KruskalMST<WSparseGraph<double>, double> kruskalMST(g2);
	mst = kruskalMST.mstEdges();
	for (int i = 0; i < mst.size(); i++)
		cout << mst[i] << endl;
	cout << "The MST weight is: " << kruskalMST.result() << endl;
	system("pause");
    return 0;
}

