// Copyright (c) 2012- PPSSPP Project.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, version 2.0 or later versions.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License 2.0 for more details.

// A copy of the GPL 2.0 should have been included with the program.
// If not, see http://www.gnu.org/licenses/

// Official git repository and contact information can be found at
// https://github.com/hrydgard/ppsspp and http://www.ppsspp.org/.

#pragma once

#include "Common/ChunkFile.h"


// Protocol Families
#define AF_INET 2

// Socket Types
//#define SOCK_STREAM 1
//#define SOCK_DGRAM 2

// Protocols
//#define IPPROTO_TCP 6
//#define IPPROTO_UDP 17

// Option Level
//#define SOL_SOCKET 0xFFFF

// Option Names
//#define SO_REUSEADDR 0x0004
// #define SO_REUSEPORT 0x0200
// #define SO_SNDTIMEO 0x1005
// #define SO_RCVTIMEO 0x1006
// #define SO_TYPE 0x1008
// #define SO_NBIO 0x1009

// IP Macros
#define INADDR_ANY 0

// On-Demand Nonblocking Flag
#define INET_MSG_DONTWAIT 0x80

// Event Flags
#define INET_POLLRDNORM 0x0040
#define INET_POLLWRNORM 0x0004

// Infrastructure Errno Numbers
//#define EAGAIN 0x0B
//#define ETIMEDOUT 0x74
//#define EINPROGRESS 0x77
//#define EISCONN 0x7F

// Sockaddr
struct SceNetInetSockaddr {
	uint8_t sa_len;
	uint8_t sa_family;
	uint8_t sa_data[14];
};

// Sockaddr_in
struct SceNetInetSockaddrIn {
	uint8_t sin_len;
	uint8_t sin_family;
	uint16_t sin_port;
	uint32_t sin_addr;
	uint8_t sin_zero[8];
};

// Polling Event Field
struct SceNetInetPollfd {
	int fd;
	short events;
	short revents;
};


void Register_sceNet();
void Register_sceWlanDrv();

void __NetInit();
void __NetShutdown();
void __NetDoState(PointerWrap &p);
