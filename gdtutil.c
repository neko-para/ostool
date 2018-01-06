#include "gdt.h"

void gdtSet(gdtEntry* entry, dword base, dword limit, byte access, byte flag) {
	entry->base_lo = base;
	entry->base_mi = base >> 16;
	entry->base_hi = base >> 24;
	entry->limit_lo = limit;
	entry->limit_hi = limit >> 16;
	entry->flag = flag;
	entry->access = access;
}

void gdtSetPtr(gdtPtr* ptr, gdtEntry entrys[], word cnt) {
	ptr->limit = sizeof(gdtEntry) * cnt - 1;
	ptr->base = (dword)entrys;
}
