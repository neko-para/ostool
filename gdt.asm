global gdtUpdate

gdtUpdate:
	mov eax, [esp + 4]
	mov ecx, [esp + 8]
	mov edx, [esp + 12]
	lgdt [eax]
	mov ax, dx
	mov ds, ax
	mov es, ax
	mov fs, ax
	mov gs, ax
	mov ss, ax
	push cx
	push gdtUpdateRet
	retf
gdtUpdateRet:
	ret
