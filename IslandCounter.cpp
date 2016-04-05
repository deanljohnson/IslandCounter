#include "stdafx.h"
#include <ctime>
#include <type_traits>
#include <vector>
#include "IslandGenerator.h"
#include <iostream>

using namespace std;

void DisplayMap(vector<vector<int>>& map)
{
	for (auto j = 0; j < map.size(); j++)
	{
		for (auto i = 0; i < map[j].size(); i++)
		{
			cout << map[j][i] << " ";
		}

		cout << "\n";
	}
}

bool isOnMap(vector<vector<int>>& map, int x, int y)
{
	return x >= 0 && y >= 0 && x < map.size() && y < map[0].size();
}

void DFS(vector<vector<int>>& map, int x, int y, int lookingFor, vector<vector<bool>>& visited)
{
	int xOffset[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
	int yOffset[] = {-1, 0, 1, -1, 1, -1, 0, 1};

	visited[x][y] = true;

	for (auto i = 0; i < 8; i++)
	{
		if (isOnMap(map, x + xOffset[i], y + yOffset[i]) && map[x + xOffset[i]][y + yOffset[i]] == lookingFor && !visited[x + xOffset[i]][y + yOffset[i]])
		{
			DFS(map, x + xOffset[i], y + yOffset[i], lookingFor, visited);
		}
	}
}

int main()
{
	const auto size = 30;

	srand(time(nullptr));

	auto gen = IslandGenerator();

	auto map = vector<vector<int>>(size);
	for (auto i = 0; i < size; i++)
	{
		map[i] = vector<int>(size);
	}

	gen.Generate(map);

	DisplayMap(map);

	vector<vector<bool>> visited(size, vector<bool>(size, 0));

	auto count = 0;
	for (auto j = 0; j < size; j++)
	{
		for (auto i = 0; i < size; i++)
		{
			if (map[i][j] == 1 && !visited[i][j])
			{
				DFS(map, i, j, 1, visited);
				count++;
			}
		}
	}

	cout << count;

	cin.get();
}
