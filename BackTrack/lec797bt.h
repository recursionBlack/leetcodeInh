#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution797bt {
	vector<vector<int>> vec;
public:
	vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
		vector<int> pat;
		pat.push_back(0);
		backtrack(graph, 0, pat);
		return vec;
	}

	
	void backtrack(const vector<vector<int>>& graph, int startindex, vector<int> path)
	{
		if (path.size() > 0&& path.back() == graph.size() - 1)
		{
			vec.push_back(path);
			return;
		}

		// graph = [[1, 2], [3], [3], []]
		// graph = [[4,3,1],[3,2,4],[3],[4],[]]

		for (int i = 0; i < graph[startindex].size(); i++)
		{
			path.push_back(graph[startindex][i]);
			backtrack(graph, graph[startindex][i], path);
			path.pop_back();
		}
	}

	//	输入函数
	// 第一次独立实现出二维矩阵的输入！！！终于解决了二维矩阵不知道怎么输入进来的难题
	
	void ShuRu()
	{
		cout << "please putin row number" << endl;
		cout << "zhuzengkuan id recursion" << endl;
		int row;
		cin >> row;
		cin.clear();
		cin.ignore();
		int c;
		vector<int> rowvec;
		for (int i=0; i<row; i++)
		{
			cout << "please putin a list" << endl;	
			while (cin >>c)
			{
				rowvec.push_back(c);
			}
			// 这俩句非常关键，
			cin.clear();
			cin.ignore();
			
			M_graph.push_back(rowvec);
			rowvec.clear();
		}

	}
	// 输出函数
	void CalcResult()
	{
		vector<vector<int>> res = allPathsSourceTarget(M_graph);
		for (auto s : res)
		{
			for (auto c:s)
			{
				cout << c << " ";
			}
			cout << endl;
		}
	}

public:

	int m_N = 0;
	int m_K = 0;

	string inputnums;

	vector<vector<int>> M_graph;
};