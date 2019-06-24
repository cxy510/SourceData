#pragma once
#include<iostream>
using namespace std;
template<typename Weight>
class Edge
{
public:
	Edge(int a,int b,Weight weight) {
		this->a = a;
		this->b = b;
		this->weight = weight;
	}
	Edge() {

	}
	~Edge() {

	}
	int v() { return a; }//��ñߵ���������
	int w() { return b; }
	Weight wt() { return weight; }//���Ȩֵ
	int other(int x) {
		assert(x == a || x == b);
		return x == a ? b : a;
	}
	friend ostream& operator<<(ostream&os, const Edge&e) {
		os << e.a << "-" << e.b << ": " << e.weight;
		return os;
	}
	bool operator<(Edge<Weight>&e) {
		return weight < e.wt();
	}
	bool operator<=(Edge<Weight>&e) {
		return weight <= e.wt();
	}
	bool operator>=(Edge<Weight>&e) {
		return weight >= e.wt();
	}
	bool operator>(Edge<Weight>&e) {
		return weight > e.wt();
	}
	bool operator==(Edge<Weight>&e) {
		return weight == e.wt();
	}
private:
	int a, b;
	Weight weight;
};

