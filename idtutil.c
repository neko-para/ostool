#include "idt.h"

void idtSet(idtEntry* entry, dword offset, word selector, byte access) {
	entry->offset_lo = offset;
	entry->offset_hi = offset >> 16;
	entry->selector = selector;
	entry->zero = 0;
	entry->access = access;
}

void idtSetPtr(idtPtr* idt, idtEntry entrys[], word cnt) {
	idt->limit = sizeof(idtEntry) * cnt - 1;
	idt->base = (unsigned)&entrys;
}
