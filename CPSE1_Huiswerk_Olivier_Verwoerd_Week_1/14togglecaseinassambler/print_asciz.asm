   .cpu cortex-m0
   .text
   .align 1
   .global print_asciz

print_asciz:
   push { r5, lr }
   mov  r5, r0
loop: 
   ldrb r0, [ r5 ]
   add  r0, r0, #0
   beq  finished
   sub  r0, r0, #64
   ble  putchar
   sub  r0, r0, #26
   ble  uncapitalize
   sub  r0, r0, #6
   ble  putcharmid
   sub  r0, r0, #26
   ble  capitalize
   add  r0, r0, #58
   b putchar
   
capitalize:
   add  r0, r0, #26
   b putchar
uncapitalize:
   add  r0, r0, #58
   b putchar
putcharmid:
   add  r0, r0, #32
   b putchar
putchar:
   add  r0, r0, #64
   bl   put_char
   add  r5, r5, #1
   b    loop
finished: 
   pop  { r5, pc }
