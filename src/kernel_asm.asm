global loader
extern main


global GDTFlush
extern gp
GDTFlush:
    lgdt [gp]
    mov ax, 0x10
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    mov ss, ax
    jmp 0x08:flush2
flush2:
    ret


FLAGS    equ 0
MAGIC    equ 0x1BADB002       ; Magicnumber - Erkennungsmerkmal für Grub
CHECKSUM equ -(MAGIC + FLAGS) ; Checksum

[SECTION .boot]
align 4
MultiBootHeader:
  dd MAGIC       ; Magic number
  dd FLAGS       ; Flags
  dd CHECKSUM    ; Checksum

loader:
  mov esp,0x200000 ; Stack an die 2MB-Grenze platzieren
  push eax         ; Multiboot Magicnumber auf den Stack legen
  push ebx         ; Adresse der Multiboot-Structure auf den Stack legen
  call main        ; main-Funktion des C-Kernels aufrufen

  cli ; falls der Kernel bis hier her kommt, CPU anhalten
  hlt

