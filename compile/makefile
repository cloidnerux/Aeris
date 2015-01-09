#!/bin/bash
## by clodinerux
## erstellt das Image und Kopiert es nach ../

image: kernel.bin
	@echo "Erstelle Mount-Ordner"	
	@mkdir -p Aeris/
	@echo "[OK]"
	@echo "Erstelle Image"
	@rm -rf aeris.img
	@dd if=/dev/zero of=aeris.img bs=1024 count=1440
	@echo "[OK]"
	@echo "Erstelle Dateisytsem mit ext2fs"
	@mke2fs -F aeris.img
	@echo "[OK]"
	@echo "Mounte das Image"
	@sudo mount -o loop aeris.img Aeris/
	@echo "[OK]"
	@echo "Richte Image ein"
	@sudo mkdir Aeris/grub
	@sudo cp kernel.bin Aeris/
	@sudo cp /boot/grub/stage1 Aeris/grub
	@sudo cp /boot/grub/stage2 Aeris/grub
	@sudo cp menu.lst Aeris/grub
	@sudo umount Aeris/
	@echo "[OK]"
	@sleep 2
	@echo "Bootloader einrichten"
	@sh make_grub
	@echo "[OK]"
	cp aeris.img ../
	@echo "ENDE"
