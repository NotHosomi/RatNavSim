#pragma once
#include <array>
#include <ASGF/Sprite.h>
#include <ASGF/Line.h>
#include "Whisker.h"


class Rat
{
public:
	Rat(int nWhiskerCount);
	void Update();
	void Render();

	void Move(Vector2<float> tDelta, float fTheta);
	void SetPos(Vector2<float> tPos);
	void SetAngle(float fAngle);

private:
	Vector2<float> m_tPos = { 0,0 };
	float m_fAngle = 0;

	int m_nWhiskerCount;
	std::vector<Whisker> m_vWhiskersLeft;
	std::vector<Whisker> m_vWhiskersRight;
	Sprite m_Sprite;
};

