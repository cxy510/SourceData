#pragma once
#include<iostream>
#include<vector>
#include<cassert>
using namespace std;

//����ͼ-�ڽӾ���
class DenseGraph
{
private:
	int n, m;//�����ͱ���
	bool directed;//���������
	vector<vector<bool>>g;
public:
	DenseGraph(int n,bool directed);
	~DenseGraph();



	int V() { return n; }//����

	int E() { return m; }//����

	void addEdge(int v, int w) {//���ӱ�
		assert(v >= 0 && v < n);
		assert(w >= 0 && w < n);
		if (hasEdge(v, w)) { return; }
		g[v][w] = true;
		if (!directed) {//����ͼ
			g[w][v] = true;
		}
		m++;
		
	}
	bool hasEdge(int v, int w) {//�ж��Ƿ��б�
		assert(v >= 0 && v < n);
		assert(w >= 0 && w < n);
		return g[v][w];
	}
	void show() {
		for (int i = 0; i < n; i++) {
			cout << "vertex" << i << ":\t";
			for (int j = 0; j < g[i].size(); j++) {
				cout << g[i][j] << "\t";
			}
			cout << endl;
		}
	}
	class adjIterator {
	private:
		DenseGraph &G;
		int v;//�ڵ�
		int index;//��ǰ����������
	public:
		adjIterator(DenseGraph &graph, int v) :G(graph) {
			this->v = v;
			this->index = -1;
		}
		int begin() {
			index = -1;
			return next();
		}
		int next() {
			for (index += 1; index < G.V(); index++) {
				if (G.g[v][index]) {
					return index;
				}
			}
			return -1;
		}
		bool end() {
			return index >= G.V();
		}
	};
};

DenseGraph::DenseGraph(int n, bool directed)
{
	this->n = n;
	this->m = 0;
	this->directed = directed;
	for (int i = 0; i < n; i++) {
		g.push_back(vector<bool>(n,false));
	}
}

DenseGraph::~DenseGraph()
{
}