#pragma once
#include<iostream>
#include<vector>
#include<cassert>
#include"Edge.h"
using namespace std;
//ϡ��ͼ  �ڽӱ�
template <typename Weight>
class WSparseGraph
{
private:
	int n, m;//�ڵ㣬��
	bool directed;
	vector<vector<Edge<Weight>*>>g;//���ڽӾ���ͬ

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

	int V() { return n; }//����
	int E() { return m; }//����

	void addEdge(int v, int w,Weight weight) {//���ӱ�
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
		for (int i = 0; i < g[v].size(); i++) {//�����ڽӱ��ʺ�ϡ��ͼ
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
		int index;//��ǰ����������
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



