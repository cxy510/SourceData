#pragma once
#include<iostream>
#include<vector>
#include<cassert>
#include"Edge.h"
using namespace std;

//����ͼ-�ڽӾ���
template <typename Weight>
class WDenseGraph
{
private:
	int n, m;//�����ͱ���
	bool directed;//���������
	vector<vector<Edge<Weight>*>>g;
public:
	WDenseGraph::WDenseGraph(int n, bool directed)
	{
		this->n = n;
		this->m = 0;
		this->directed = directed;
		for (int i = 0; i < n; i++) {
			g.push_back(vector<Edge<Weight>*>(n, false));
		}
	}

	WDenseGraph::~WDenseGraph()
	{
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (g[i][j] != NULL) {
					delete g[i][j];
				}
			}
		}
	}

	int V() { return n; }//����

	int E() { return m; }//����

	void addEdge(int v, int w,Weight weight) {//���ӱ�
		assert(v >= 0 && v < n);
		assert(w >= 0 && w < n);
		if (hasEdge(v, w)) { 
			delete g[v][w];
			if (!directed) {
				delete g[w][v];
			}
			m--;
			return; 
		}
		g[v][w] = new Edge<Weight>(v, w, weight);
		if (!directed) {//����ͼ
			g[w][v] = new Edge<Weight>(v, w, weight);
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
			for (int j = 0; j < n; j++) {
				if (g[i][j])
					cout << g[i][j]->wt() << "\t";
				else
					cout << "NULL\t";
			}
			cout << endl;
		}
	}
	class adjIterator {
	private:
		WDenseGraph &G;
		int v;//�ڵ�
		int index;//��ǰ����������
	public:
		adjIterator(WDenseGraph &graph, int v):G(graph){
			this->v = v;
			this->index = -1;
		}
		Edge<Weight>* begin() {
			index = -1;
			return next();
		}
		Edge<Weight>* next() {
			for (index += 1; index < G.V(); index++) {
				if (G.g[v][index]) {
					return G.g[v][index];
				}
			}
			return NULL;
		}
		bool end() {
			return index >= G.V();
		}
	};
};

