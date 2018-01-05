#include "gdt.h"

void gdtSet(gdtEntry* entry, dword base, dword limit, byte access, byte granularity) {
	entry->base_low = base;
	entry->base_middle = base >> 16;
	entry->base_high = base >> 24;
	entry->limit_low = limit;
	entry->granularity = ((limit >> 16) & 0x0F) | (granularity & 0xF0);
	entry->access = access;
}

void gdtSetPtr(gdtPtr* ptr, gdtEntry entrys[], word cnt) {
	ptr->limit = sizeof(gdtEntry) * cnt - 1;
	ptr->base = (dword)entrys;
}