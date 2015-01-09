## by cloidnerux
## Sucht und Compiliert alle *.c Datein im Ordner src
## fertige *.o Dateien werden nach compile gespeichert

#####################################################################
## VARS
SOURCE = 
BINARIES = ../compile/

AS = nasm
CC = gcc
LD = ld

ASFLAGS = -f elf32 -Wall -Werror
CCFLAGS = -m32 -Wall -Werror -nostdlib -nostartfiles -nodefaultlibs -I ./include
## -m32
CCPREFLAGS = -ffreestanding
LDFLAGS = -m elf_i386 -T $(BINARIES)/link.ld
CINCPATH = -I $(SOURCE)include/

OUTPATH = $(BINARIES)

###################################################################
## Standard Ziel
 
all: allsources kernel

###################################################################
## Dateien Suchen:
## Aus Dirty Oertys makefile

.PHONY: allsources
allsources:
	@echo -n "[allsources] Searching source files..."
	@echo -n "SOURCES = " > allsources
	@find . -name "*.c" -printf "%p " >> allsources
	@echo "\n" >> allsources
	@echo -n "ASMSRC = " >> allsources
	@find . -name "*.asm" -printf "%p " >> allsources
	@echo "  [OK]"

include allsources
objects = $(patsubst %.c,%.o,$(SOURCES)) $(patsubst %_asm.asm,%_asm.o,$(ASMSRC))
##################################################################
## Compilieren und Linken
## Aus Dirty Oertys makefile

.PHONY: kernel
kernel: $(objects)
	@echo -n "[kernel] Linking object files..."
	@$(LD) $(LDFLAGS) -o $(OUTPATH)/kernel.bin `find $(OUTPATH) -name "*.o" -printf "%p "`
	@echo "  [OK]"


%.o: %.c
	@echo -n "[c] Compiling $<..."
	@$(CC) $(CCPREFLAGS) -c $<  -o $(OUTPATH)$@ $(CCFLAGS) $(CINCPATH)
	@echo "  [OK]"

%_asm.o: %_asm.asm
	@echo -n "[asm] Assembling $<..."
	@$(AS) $(ASFLAGS) $< -o $(OUTPATH)$@
	@echo "  [OK]"

