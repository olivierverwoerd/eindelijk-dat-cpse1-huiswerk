.cpu cortex-m0
.text
.align 1
.global application

application:
    push { r5, lr }
	b print_asciz