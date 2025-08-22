#pragma once
#include <ASGF/Vector2.h>
#include <ASGF/Line.h>

class Whisker
{
public:
	Whisker(Vector2<float> tRootOffset, float fAngle, float fLength);

	void OnHeadMove(Vector2<float> tHeadPos, float fHeadAngle);
	float CheckCollisions(Vector2<float> tRootPos, Vector2<float> tTipPos);

	void Render();
private:
	Vector2<float> m_tRootOffset; // the offset of the root from the head
	Vector2<float> m_tTipOffset; // the offset of the tip from the root

	Line m_vfx;
};

