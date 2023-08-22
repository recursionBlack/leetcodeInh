#include <vector>

using namespace std;

class Solution051 {
	vector<vector<string>> res;
public:
	vector<vector<string>> solveNQueens(int n) {
		vector<string> board(n, string(n, '.'));
		res.clear();
		backtrack(board, 0);
		return res;
	}

	void backtrack(vector<string>& board, int row)   //board表示每一列
	{
		//每一行都成功放了皇后，记录结果
		if (row == board.size())
		{
			res.push_back(board);
			return;
		}
		int n = board[row].size();
		for (int col = 0; col < n; col++)
		{
			if (!isvalid(board, row, col))
				continue;
			board[row][col] = 'Q';
			backtrack(board, row + 1);
			board[row][col] = '.';
		}
	}

	bool isvalid(vector<string>& board, int row, int col)
	{
		int n = board.size();
		//只需要检查3个方向，上方，左上，右上，是否有皇后，
		// 同一行不用考虑，因为每行只放一个皇后，下方也不用考虑，因为下方还没放
		//检查列是否有皇后互相冲突
		for (int i = 0; i < n; i++)
		{
			if (board[i][col] == 'Q')
			{
				return false;
			}
		}
		//检查左上方是否有皇后冲突
		for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
		{
			if (board[i][j] == 'Q')
			{
				return false;
			}
		}
		//检查右上方是否有皇后冲突
		for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
		{
			if (board[i][j] == 'Q')
			{
				return false;
			}
		}
		return true;
	}
};