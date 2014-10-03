#include <iostream>
#include <string>

#include "HttpUtility.h"
using namespace std;
int main() {
	HttpRequest request;
	HttpResponse response;
	request.SetHost(L"http://www.cnblogs.com/ytjjyy/archive/2012/05/03/2480361.html");
	request.method = L"GET";
	/*
	wcout << request.server << endl;
	wcout << request.port << endl;
	wcout << request.method << endl;
	wcout << request.query << endl;
	wcout << request.contentType << endl;
	wcout << request.cookie << endl;
	*/
	bool rs = HttpQuery(request, response);
	wcout << "result = " << rs << endl;
	auto str = response.body;
	for each (char c in str) {
		cout << c;

	}
	cout << endl;
	system("pause");
	return 0;
}