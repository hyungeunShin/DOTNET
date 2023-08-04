//packet.cpp

#include <string.h>
#include "packet.h"

PACKET pack_ShortMessag(const char* name, const char* msg)
{
	PACKET pack;
	pack.flag = PACK_SHORTMESSAGE;
	strcpy_s(pack.name, sizeof(pack.name), name);
	strcpy_s(pack.msg, sizeof(pack.msg), msg);

	return pack;
}