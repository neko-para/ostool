#ifndef _HD_H_
#define _HD_H_

#include "types.h"

#define HD_STATUS_ERR (1 << 0)
#define HD_STATUS_DRQ (1 << 3)
#define HD_STATUS_SRV (1 << 4)
#define HD_STATUS_DF  (1 << 5)
#define HD_STATUS_RDY (1 << 6)
#define HD_STATUS_BSY (1 << 7)

byte hdStatus();
word hdRead(bit drive, byte sects, dword offset, void* data);
word hdWrite(bit drive, byte sects, dword offset, const void* data);

#endif
