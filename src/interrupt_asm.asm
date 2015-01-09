global IDTLoad
extern idtp
IDTLoad:
    lidt [idtp]
    ret
global save_registers
save_registers:
    pushad
    ret
global reload_registers
reload_registers:
    popad
    ret
global _iret
_iret:
    iret

global isr0
global isr1
global isr2
global isr3
global isr4
global isr5
global isr6
global isr7
global isr8
global isr9
global isr10
global isr11
global isr12
global isr13
global isr14
global isr15
global isr16
global isr17
global isr18
global isr19
global isr20
global isr21
global isr22
global isr23
global isr24
global isr25
global isr26
global isr27
global isr28
global isr29
global isr30
global isr31

;  0: Divide By Zero Exception
isr0:
    cli
    push byte 0    ; Die Nummer des Interrupts speichern
    push byte 0
    jmp int_common_stub

;  1: Debug Exception
isr1:
    cli
    push byte 0
    push byte 1
    jmp int_common_stub

isr2:
    cli
    push byte 0
    push byte 2
    jmp int_common_stub

isr3:
    cli
    push byte 0
    push byte 3
    jmp int_common_stub

isr4:
    cli
    push byte 0
    push byte 4
    jmp int_common_stub
    
isr5:
    cli
    push byte 0
    push byte 5
    jmp int_common_stub
    
isr6:
    cli
    push byte 0
    push byte 6
    jmp int_common_stub

isr7:
    cli
    push byte 0
    push byte 7
    jmp int_common_stub
;  8: Double Fault Exception (With Error Code!)

isr8:
    cli
    push byte 0
    push byte 8
    jmp int_common_stub

isr9:
    cli
    push byte 0
    push byte 9
    jmp int_common_stub
    
isr10:
    cli
    push byte 0
    push byte 10
    jmp int_common_stub

isr11:
    cli
    push byte 0
    push byte 11
    jmp int_common_stub

isr12:
    cli
    push byte 0
    push byte 12
    jmp int_common_stub

isr13:
    cli
    push byte 0
    push byte 13
    jmp int_common_stub
    
isr14:
    cli
    push byte 0
    push byte 14
    jmp int_common_stub

isr15:
    cli
    push byte 0
    push byte 15
    jmp int_common_stub

isr16:
    cli
    push byte 0
    push byte 16
    jmp int_common_stub

isr17:
    cli
    push byte 0
    push byte 17
    jmp int_common_stub

isr18:
    cli
    push byte 0
    push byte 18
    jmp int_common_stub

isr19:
    cli
    push byte 0
    push byte 19
    jmp int_common_stub

isr20:
    cli
    push byte 0
    push byte 20
    jmp int_common_stub

isr21:
    cli
    push byte 0
    push byte 21
    jmp int_common_stub

isr22:
    cli
    push byte 0
    push byte 22
    jmp int_common_stub

isr23:
    cli
    push byte 0
    push byte 23
    jmp int_common_stub

isr24:
    cli
    push byte 0
    push byte 24
    jmp int_common_stub

isr25:
    cli
    push byte 0
    push byte 25
    jmp int_common_stub

isr26:
    cli
    push byte 0
    push byte 26
    jmp int_common_stub

isr27:
    cli
    push byte 0
    push byte 27
    jmp int_common_stub

isr28:
    cli
    push byte 0
    push byte 28
    jmp int_common_stub

isr29:
    cli
    push byte 0
    push byte 29
    jmp int_common_stub

isr30:
    cli
    push byte 0
    push byte 30
    jmp int_common_stub

isr31:
    cli
    push byte 0
    push byte 31
    jmp int_common_stub

global irq0
global irq1
global irq2
global irq3
global irq4
global irq5
global irq6
global irq7
global irq8
global irq9
global irq10
global irq11
global irq12
global irq13
global irq14
global irq15

; 32: IRQ0
irq0:
    cli
    push byte 0
    push byte 32 
    jmp int_common_stub

irq1:
    cli
    push byte 0
    push byte 33 
    jmp int_common_stub

irq2:
    cli
    push byte 0
    push byte 34 
    jmp int_common_stub

irq3:
    cli
    push byte 0
    push byte 35 
    jmp int_common_stub

irq4:
    cli
    push byte 0
    push byte 36 
    jmp int_common_stub

irq5:
    cli
    push byte 0
    push byte 37 
    jmp int_common_stub

irq6:
    cli
    push byte 0
    push byte 38 
    jmp int_common_stub

irq7:
    cli
    push byte 0
    push byte 39 
    jmp int_common_stub

irq8:
    cli
    push byte 0
    push byte 40 
    jmp int_common_stub

irq9:
    cli
    push byte 0
    push byte 41 
    jmp int_common_stub

irq10:
    cli
    push byte 0
    push byte 42 
    jmp int_common_stub

irq11:
    cli
    push byte 0
    push byte 43 
    jmp int_common_stub

irq12:
    cli
    push byte 0
    push byte 44 
    jmp int_common_stub

irq13:
    cli
    push byte 0
    push byte 45 
    jmp int_common_stub

irq14:
    cli
    push byte 0
    push byte 46 
    jmp int_common_stub
; 47: IRQ15
irq15:
    cli
    push byte 0
    push byte 47
    jmp int_common_stub

global null_handler  ;standart interrupts

null_handler:
             cli
             push byte 0
             push byte 48
             jmp int_common_stub

extern InterruptStandardHandler ;Verweist auf den Interrupt standart handler

int_common_stub:
    pusha
    push ds
    push es
    push fs
    push gs
    mov ax, 0x10
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    mov eax, esp
    push eax
    mov eax, InterruptStandardHandler
    call eax
    pop eax
    pop gs
    pop fs
    pop es
    pop ds
    popa
    add esp, 8
    iret