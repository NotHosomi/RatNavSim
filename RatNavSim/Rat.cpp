#include "Rat.h"


#define DEG2RAD(x) x * M_PI / 180 

Rat::Rat(int nWhiskerCount)
{
	m_Sprite.SetTexture("Puck.png");
	m_nWhiskerCount = nWhiskerCount;
	for (int i = 0; i < m_nWhiskerCount; ++i)
	{
		m_vWhiskersLeft.emplace_back(Vector2<float>(40, 20 + 5 * i), -90 - 2*i, 100.0f - 5*i);
		m_vWhiskersRight.emplace_back(Vector2<float>(-40, 20 + 5 * i), 90 - 2*i, 100.0f - 5*i);
	}
	SetPos({ 0,0 });
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
	tDelta.Rotate(DEG2RAD(m_fAngle));
	SetPos(m_tPos + tDelta);
	SetAngle(m_fAngle + fTheta);

	for (auto& w : m_vWhiskersLeft)
	{
		w.OnHeadMove(m_tPos, m_fAngle);
	}
	for (auto& w : m_vWhiskersRight)
	{
		w.OnHeadMove(m_tPos, m_fAngle);
	}
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
