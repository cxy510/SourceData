#pragma once
#include<iostream>
#include<vector>
#include<cassert>
#include"Edge.h"
using namespace std;
//稀疏图  邻接表
template <typename Weight>
class WSparseGraph
{
private:
	int n, m;//节点，边
	bool directed;
	vector<vector<Edge<Weight>*>>g;//与邻接矩阵不同

public:
	WSparseGraph::WSparseGraph(int n, bool directed)
	{
		this->n = n;
		this->m = 0;
		this->directed = directed;
		for (int i = 0; i < n; i++) {
			g.push_back(vector<Edge<Weight>*>());
		}
	}
	~WSparseGraph() {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < g[i].size(); j++) {
				delete g[i][j];
			}
		}
	}

	int V() { return n; }//点数
	int E() { return m; }//边数

	void addEdge(int v, int w,Weight weight) {//增加边
		assert(v >= 0 && v < n);
		assert(w >= 0 && w < n);
		g[v].push_back(new Edge<Weight>(v,w,weight));
		if (v != w && !directed) {
			g[w].push_back(new Edge<Weight>(v, w, weight));
		}
		m++;
	}
	bool hasEdge(int v, int w) {
		assert(v >= 0 && v < n);
		assert(w >= 0 && w < n);
		for (int i = 0; i < g[v].size(); i++) {//所以邻接表适合稀疏图
			if (g[v][i]->other(v)==w) {
				return true;
			}
		}
		return false;
	}
	void show() {
		for (int i = 0; i < n; i++) {
			cout << "vertex" << i << ":\t";
			for (int j = 0; j < g[i].size(); j++) {
				cout <<"(to:"<< g[i][j]->w()<<",wt"<<g[i][j]->wt()<<")\t";
			}
			cout << endl;
		}
	}
	class adjIterator {
	private:
		WSparseGraph &G;
		int v;
		int index;//当前迭代到哪里
	public:
		adjIterator(WSparseGraph &graph, int v) :G(graph) {
			this->v = v;
			this->index = 0;
		}
		Edge<Weight>* begin() {
			index = 0;
			if (G.g[v].size()) {
				return G.g[v][index];
			}
			return NULL;
		}
		Edge<Weight>* next() {
			index++;
			if (index < G.g[v].size()) {
				return G.g[v][index];
			}
			return NULL;
		}
		bool end() {
			return index >= G.g[v].size();
		}
	};


};



