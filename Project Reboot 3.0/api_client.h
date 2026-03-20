#pragma once

#include <string>
#include <thread>
#ifdef CURL_H
#include "../vendor/curl/curl.h"
#else
#include <curl/curl.h>
#endif

#include "globals.h"

static size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp)
{
	((std::string*)userp)->append((char*)contents, size * nmemb);
	return size * nmemb;
}

static void CallAPIAsync(const std::string& host, const std::string& endpoint, const std::string& username, const std::string& reason)
{
	std::thread([host, endpoint, username, reason]()
	{
		try
		{
			CURL* curl = curl_easy_init();
			if (!curl)
				return;

			std::string url = host + endpoint + username + "/" + reason;

			std::string readBuffer;

			curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
			curl_easy_setopt(curl, CURLOPT_TIMEOUT, 5L);
			curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
			curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void*)&readBuffer);

			struct curl_slist* headers = nullptr;
			headers = curl_slist_append(headers, ("x-api-key: " + API_KEY).c_str());
			curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

			CURLcode res = curl_easy_perform(curl);

			if (headers)
				curl_slist_free_all(headers);
			curl_easy_cleanup(curl);
		}
		catch (const std::exception& e)
		{

		}
	}).detach();
}

static void CallHypeAPIAsync(const std::string& username, const std::string& reason)
{
	CallAPIAsync(API_HYPE, "/api/v1/rewards/managehype/", username, reason);
}

static void CallVbucksAPIAsync(const std::string& username, int amount)
{
	CallAPIAsync(API_VBUCKS, "/api/v1/rewards/vbucks/", username, std::to_string(amount));
}
