#ifndef _RAWHID_H_
#define _RAWHID_H_
#include "stdint.h"

#define PACK_SIZE 64
void RawHID_send(uint8_t *buffer, uint32_t length);
uint32_t RawHID_recv(uint8_t *buffer, uint32_t length);

#endif
