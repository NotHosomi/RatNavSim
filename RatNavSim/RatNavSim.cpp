// RatNavSim.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <ASGF/Window.h>
#include "Sim.h"

const uint16_t SCREEN_WIDTH = 1280;
const uint16_t SCREEN_HEIGHT = 720;

int main(int argc, char* argv[])
{
	Window w(SCREEN_WIDTH, SCREEN_HEIGHT);
	w.SetWindowTitle("RatNavSim");

	Sim sim;

	w.Run(std::bind(&Sim::Update, &sim),
		std::bind(&Sim::Render, &sim));

	w.Close();
	return 0;
}
