#pragma once
#include <string>
#include <vector>
#include <ASGF/Vector2.h>
#include <ASGF/Line.h>

struct T_Wall
{
	Vector2<float> tStart;
	Vector2<float> tEnd;
};

class Environment
{
private:
	Environment() = default;
public:
	static Environment& Get();

	void Render();

	const std::vector<T_Wall>& GetWallData();


	void LoadMap(std::string fileaddress);
	void AddWall(Vector2<float> tStart, Vector2<float> tEnd);
	void ContinueWall(Vector2<float> tNextPos);
	void AddWallSeries(std::vector<Vector2<float>> vNodes);
private:
	std::vector<T_Wall> m_vWallData;
	std::vector<Line> m_vVfx;

	Vector2<float> m_tLastPoint;
};

