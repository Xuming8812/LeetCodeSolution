#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>
#include<set>

using namespace std;

/*
A 3 x 3 magic square is a 3 x 3 grid filled with distinct numbers from 1 to 9 such that each row, column, and both diagonals all have the same sum.

Given an grid of integers, how many 3 x 3 "magic square" subgrids are there?  (Each subgrid is contiguous).
*/

bool isMagic(vector<vector<int>>& grid, int row, int col)
{
	//check whether the center is 5
	if (grid[row + 1][col + 1] != 5)
	{
		return false;
	}

	//check whether the matrix contains 1 to 9 and no duplicates
	set<int> store;

	for (int i = row; i <= row + 2; i++)
	{
		for (int j = col; j <= col + 2; j++)
		{
			store.insert(grid[i][j]);
		}
	}

	if (store.size() != 9)
	{
		return false;
	}

	auto mm = minmax_element(store.begin(), store.end());

	if (*mm.first != 1 || *mm.second != 9)
	{
		return false;
	}

	//check whether sum of each row is 15
	for (int i = 0; i < 3; i++)
	{
		if (grid[row + i][col] + grid[row + i][col + 1] + grid[row + i][col + 2] != 15)
		{
			return false;
		}
	}
	//check whether sum of each col is 15
	for (int i = 0; i < 3; i++)
	{
		if (grid[row][col + i] + grid[row + 1][col + i] + grid[row + 2][col + i] != 15)
		{
			return false;
		}
	}
	//check whether diagonal sum is 15
	if (grid[row][col] + grid[row + 2][col + 2] != 10 || grid[row][col + 2] + grid[row + 2][col] != 10)
	{
		return false;
	}

	return true;
}

int numMagicSquaresInside(vector<vector<int>>& grid)
{
	if (grid.size() < 3 || grid[0].size() < 3)
	{
		return 0;
	}

	int result{ 0 };

	for (int row = 0; row + 2 < grid.size(); row++)
	{
		for (int col = 0; col + 2 < grid[0].size(); col++)
		{
			if (isMagic(grid, row, col))
			{
				result++;
			}
		}
	}

	return result;
}

