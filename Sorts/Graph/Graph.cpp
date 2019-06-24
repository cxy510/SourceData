// Graph.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "SparseGraph.h"
#include "DenseGraph.h"
#include "ReadGraph.h"
#include "Component.h"
#include "Path.h"
#include "ShortestPath.h"
#include <time.h>
int main()
{
	

	//������ȱ����õ�·��
	string filename1 = "testG1.txt";
	SparseGraph g1(13, false);
	ReadGraph<SparseGraph> readGraph1(g1, filename1);
	g1.show();
	cout << endl;
	Path<SparseGraph>dfs(g1, 0);
	cout << "DFS:";
	dfs.showPath(6);
	//������ȱ����õ���С·�� 
	ShortestPath<SparseGraph>bfs(g1, 0);
	cout << "BFS:";
	bfs.showPath(6);


	//��������㷨�����ͨ��������
	/*string filename1 = "testG1.txt";
	SparseGraph g1(13, false);
	ReadGraph<SparseGraph> readGraph1(g1, filename1);
	Component<SparseGraph>component1(g1);
	cout << "TestG1.txt,Component Count: " << component1.count() << endl;
	cout << endl;
	string filename2 = "testG2.txt";
	SparseGraph g2(7, false);
	ReadGraph<SparseGraph> readGraph2(g2, filename2);
	Component<SparseGraph>component2(g2);
	cout << "TestG2.txt,Component Count: " << component2.count() << endl;*/

	//��ȡ�ļ�����ͼ ����ʾ
	/*string filename = "testG1.txt";
	SparseGraph g1(13, false);
	ReadGraph<SparseGraph> readGraph1(g1, filename);
	g1.show();
	cout << endl;
	DenseGraph g2(13, false);
	ReadGraph<DenseGraph> readGraph2(g2, filename);
	g2.show();*/


	//���ֽṹ��̬���ӱߣ�����ӡ��ʾ
	//int N = 20;//20����
	//int M = 100;//100����
	//srand(time(NULL));
	//SparseGraph g1(N, false);
	//for (int i = 0; i < M; i++) {
	//	int a = rand() % N;
	//	int b = rand() % N;
	//	g1.addEdge(a,b);
	//}

	//for (int v = 0; v < N; v++) {
	//	cout << v << ":";
	//	SparseGraph::adjIterator adj(g1, v);
	//	for (int w = adj.begin(); !adj.end(); w = adj.next()) {
	//		cout << w << " ";
	//	}
	//	cout << endl;
	//}

	//DenseGraph g2(N, false);
	//for (int i = 0; i < M; i++) {
	//	int a = rand() % N;
	//	int b = rand() % N;
	//	g2.addEdge(a, b);
	//}

	//for (int v = 0; v < N; v++) {
	//	cout << v << ":";
	//	DenseGraph::adjIterator adj(g2, v);
	//	for (int w = adj.begin(); !adj.end(); w = adj.next()) {
	//		cout << w << " ";
	//	}
	//	cout << endl;
	//}



	system("pause");
    return 0;
}

