#ifndef _IO_H_
#define _IO_H_

#include "types.h"

byte In8(word port);
word In16(word port);
dword In32(word port);

void Ins8(word port, dword count, void* data);
void Ins16(word port, dword count, void* data);
void Ins32(word port, dword count, void* data);

void Out8(word port, byte data);
void Out16(word port, word data);
void Out32(word port, dword data);

void Outs8(word port, dword count, const void* data);
void Outs16(word port, dword count, const void* data);
void Outs32(word port, dword count, const void* data);

void Hlt();

#endif
