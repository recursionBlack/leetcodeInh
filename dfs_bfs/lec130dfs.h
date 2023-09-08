#include <vector>

using namespace std;

class Solution130dfs {
public:
	int n, m;

	void dfs(vector<vector<char>>& board, int x, int y) {
		//越界了直接return
		if (x < 0 || x >= n || y < 0 || y >= m || board[x][y] != 'O') {
			return;
		}
		board[x][y] = 'A';	// 把与边界相接的’O‘改为'A'
		// 往4个方向上蔓延
		dfs(board, x + 1, y);
		dfs(board, x - 1, y);
		dfs(board, x, y + 1);
		dfs(board, x, y - 1);
	}

	void solve(vector<vector<char>>& board) {
		n = board.size();
		if (n == 0) {
			return;
		}
		m = board[0].size();
		// 直接在上下两条边上找'O'
		for (int i = 0; i < n; i++) {
			dfs(board, i, 0);
			dfs(board, i, m - 1);
		}
		//在左右两边界上找'O'
		for (int i = 1; i < m - 1; i++) {
			dfs(board, 0, i);
			dfs(board, n - 1, i);
		}

		// 全局遍历一遍，把'A'变'O'，'O'变'X'
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (board[i][j] == 'A') {
					board[i][j] = 'O';
				}
				else if (board[i][j] == 'O') {
					board[i][j] = 'X';
				}
			}
		}
	}
};