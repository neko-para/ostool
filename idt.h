#ifndef _IDT_H_
#define _IDT_H_

#include "types.h"

struct idtEntry {
	word offset_lo;
	word selector;
	byte zero;
	byte access;
	word offset_hi;
} __attribute__((packed));

typedef struct idtEntry idtEntry;

struct idtPtr {
	word limit;
	dword base;
} __attribute__((packed));

typedef struct idtPtr idtPtr;

void idtUpdate(idtPtr* ptr);
void idtSet(idtEntry* entry, dword offset, word selector, byte access);
void idtSetPtr(idtPtr* idt, idtEntry entrys[], word cnt);

#endif
