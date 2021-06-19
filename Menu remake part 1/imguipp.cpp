#include "imguipp.h"
namespace imguipp
{

	float getx()
	{
		return ImGui::GetContentRegionAvail().x;
	}

	float gety()
	{
		return ImGui::GetContentRegionAvail().y;
	}

	void button(const char* label, int& currentTab, int newTab, ImVec2 size)
	{
		if (ImGui::Button(label, size))
			currentTab = newTab;
	}

	void line(int newId)
	{
		std::string id = ("imguipp_line_" + std::to_string(newId));
		ImGui::PushStyleColor(ImGuiCol_ChildBg, IM_COL32(0, 0, 0, 0));
		{
			ImGui::BeginChild(id.c_str(), ImVec2(ImGui::GetContentRegionAvail().x, 1), false);
			ImGui::Separator();
			ImGui::EndChild();
		}
		ImGui::PopStyleColor();
	}

	void linevertical()
	{
		ImGui::SameLine();
		ImGui::SeparatorEx(ImGuiSeparatorFlags_Vertical);
		ImGui::SameLine();
	}

	void center_text(const char* text, int lineId , bool separator)
	{
		if (text == nullptr)
			return;

		ImGui::Spacing();
		ImGui::SameLine((ImGui::GetContentRegionAvail().x / 2) - (ImGui::CalcTextSize(text).x / 2));
		ImGui::Text(text);
		ImGui::Spacing();

		if (true == separator)
			line(lineId);
	}

	void center_text_ex(const char* text, float width_available, int lineId,  bool separator)
	{
		if (text == nullptr)
			return;

		ImGui::Spacing();
		ImGui::SameLine((width_available / 2) - (ImGui::CalcTextSize(text).x / 2));
		ImGui::Text(text);
		ImGui::Spacing();

		if (true == separator)
			line(lineId);
	}

	namespace other
	{
		float get_window_size_x()
		{
			return ImGui::GetWindowSize().x;
		}

		float get_window_size_y()
		{
			return ImGui::GetWindowSize().y;
		}

		ImVec2 get_window_size()
		{
			return ImGui::GetWindowSize();
		}

		char* get_window_name()
		{
			return ImGui::GetCurrentWindow()->Name;
		}

		ImDrawList* get_drawlist()
		{
			return ImGui::GetCurrentWindow()->DrawList;
		}
	}

	ImVec4 to_vec4(float r, float g, float b, float a)
	{
		return ImVec4(r / 255.0, g / 255.0, b / 255.0, a / 255.0);
	}
}