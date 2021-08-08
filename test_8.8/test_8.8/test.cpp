#define _CRT_SECURE_NO_WARNINGS 1

//leetcode 733 图像渲染
int nextP[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
class Solution {
public:
	void DFS(vector<vector<int>>& image, int row, int col, int oldColor
		, vector<vector<int>>& visited, int newx, int newy, int newColor)
	{
		//1.染色
		image[newx][newy] = newColor;
		visited[newx][newy] = 1;
		//2.搜索：上下左右
		for (int i = 0; i < 4; i++)
		{
			int nextx = newx + nextP[i][0];
			int nexty = newy + nextP[i][1];

			//3，判断位置：是否越界
			if (nextx < 0 || nextx >= row || nexty < 0 || nexty >= col)
				continue;

			//判断颜色是否符合要求，并且是否已经访问过
			if (image[nextx][nexty] == oldColor && visited[nextx][nexty] == 0)
				DFS(image, row, col, oldColor, visited, nextx, nexty, newColor);
		}
	}
	vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
		int row = image.size();
		int col = image[0].size();
		int oldColor = image[sr][sc];
		vector<vector<int>> visited(row, vector<int>(col, 0));
		DFS(image, row, col, oldColor, visited, sr, sc, newColor);
		return image;
	}
};


//leetcode 130 被围绕的区域
class Solution {
public:
	int nextP[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };

	void DFS(vector<vector<char>>& board, int row, int col, int x, int y)
	{
		//1.标记
		board[x][y] = 'a';
		//2.搜索
		for (int i = 0; i < 4; i++)
		{
			//搜索下一个位置：上下左右
			int newx = x + nextP[i][0];
			int newy = y + nextP[i][1];

			//判断越界
			if (newx < 0 || newx >= row || newy < 0 || newy >= col)
				continue;

			if (board[newx][newy] == 'O')
				DFS(board, row, col, newx, newy);
		}
	}

	void solve(vector<vector<char>>& board) {
		int row = board.size();
		int col = board[0].size();

		//先找到所有边上的O
		//以每个边上的O为起点，找到并标记每个与边上的O相连的O
		for (int i = 0; i < col; i++)
		{
			//第一行
			if (board[0][i] == 'O')
				DFS(board, row, col, 0, i);
			//最后一行
			if (board[row - 1][i] == 'O')
				DFS(board, row, col, row - 1, i);

		}
		for (int i = 1; i < row - 1; i++)
		{
			//第一列
			if (board[i][0] == 'O')
				DFS(board, row, col, i, 0);
			//最后一列
			if (board[i][col - 1] == 'O')
				DFS(board, row, col, i, col - 1);
		}

		//替换符合条件的O，恢复不符合条件的O
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				if (board[i][j] == 'O')
					board[i][j] = 'X';
				else if (board[i][j] == 'a')
					board[i][j] = 'O';
			}
		}


	}
};

//leetcode 200 岛屿数量
class Solution {
public:

	int nextP[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };

	void DFS(vector<vector<char>>& grid, int row, int col
		, vector<vector<int>>& visited, int x, int y)
	{
		//1.标记
		visited[x][y] = 1;
		//2.搜索新的位置：上下左右
		for (int i = 0; i < 4; i++)
		{
			int newx = x + nextP[i][0];
			int newy = y + nextP[i][1];

			if (newx < 0 || newx >= row || newy < 0 || newy >= col)
				continue;

			if (grid[newx][newy] == '1' && visited[newx][newy] == 0)
			{
				DFS(grid, row, col, visited, newx, newy);
			}
		}
	}

	int numIslands(vector<vector<char>>& grid) {
		int step = 0;
		int row = grid.size();
		if (row == 0)
			return 0;
		int col = grid[0].size();
		vector<vector<int>> visited(row, vector<int>(col, 0));

		//对全部的岛屿进行遍历
		//并标记访问过的岛屿
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				if (grid[i][j] == '1' && visited[i][j] == 0)
				{
					++step;
					DFS(grid, row, col, visited, i, j);
				}
			}
		}
		return step;
	}
};