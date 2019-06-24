#pragma once
#include<cassert>
#include<iostream>
#include<stack>
using namespace std;
//深度优先遍历 求得两个节点之间的路径
template <typename Graph>
class Path
{
private:
	Graph &G;
	int s;//源结点
	bool *visited;
	int *from;//路径
	void dfs(int v) {
		visited[v] = true;
		
		typename Graph::adjIterator adj(G, v);
		for (int i = adj.begin(); !adj.end(); i = adj.next()) {
			if (!visited[i]) {
				from[i] = v;
				dfs(i);
			}
		}
	}
public:
	Path(Graph &graph, int s) :G(graph) {  
        //算法初始化
		assert(s >= 0 && s < G.V());
		visited = new bool[G.V()];
		from = new int[G.V()];
		for (int i = 0; i < G.V(); i++) {
			visited[i] = false;
			from[i] = -1;
		}
		this->s = s;
		//寻路算法
		dfs(s);
	}
	~Path() {
		delete[] visited;
		delete[] from;
	}
	bool hasPath(int w) {
		assert(w >= 0 && w < G.V());
		return visited[w];
	}
	void path(int w, vector<int>&vec) {
		stack<int>s;
		int p = w;
		while (p != -1) {
			s.push(p);
			p = from[p];
		}
		vec.clear();
		while (!s.empty()) {
			vec.push_back(s.top());
			s.pop();
		}
	}
	void showPath(int w) {
		vector<int>vec;
		path(w, vec);
		for (int i = 0; i < vec.size(); i++) {
			cout << vec[i];
			if (i == vec.size() - 1) {
				cout << endl;
			}
			else {
				cout << "-->";
			}
		}
	}
};
