#ifndef _GDT_H_
#define _GDT_H_

#include "types.h"

struct gdtEntry {
	word limit_low;
	word base_low;
	byte base_middle;
	byte access;
	byte granularity;
	byte base_high;
} __attribute__((packed));

typedef struct gdtEntry gdtEntry;

struct gdtPtr {
	word limit;
	dword base;
} __attribute__((packed));

typedef struct gdtPtr gdtPtr;

void gdtUpdate(gdtPtr* ptr);
void gdtSet(gdtEntry* entry, dword base, dword limit, byte access, byte granularity);
void gdtSetPtr(gdtPtr* ptr, gdtEntry entrys[], word cnt);

#endif