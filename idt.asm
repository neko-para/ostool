global idtUpdate

idtUpdate:
	mov eax, [esp + 4]
	lidt [eax]
	ret
