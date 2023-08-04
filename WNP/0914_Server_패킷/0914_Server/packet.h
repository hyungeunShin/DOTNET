//packet.h
//어플리케이션 프로토콜 정의
//고정 크기 패킷

#pragma once

#define PACK_SHORTMESSAGE	1

struct PACKET
{
	int flag;
	char name[20];
	char msg[100];
};
