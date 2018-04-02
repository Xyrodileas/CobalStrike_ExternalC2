#pragma once
#include "stdafx.h"
#include <windows.h>
#include <string>
#include <stdio.h>


using std::string;

#pragma comment(lib,"ws2_32.lib")

using std::string;




class Comms_http
{
public:
	Comms_http(const char* c2);
	Comms_http();
	~Comms_http();

	char * readUrl2(long & bytesReturnedOut, char ** headerOut);

	

private:
	char *szUrl;
	char *mUrl;
	HINSTANCE hInst;
	
	SOCKET conn;
	string serverName;
	string filepath;
	string filename;

	const int bufLen = 1024;

	void mParseUrl(char* mUrl);

	int getHeaderLength(char * content);

	void connectToServer(char *szServerName, WORD portNum);


	// SSL
	br_ssl_client_context sc;
	br_x509_minimal_context xc;
	unsigned char iobuf[BR_SSL_BUFSIZE_BIDI];
	br_sslio_context ioc;
};

