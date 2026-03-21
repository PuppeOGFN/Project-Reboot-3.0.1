#pragma once

#include <atomic>

#include "inc.h"

namespace Globals
{
	extern inline bool bCreative = false;
	extern inline bool bGoingToPlayEvent = false;
	extern inline bool bEnableAGIDs = true;
	extern inline bool bNoMCP = false;
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
	extern inline std::string BackendIP = "http://127.0.0.1:3551"; // this is used to get Teams working. (its mostly duos btw)
}

extern inline int NumToSubtractFromSquadId = 0; // I think 2?

extern inline std::string PlaylistName =
"/Game/Athena/Playlists/Showdown/Playlist_ShowdownAlt_Solo.Playlist_ShowdownAlt_Solo"; // Arena Solos
// "/Game/Athena/Playlists/Showdown/Playlist_ShowdownAlt_Duo.Playlist_ShowdownAlt_Duo"; // Arena Duos
// "/Game/Athena/Playlists/Playlist_DefaultSolo.Playlist_DefaultSolo"; // Normal Solos
// "/Game/Athena/Playlists/Playlist_DefaultDuo.Playlist_DefaultDuo"; // Normal Duos


extern inline std::string API_KEY = "YOUR_API_KEY";

extern inline std::string API_HYPE = "http://127.0.0.1:90";
extern inline std::string API_VBUCKS = "http://127.0.0.1:92";