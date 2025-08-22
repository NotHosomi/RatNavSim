#include "Whisker.h"
#include "Environment.h"

#define DEG2RAD(x) x * M_PI / 180 
Whisker::Whisker(Vector2<float> tOffset, float fAngle, float fLength)
{
	m_tRootOffset = tOffset;
	m_tTipOffset = { 0, fLength };
	m_tTipOffset.Rotate(DEG2RAD(fAngle));
}

void Whisker::OnHeadMove(Vector2<float> tHeadPos, float fHeadAngle)
{
	// update positions
	Vector2<float> rootPos = tHeadPos + m_tRootOffset.Rotation(fHeadAngle);
	Vector2<float> tipPos = rootPos + m_tTipOffset.Rotation(fHeadAngle);
	m_vfx.SetStart(rootPos.cast<int>());
	m_vfx.SetEnd(tipPos.cast<int>());

	if(CheckCollisions(rootPos, tipPos) > 0)
	{
		m_vfx.SetColour(Colours::Red);
	}
	else
	{
		m_vfx.SetColour(Colours::Blue);
	}
}

float Whisker::CheckCollisions(Vector2<float> tRootPos, Vector2<float> tTipPos)
{
	float deepest = 0;
	float depth = 0;
	for (auto& wall : Environment::Get().GetWallData())
	{
		depth = 1;
		if (depth > deepest)
		{
			deepest = depth;
		}
	}
	return deepest;
}

void Whisker::Render()
{
	m_vfx.Render();
}
