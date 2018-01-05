#include "hd.h"
#include "io.h"

byte hdStatus() {
	return In8(0x01F7);
}

word hdRead(bit drive, byte sects, dword offset, void* data) {
	unsigned i;
	drive &= 1;
	offset &= 0xFFFFFFF;
	Out8(0x01F6, 0xE0 | (drive << 4) | ((offset >> 24) & 0xF));
	Out8(0x01F2, sects);
	Out8(0x01F3, offset);
	Out8(0x01F4, offset >> 8);
	Out8(0x01F5, offset >> 16);
	Out8(0x01F7, 0x20);
	for (i = 0; i < sects; ++i) {
		while (1) {
			byte status = hdStatus();
			if (status & HD_STATUS_DRQ) {
				break;
			} else if (status & HD_STATUS_BSY) {
				continue;
			} else if (status & (HD_STATUS_ERR | HD_STATUS_DF)) {
				return i | (status << 8);
			}
		}
		Ins16(0x01F0, 256, data);
		data = (unsigned char*)data + 512;
	}
	return sects;
}

word hdWrite(bit drive, byte sects, dword offset, const void* data) {
	unsigned i;
	drive &= 1;
	offset &= 0xFFFFFFF;
	Out8(0x01F6, 0xE0 | (drive << 4) | ((offset >> 24) & 0xF));
	Out8(0x01F2, sects);
	Out8(0x01F3, offset);
	Out8(0x01F4, offset >> 8);
	Out8(0x01F5, offset >> 16);
	Out8(0x01F7, 0x30);
	for (i = 0; i < sects; ++i) {
		while (1) {
			byte status = hdStatus();
			if (status & HD_STATUS_DRQ) {
				break;
			} else if (status & HD_STATUS_BSY) {
				continue;
			} else if (status & (HD_STATUS_ERR | HD_STATUS_DF)) {
				return i | (status << 8);
			}
		}
		Outs16(0x01F0, 256, data);
		data = (const unsigned char*)data + 512;
	}
	Out8(0x01F7, 0xE7);
	return sects;
}
