#pragma once
#include <vector>
#include "ASGF/Line.h"
#include "ASGF/Sprite.h"
#include "Rat.h"

class Sim
{
public:
	Sim();
	void Update();
	void Render();

private:
	Rat m_Rat;

	std::vector<Line> m_vLines;
	Sprite demorat;
};

