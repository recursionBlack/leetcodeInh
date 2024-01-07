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

class Solution516_4 {
public:
	// �ϸ�λ�������Ķ�̬�滮 + �ռ�ѹ������
	//L>R�ĸ��Ӳ������Ϊl<R,һ��ĸ��Ӳ������ˡ�
	//���Ҹ������·��������ӣ����Ŀ���ȡ�����Ͻǵĸ��ӵ�ֵ���������������
	int longestPalindromeSubseq4(string str) {
		int n = str.length();
		vector<int> dp(n);
		int leftDown = 0, backup;
		for (int l = n - 1; l >= 0; l--) {
			// dp[l] : �����е�dp[l][l]
			dp[l] = 1;
			if (l + 1 < n) {
				leftDown = dp[l + 1];
				// dp[l+1] : �����е�dp[l][l+1]
				dp[l + 1] = str[l] == str[l + 1] ? 2 : 1;
			}
			for (int r = l + 2; r < n; r++) {
				backup = dp[r];
				if (str[l] == str[r]) {
					dp[r] = 2 + leftDown;
				}
				else {
					dp[r] = max(dp[r], dp[r - 1]);
				}
				leftDown = backup;
			}
		}
		return dp[n - 1];
	}


	//	���뺯��
	// text1 = "bbbab"
	// text1 = "cbbd"
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
		int  res = longestPalindromeSubseq4(m_s1);
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