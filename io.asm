global In8
global In16
global In32

global Ins8
global Ins16
global Ins32

global Out8
global Out16
global Out32

global Outs8
global Outs16
global Outs32

global Hlt

In8:
	mov dx, word [esp + 4]
	xor eax, eax
	in al, dx
	ret

In16:
	mov dx, word [esp + 4]
	xor eax, eax
	in ax, dx
	ret

In32:
	mov dx, word [esp + 4]
	xor eax, eax
	in eax, dx
	ret

Ins8:
	push edi
	mov dx, word [esp + 8]
	mov ecx, dword [esp + 12]
	mov edi, dword [esp + 16]
	rep insb
	pop edi
	ret

Ins16:
	push edi
	mov dx, word [esp + 8]
	mov ecx, dword [esp + 12]
	mov edi, dword [esp + 16]
	rep insw
	pop edi
	ret

Ins32:
	push edi
	mov dx, word [esp + 8]
	mov ecx, dword [esp + 12]
	mov edi, dword [esp + 16]
	rep insd
	pop edi
	ret

Out8:
	mov dx, word [esp + 4]
	mov al, byte [esp + 8]
	out dx, al
	ret

Out16:
	mov dx, word [esp + 4]
	mov ax, word [esp + 8]
	out dx, ax
	ret

Out32:
	mov dx, word [esp + 4]
	mov eax, dword [esp + 8]
	out dx, eax
	ret

Outs8:
	push esi
	mov dx, word [esp + 8]
	mov ecx, dword [esp + 12]
	mov esi, dword [esp + 16]
Outs8_loop:
	outsb
	jmp $+2
	loop Outs8_loop
	pop esi
	ret

Outs16:
	push esi
	mov dx, word [esp + 8]
	mov ecx, dword [esp + 12]
	mov esi, dword [esp + 16]
Outs16_loop:
	outsw
	jmp $+2
	loop Outs16_loop
	pop esi
	ret

Outs32:
	push esi
	mov dx, word [esp + 8]
	mov ecx, dword [esp + 12]
	mov esi, dword [esp + 16]
Outs32_loop:
	outsd
	jmp $+2
	loop Outs32_loop
	pop esi
	ret

Hlt:
	hlt
	ret