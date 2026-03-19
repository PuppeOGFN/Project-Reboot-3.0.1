#pragma once

#include <atomic>

#include "inc.h"

namespace Globals
{
	extern inline bool bCreative = false;
	extern inline bool bGoingToPlayEvent = false;
	extern inline bool bEnableAGIDs = true;
	extern inline bool bNoMCP = true;
	extern inline bool bLogProcessEvent = false;
	// extern inline bool bLateGame = false;
	extern inline std::atomic<bool> bLateGame(false);

	extern inline bool bInfiniteMaterials = false;
	extern inline bool bInfiniteAmmo = false;
	extern inline bool bShouldUseReplicationGraph = false;

	extern inline bool bHitReadyToStartMatch = false;
	extern inline bool bInitializedPlaylist = false;
	extern inline bool bStartedListening = false;
	extern inline bool bAutoRestart = false; // doesnt work fyi
	extern inline bool bFillVendingMachines = true;
	extern inline bool bPrivateIPsAreOperator = true;
	extern inline int AmountOfListens = 0; // TODO: Switch to this for LastNum
	extern inline bool bDeveloperMode = false;
}

extern inline int NumToSubtractFromSquadId = 0; // I think 2?

extern inline std::string PlaylistName =
"/Game/Athena/Playlists/Playlist_DefaultSolo.Playlist_DefaultSolo";


extern inline std::string API_KEY = "your-api-key-here";

extern inline std::string API_HYPE = "http://127.0.0.1:90";
extern inline std::string API_SEASONUMBRELLA = "http://127.0.0.1:91";
extern inline std::string API_VBUCKS = "http://127.0.0.1:92";
extern inline std::string API_XP = "http://127.0.0.1:93";