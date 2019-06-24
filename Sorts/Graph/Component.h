#pragma once
#include <iostream>
#include <cassert>
//图的遍历 深度优先   算连通分量
using namespace std;
template<typename Graph>
class Component
{
public:
	Component(Graph &graph):G(graph) {
		visited = new bool[G.V()];
		id = new int[G.V()];
		ccount = 0;
		for (int i = 0; i < G.V(); i++) {
			visited[i] = false;
			id[i] = -1;
		}
		for (int i = 0; i < G.V(); i++) {
			if (!visited[i]) {
				dfs(i);
				ccount++;
			}
		}
	}
	~Component() {
		delete[] visited;
		delete[] id;
	}

	int count() {//连通分量个数
		return ccount;
	}
	bool isConnected(int v,int w) {
		assert(v >= 0 && v < G.V());
		assert(v >= 0 && v < G.V());
		return id[v] == id[w];
	}
private:
	Graph &G;
	bool *visited;//节点是否访问过
	int ccount;//连通分量个数
	int *id;//判断图中节点是否相连  相连的节点id相同，不相连的id不同
	void dfs(int v) {
		visited[v] = true;
		id[v] = ccount;
		typename Graph::adjIterator adj(G, v);
		for (int i = adj.begin(); !adj.end(); i = adj.next()) {
			if (!visited[i]) {
				dfs(i);
			}
		}
	}
};

