// UnionFind.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cassert>
#include"UnionFind1.h"
#include"UnionFind2.h"
#include"UnionFind3.h"
#include"UnionFind4.h"
#include"UnionFind5.h"
using namespace std;

int main()
{
	int n = 1000000;
	//UnionFindTestHelper::testUF1(n);
	//onFindTestHelper2::testUF2(n);
	UnionFindTestHelper3::testUF3(n);
	UnionFindTestHelper4::testUF4(n);
	UnionFindTestHelper5::testUF5(n);
	system("pause");
    return 0;
}

