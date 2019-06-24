#pragma once
#include<iostream>
#include<vector>
#include<cassert>
using namespace std;
//稀疏图  邻接表
class SparseGraph
{
private:
	int n, m;//节点，边
	bool directed;
	vector<vector<int>>g;//与邻接矩阵不同

public:
	SparseGraph(int n,bool directed);
	//~SparseGraph();

	int V() { return n; }//点数
	int E() { return m; }//边数

	void addEdge(int v, int w) {//增加边
		assert(v >= 0 && v < n);
		assert(w >= 0 && w < n);
		g[v].push_back(w);
		if (v != w && !directed) {
			g[w].push_back(v);
		}
		m++;
	}
	bool hasEdge(int v, int w) {
		assert(v >= 0 && v < n);
		assert(w >= 0 && w < n);
		for (int i = 0; i < g[v].size(); i++) {//所以邻接表适合稀疏图
			if (g[v][i] == w) {
				return true;
			}
		}
		return false;
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
		SparseGraph &G;
		int v;
		int index;//当前迭代到哪里
	public:
		adjIterator(SparseGraph &graph, int v):G(graph){
			this->v = v;
			this->index = 0;
		}
		int begin() {
			index = 0;
			if (G.g[v].size()) {
				return G.g[v][index];
			}
			return -1;
		}
		int next() {
			index++;
			if (index < G.g[v].size()) {
				return G.g[v][index];
			}
			return -1;
		}
		bool end() {
			return index >= G.g[v].size();
		}
	};

	
};

SparseGraph::SparseGraph(int n, bool directed)
{
	this->n = n;
	this->m = 0;
	this->directed = directed;
	for (int i = 0; i < n; i++) {
		g.push_back(vector<int>());
	}
}

