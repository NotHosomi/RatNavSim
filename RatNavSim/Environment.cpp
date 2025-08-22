#include "Environment.h"
#include <filesystem>
#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>

Environment& Environment::Get()
{
	static Environment instance;
	return instance;
}

const std::vector<T_Wall>& Environment::GetWallData()
{
	return m_vWallData;
}

void Environment::LoadMap(std::string fileaddress)
{
	using namespace nlohmann;
	if (!std::filesystem::exists(fileaddress))
	{
		std::cerr << "Could not find envionment file" << fileaddress << std::endl;
		return;
	}
	std::ifstream file(fileaddress);
	json j = json::parse(file);
	for (auto& jWallChain : j.at("Walls"))
	{
		std::vector<Vector2<float>> vNodes;
		for (auto& jNode : jWallChain)
		{
			vNodes.emplace_back(jNode.at("X").get<float>(), jNode.at("Y").get<float>());
		}
		AddWallSeries(vNodes);
	}
}

void Environment::AddWall(Vector2<float> tStart, Vector2<float> tEnd)
{
	m_vWallData.emplace_back(tStart, tEnd);
	m_vVfx.emplace_back(tStart.cast<int>(), tEnd.cast<int>());

	m_tLastPoint = tEnd;
}

void Environment::ContinueWall(Vector2<float> tNextPos)
{
	AddWall(m_tLastPoint, tNextPos);
}

void Environment::AddWallSeries(std::vector<Vector2<float>> vNodes)
{
	for (int i = 1; i < vNodes.size(); ++i)
	{
		AddWall(vNodes[i - 1], vNodes[i]);
	}
}

void Environment::Render()
{
	for (auto& line : m_vVfx)
	{
		line.Render();
	}
}
