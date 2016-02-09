00000090 <main>:
  90:	b510      	push	{r4, lr}
  92:	2400      	movs	r4, #0
  94:	2c23      	cmp	r4, #35	; 0x23
  96:	dc07      	bgt.n	a8 <main+0x18>
  98:	f7ff fffe 	bl	0 <stop_light>
  9c:	1c20      	adds	r0, r4, #0
  9e:	f7ff fffe 	bl	0 <inc>
  a2:	1e04      	subs	r4, r0, #0
  a4:	2c23      	cmp	r4, #35	; 0x23
  a6:	ddf7      	ble.n	98 <main+0x8>
  a8:	bd10      	pop	{r4, pc}
  aa:	46c0      	nop			; (mov r8, r8)
