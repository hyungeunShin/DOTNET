//packet.h
//���ø����̼� �������� ����
//���� ũ�� ��Ŷ

#pragma once

#define PACK_SHORTMESSAGE	1

struct PACKET
{
	int flag;
	char name[20];
	char msg[100];
};
