#include "console.hpp"

namespace ConsoleGui {
	void Init() {
		ImGui::SetNextWindowSize(ImVec2(400, 400), ImGuiCond_Once);
		ImGui::SetNextWindowBgAlpha(1.F);
	}

	bool init = false;
	void Render() {
		if (!init)
			ConsoleGui::Init();

		ImGui::Begin("Console", &State.ShowConsole, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize);
		ImGui::BeginChild("console#scroll", ImVec2(0, -22 * ImGui::GetIO().FontGlobalScale), false, ImGuiWindowFlags_HorizontalScrollbar);
		for (EventInterface* e : State.events) {
			ImGui::Text(e->Output().c_str());
		}
		ImGui::EndChild();
		ImGui::End();
	}
}