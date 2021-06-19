#pragma once
#include <Windows.h>
#include <iostream>
#include <imgui.h>
#include <imgui_internal.h>

enum GAME_STATUS
{
	UNDETECTED,
	UPDATING,
	DETECTED,
	COMING_SOON
};

namespace Functions
{
	void Rainbow();
	void Helpmarker(const char* Text, ImColor Color);
	void Line(const char* Id, int width, int height);
	void LineEx(const char* Id);
	void LineVertical();

	void Inject(std::string game);
}

