#include <iostream>
#include <vector>
#include <stdlib.h>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <sstream> 
#include <stack>
#include <cmath>


using namespace std;

class Solution079 {
public:
	// �����������޷��ĳɶ�̬�滮��
	// ����һ�� m x n ��ά�ַ����� board ��һ���ַ������� word
	// ��� word �����������У����� true �����򣬷��� false ��
	// ���ʱ��밴����ĸ˳��ͨ�����ڵĵ�Ԫ���ڵ���ĸ����
	// ����"����"��Ԫ������Щˮƽ���ڻ�ֱ���ڵĵ�Ԫ��
	// ͬһ����Ԫ���ڵ���ĸ�������ظ�ʹ��
	// �������� : https://leetcode.cn/problems/word-search/
	bool exist(vector<vector<char>>& board, string word) {

		for (int i = 0; i < board.size(); i++)
		{
			for (int j = 0; j < board[0].size(); j++) {
				if (f(board, i, j, word, 0)) {
					return true;
				}
			}
		}
		return false;
	}

	// ��Ϊboard������е��ַ�
	// ���������Щ�ַ��޷�����
	// ��·���ĵݹ��޷��ĳɶ�̬�滮����˵û��Ҫ
	// ��(i,j)����������w[k]�����ʺ����ܲ��ܰ�word�߳���w[k...]
	bool f(vector<vector<char>>& b, int i, int j, string w, int k) {
		if (k == w.length()) {
			return true;
		}
		if (i < 0 || i == b.size() || j < 0 || j == b[0].size() || b[i][j] != w[k]) {
			return false;
		}
		// ��Խ�磬b[i][j] == w[k]
		char tmp = b[i][j];
		b[i][j] = 0;
		bool ans = f(b, i - 1, j, w, k + 1)
			|| f(b, i + 1, j, w, k + 1)
			|| f(b, i, j - 1, w, k + 1)
			|| f(b, i, j + 1, w, k + 1);
		b[i][j] = tmp;
		return ans;
	}

	//	���뺯��
	// [[1,3,1],[1,5,1],[4,2,1]] 
	// res = 7;
	// [[1,2,3],[4,5,6]]
	// res = 12;
	void ShuRu()
	{
		cout << "please putin word1" << endl;
		cin >> m_s1;
		cin.clear();
		cin.ignore();
	}
	// �������
	void CalcResult()
	{
		grid = parse_2d_array(m_s1);
		int  res = minPathSum4(grid);
		cout << "the result is: " << endl;
		cout << res << " " << endl;
	}

	vector<vector<int>> parse_2d_array(string input) {
		vector<vector<int>> array;
		vector<int> arr;
		stack<int> q;
		for (char c : input) {
			if (c == ',' && !q.empty())
			{
				int wei = 0;
				int sum = 0;
				while (!q.empty()) {
					int top = q.top();
					q.pop();
					sum += top * pow(10, wei);
					wei++;
				}
				arr.push_back(sum);
			}
			else if (c - '0' >= 0 && c - '0' <= 9) {
				int t = c - '0';
				q.push(t);
			}
			else if (c == ']' && !arr.empty()) {
				int wei = 0;
				int sum = 0;
				while (!q.empty()) {
					int top = q.top();
					q.pop();
					sum += top * pow(10, wei);
					wei++;
				}
				arr.push_back(sum);
				array.push_back(arr);
				arr.clear();
			}
		}
		return array;
	}

public:
	int m_N = 0;
	vector<int> m_A;
	string m_s1;
	string m_s2;
	vector<vector<int>> grid;
};