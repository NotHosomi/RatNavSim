#include "Sim.h"
#include <ASGF/Camera.h>
#include <ASGF/Window.h>
#include <ASGF/Input.h>
#include "Environment.h"

Sim::Sim() :
	m_Rat(5)
{
	new Camera(Window::GetMainWindow()->GetWidth(), Window::GetMainWindow()->GetHeight());
	T_CameraConfig tCamConfig = {
		.bEnableRecenter = true,
		.eRecenter = E_Keys::C,
		.bEnableEdgePan = true,
		.nEdgePanThreshold = 20,
		.bEnableKeyMovement = true,
		.eUp = E_Keys::W,
		.eLeft = E_Keys::A,
		.eDown = E_Keys::S,
		.eRight = E_Keys::D,
		.bEnableGrabPan = false,
		.uDragButton = 1,
		.bEnableSpeedup = true,
		.eSpeedup = E_Keys::ShiftL,
	};
	Camera::GetMainCamera()->SetConfig(tCamConfig);


	m_vLines.emplace_back(Vector2<int>{ 0,0 }, Vector2<int>{ 100,-100 });
	m_vLines.back().SetColour(Colours::Cyan);

	m_vLines.emplace_back(Vector2<int>{ -100, 0 }, Vector2<int>{ 100, -200 });
	m_vLines.back().SetColour(Colours::Green);

	m_vLines.emplace_back(Vector2<int>{ -200, -200 }, Vector2<int>{ 200, 200 });
	m_vLines.back().SetColour(Colours::Magenta);

	Environment::Get().LoadMap("env.json");

	demorat.SetTexture("Rat1.png");
	demorat.SetHeight(100);
	demorat.SetWidth(100);
	demorat.SetX(200);
	demorat.SetY(200);
}

void Sim::Update()
{
	Camera::GetMainCamera()->Update();

	if (Input::Instance()->GetKeyDown(E_Keys::R))
	{
		m_Rat.Move({ 0,0 }, 1);
	}
}

void Sim::Render()
{
	demorat.Render();
	for (auto& l : m_vLines)
	{
		l.Render();
	}

	m_Rat.Render();
	Environment::Get().Render();
}
