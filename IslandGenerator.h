#pragma once
#include <vector>

class IslandGenerator
{
private:

public:
	IslandGenerator();
	~IslandGenerator();

	void Generate(std::vector<std::vector<int>>& map);
};