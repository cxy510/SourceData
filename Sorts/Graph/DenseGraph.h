#pragma once
#include<iostream>
#include<vector>
#include<cassert>
using namespace std;

//稠密图-邻接矩阵
class DenseGraph
{
private:
	int n, m;//点数和边数
	bool directed;//有向或无向
	vector<vector<bool>>g;
public:
	DenseGraph(int n,bool directed);
	~DenseGraph();



	int V() { return n; }//点数

	int E() { return m; }//边数

	void addEdge(int v, int w) {//增加边
		assert(v >= 0 && v < n);
		assert(w >= 0 && w < n);
		if (hasEdge(v, w)) { return; }
		g[v][w] = true;
		if (!directed) {//无向图
			g[w][v] = true;
		}
		m++;
		
	}
	bool hasEdge(int v, int w) {//判断是否有边
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
		int v;//节点
		int index;//当前迭代到哪里
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