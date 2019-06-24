#pragma once
#include <iostream>
#include <cassert>
//ͼ�ı��� �������   ����ͨ����
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

	int count() {//��ͨ��������
		return ccount;
	}
	bool isConnected(int v,int w) {
		assert(v >= 0 && v < G.V());
		assert(v >= 0 && v < G.V());
		return id[v] == id[w];
	}
private:
	Graph &G;
	bool *visited;//�ڵ��Ƿ���ʹ�
	int ccount;//��ͨ��������
	int *id;//�ж�ͼ�нڵ��Ƿ�����  �����Ľڵ�id��ͬ����������id��ͬ
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

