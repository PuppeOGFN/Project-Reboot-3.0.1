#pragma once

#include <string>
#include <thread>
#ifdef CURL_H
#include "../vendor/curl/curl.h"
#else
#include <curl/curl.h>
#endif

#include "globals.h"

// Callback for curl to write response data
static size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp)
{
	((std::string*)userp)->append((char*)contents, size * nmemb);
	return size * nmemb;
}

// Generic API call function
static void CallAPIAsync(const std::string& host, const std::string& endpoint, const std::string& username, const std::string& reason)
{
	std::thread([host, endpoint, username, reason]()
	{
		try
		{
			CURL* curl = curl_easy_init();
			if (!curl)
				return;

			// Build the URL
			std::string url = host + endpoint + username + "/" + reason;

			// Prepare response buffer
			std::string readBuffer;

			// Set curl options
			curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
			curl_easy_setopt(curl, CURLOPT_TIMEOUT, 5L);
			curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
			curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void*)&readBuffer);

			// Set custom header with API key
			struct curl_slist* headers = nullptr;
			headers = curl_slist_append(headers, ("x-api-key: " + API_KEY).c_str());
			curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

			// Perform the request
			CURLcode res = curl_easy_perform(curl);

			// Cleanup
			if (headers)
				curl_slist_free_all(headers);
			curl_easy_cleanup(curl);
		}
		catch (const std::exception& e)
		{
			// Silently handle errors to not disrupt gameplay
		}
	}).detach();
}

// Convenience functions for each reward type
static void CallHypeAPIAsync(const std::string& username, const std::string& reason)
{
	CallAPIAsync(API_HYPE, "/api/v1/rewards/managehype/", username, reason);
}

static void CallSeasonUmbrellaAPIAsync(const std::string& username, const std::string& reason)
{
	CallAPIAsync(API_SEASONUMBRELLA, "/api/v1/rewards/manageseasonumbrella/", username, reason);
}

static void CallVbucksAPIAsync(const std::string& username, const std::string& reason)
{
	CallAPIAsync(API_VBUCKS, "/api/v1/rewards/managevbucks/", username, reason);
}

static void CallXPAPIAsync(const std::string& username, const std::string& reason)
{
	CallAPIAsync(API_XP, "/api/v1/rewards/managexp/", username, reason);
}
