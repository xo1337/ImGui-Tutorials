#include "functions.h"

void Functions::Inject(std::string game)
{
	if (game == "game_name")
	{
		// Do your injection code :)
	}
}

void Functions::Rainbow()
{
	//This function was not made by me (xo1337), i found it off unknown cheats.
	float rainbowSpeed = 0.00060;
	static float staticHue = 0;
	ImDrawList* draw_list = ImGui::GetWindowDrawList();
	ImVec2 panelPos = ImGui::GetWindowPos();
	staticHue -= rainbowSpeed;
	if (staticHue < -1.f) staticHue += 1.f;
	for (int i = 0; i < 1200; i++)
	{
		float hue = staticHue + (1.f / (float)1200) * i;
		if (hue < 0.f) hue += 1.0f;
		ImColor cRainbow = ImColor::HSV(hue, 1.f, 1.f);
		draw_list->AddRectFilled(ImVec2(panelPos.x + i, panelPos.y + 2), ImVec2(panelPos.x + i + 1, panelPos.y + 4), cRainbow);
	}
}

void Functions::Line(const char* Id, int width = ImGui::GetContentRegionAvailWidth(), int height = 1)
{
	ImGui::BeginChild(Id, ImVec2(width, height), TRUE);
	ImGui::EndChild();
}

void Functions::LineEx(const char* Id)
{
	Functions::Line(Id, ImGui::GetContentRegionAvailWidth(), 1);
}

void Functions::LineVertical()
{
	ImGui::SeparatorEx(ImGuiSeparatorFlags_Vertical);
}

void Functions::Helpmarker(const char* Text, ImColor Color)
{
	ImGui::TextColored(Color, "(?)");
	if (ImGui::IsItemHovered())
		ImGui::SetTooltip(Text);
}