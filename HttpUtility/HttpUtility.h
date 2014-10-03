#pragma once

#include <vector>
#include <deque>
#include <string>
#include <map>

/***********************************************************************
HTTP Utility
***********************************************************************/

class HttpRequest {
	typedef std::vector<char>							BodyBuffer;
	typedef std::deque<std::wstring>					StringList;
	typedef std::map<std::wstring, std::wstring>		HeaderMap;
public:
	std::wstring				server;
	int							port;
	std::wstring				query;
	bool						secure;
	std::wstring				username;
	std::wstring				password;
	std::wstring				method;
	std::wstring				cookie;
	BodyBuffer					body;
	std::wstring				contentType;
	StringList					acceptTypes;
	HeaderMap					extraHeaders;

	HttpRequest();
	bool						SetHost(const std::wstring& inputQuery);
	void						SetBodyUtf8(const std::wstring& bodyString);
};

class HttpResponse {
	typedef std::vector<char>					BodyBuffer;
public:	
	int							statusCode;
	BodyBuffer					body;
	std::wstring				cookie;

	HttpResponse();
	std::wstring				GetBodyUtf8();
};

extern bool					HttpQuery(const HttpRequest& request, HttpResponse& response);
extern std::wstring			UrlEncodeQuery(const std::wstring& query);
