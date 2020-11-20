#include "il2cpp-appdata.h"
#include "_events.h"
#include "utility.h"

ReportDeadBodyEvent::ReportDeadBodyEvent(PlayerControl* player, GameData_PlayerInfo* target, app::Vector2 position) : EventInterface(player, EVENT_REPORT_DEADBODY) {
	this->target = target;
	this->position = position;
	this->systemType = GetSystemTypes(position);
}

void ReportDeadBodyEvent::Output() {
	std::stringstream outputStream;
	outputStream
		<< "("
		<< TranslateSystemTypes(systemType)
		<< ")";
	ImGui::TextColored(AmongUsColorToImVec4(GetPlayerColor(GetPlayerData(getSource())->fields.ColorId)),
		convert_from_string(getSource()->fields._cachedData->fields.PlayerName).c_str());
	ImGui::SameLine();
	ImGui::Text(">");
	ImGui::SameLine();
	ImGui::TextColored(AmongUsColorToImVec4(GetPlayerColor(target->fields.ColorId)),
		convert_from_string(target->fields.PlayerName).c_str());
	ImGui::SameLine();
	ImGui::Text(outputStream.str().c_str());
}

void ReportDeadBodyEvent::ColoredEventOutput() {
	ImGui::Text("[");
	ImGui::SameLine();
	ImGui::TextColored(ImVec4(255, 140, 0, 255), "REPORT");
	ImGui::SameLine();
	ImGui::Text("]");
}