#ifndef _GDT_H_
#define _GDT_H_

#include "types.h"

struct gdtEntry {
	word limit_lo;
	word base_lo;
	byte base_mi;
	byte access;
	struct {
		byte limit_hi : 4;
		byte flag : 4;
	};
	byte base_hi;
} __attribute__((packed));

typedef struct gdtEntry gdtEntry;

struct gdtPtr {
	word limit;
	dword base;
} __attribute__((packed));

typedef struct gdtPtr gdtPtr;

void gdtUpdate(gdtPtr* ptr, dword code_seg, dword data_seg);
void gdtSet(gdtEntry* entry, dword base, dword limit, byte access, byte flag);
void gdtSetPtr(gdtPtr* ptr, gdtEntry entrys[], word cnt);

#endif
