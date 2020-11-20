#include "il2cpp-appdata.h"
#include "_events.h"
#include "utility.h"

CastVoteEvent::CastVoteEvent(EVENT_PLAYER source, std::optional<EVENT_PLAYER> target) : EventInterface(source, EVENT_VOTE)
{
	this->target = target;
}

void CastVoteEvent::Output()
{
	ImGui::TextColored(AmongUsColorToImVec4(GetPlayerColor(source.colorId)), source.playerName);
	ImGui::SameLine();
	ImGui::Text(">");
	ImGui::SameLine();

	if (target.has_value())
		ImGui::TextColored(AmongUsColorToImVec4(GetPlayerColor(target->colorId)), target->playerName);
	else
		ImGui::Text("Skipped");
}

void CastVoteEvent::ColoredEventOutput()
{
	ImGui::Text("[ VOTE ]");
}