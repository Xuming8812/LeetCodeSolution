#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>
#include<set>
#include<bitset>

using namespace std;

/*
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. 
You may assume all four edges of the grid are all surrounded by water.
*/

int numIslands(vector<vector<char>>& grid) {

	int result{ 0 };

	if (grid.empty())
	{
		return result;
	}
	
	vector<vector<int>> direction{ {0,1},{0,-1},{1,0},{-1,0} };

	for (int i{ 0 }; i < grid.size(); ++i)
	{
		for (int j{ 0 }; j < grid[0].size(); ++j)
		{
			if (grid[i][j] == '1')
			{
				result++;

				stack<vector<int>> store;
				store.push({ i,j });

				while (!store.empty())
				{
					vector<int> current = store.top();
					store.pop();

					grid[current[0]][current[1]] = '0';

					for (auto item : direction)
					{
						int m = current[0] + item[0];
						int n = current[1] + item[1];

						if (m >= 0 && m < grid.size() && n >= 0 && n < grid[0].size() && grid[m][n] == '1')
						{
							store.push({ m,n });
						}

					}
				}

			}
		}
	}

	return result;
}
