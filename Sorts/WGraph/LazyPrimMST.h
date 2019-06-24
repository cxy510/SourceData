#pragma once
#include "MinHeap.h"
#include "Edge.h"
#include <cassert>
using namespace std;
//ʹ��lazyprim�㷨 �����С������
template<typename Graph,typename Weight>
class LazyPrimMST
{
private:
	Graph &G;
	MinHeap<Edge<Weight>>pq;//���ȶ�
	bool *marked;//�жϵ��Ƿ񱻱����
	vector<Edge<Weight>>mst;//��С������������������
	Weight mstWeight;//��Ȩֵ
	void visit(int v) {//��v��ʼ���в���
		assert(!marked[v]);
		marked[v] = true;

		Graph::adjIterator adj(G, v);
		for (Edge<Weight>*e = adj.begin(); !adj.end(); e = adj.next()) {
			if (!marked[e->other(v)]) {//�ҵ���һ�����б�
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
			if (marked[e.v()] == marked[e.w()]) {//���Ǻ��б�
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

