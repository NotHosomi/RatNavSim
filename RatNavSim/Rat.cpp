#include "Rat.h"



Rat::Rat(int nWhiskerCount)
{
	m_Sprite.SetTexture("Puck.png");
	m_nWhiskerCount = nWhiskerCount;
	for (int i = 0; i < m_nWhiskerCount; ++i)
	{
		m_vWhiskersLeft.emplace_back(Vector2<float>(40, 20 + 5 * i), -90 - 2*i, 100.0f - 5*i);
		m_vWhiskersRight.emplace_back(Vector2<float>(-40, 20 + 5 * i), 90 - 2*i, 100.0f - 5*i);
	}
}

void Rat::Update()
{
	// get spherical treadmill data
}

void Rat::Render()
{
	m_Sprite.Render();
	for (auto& whisker : m_vWhiskersLeft)
	{
		whisker.Render();
	}
	for (auto& whisker : m_vWhiskersRight)
	{
		whisker.Render();
	}
}

void Rat::Move(Vector2<float> tDelta, float fTheta)
{
	SetPos(m_tPos + tDelta);
	SetAngle(m_fAngle + fTheta);
}

void Rat::SetPos(Vector2<float> tPos)
{
	m_tPos = tPos;
	m_Sprite.SetX(m_tPos.x - m_Sprite.GetWidth() / 2.0f);
	m_Sprite.SetY(m_tPos.y - m_Sprite.GetHeight() / 2.0f);
}

void Rat::SetAngle(float fAngle)
{
	m_fAngle = fAngle;
	m_Sprite.SetRotation(fAngle);
}
