#pragma once
#include "MinHeap.h"
#include "Edge.h"
#include <cassert>
using namespace std;
//使用lazyprim算法 求得最小生成树
template<typename Graph,typename Weight>
class LazyPrimMST
{
private:
	Graph &G;
	MinHeap<Edge<Weight>>pq;//优先堆
	bool *marked;//判断点是否被标记了
	vector<Edge<Weight>>mst;//最小生成树都存入向量中
	Weight mstWeight;//总权值
	void visit(int v) {//从v开始进行查找
		assert(!marked[v]);
		marked[v] = true;

		Graph::adjIterator adj(G, v);
		for (Edge<Weight>*e = adj.begin(); !adj.end(); e = adj.next()) {
			if (!marked[e->other(v)]) {//找到了一个横切边
				pq.insert(*e);
			}
		}

	}
public:
	LazyPrimMST(Graph &graph):G(graph),pq(MinHeap<Edge<Weight>>(graph.E()))
	{
		marked = new bool[G.V()];
		for (int i = 0; i < G.V(); i++) {
			marked[i] = false;
		}
		mst.clear();
		//Lazy Prim
		visit(0);
		while (!pq.isEmpty()) {
			Edge<Weight>e = pq.extractMin();
			if (marked[e.v()] == marked[e.w()]) {//不是横切边
				continue;
			}
			mst.push_back(e);
			if (!marked[e.v()]) {
				visit(e.v());
			}
			else {
				visit(e.w());
			}
		}

		mstWeight = mst[0].wt();
		for (int i = 1; i < mst.size(); i++) {
			mstWeight += mst[i].wt();
		}
	}

	~LazyPrimMST()
	{
		delete[] marked;
	}
	Weight result() {
		return mstWeight;
	}
	vector<Edge<Weight>> mstEdges() {
		return mst;
	}
};

