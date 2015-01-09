## by cloidnerux
## Kompiliert und erstellt Automatisch ein Image
#!/bin/bash

kernel:
	@echo "[---------Compiliere Kernel---------]"
	@make -C src/
	@sleep 2
	@echo "-------->> Fertig"

image:
	@echo "[---------Erstelle Image------------]"
	@make -C compile/
	@sleep 2
	@echo "-------->> Fertig"

qemu:
	@echo "Starte qemu"
	@echo "Starting QEMU..."
	@qemu -fda aeris.img -m 256 -boot a -name "Aeris 0.4"
	@echo "-------->> Fertig"

bochs:
	@echo "Starte bochs"
	@echo "Starting BOCHS..."
	@bochs -f aeris -q
	@echo "-------->> Fertig"

.PHONY: clean
clean:
	@echo "[--------Bereinige Build-Dir-------]"
	@echo -n "[clean] Lösche Objektdateien und den Kernel\n"
	-@sudo umount compile/Aeris
	@rm -rf `find compile/ -name "*.o" -printf "%p "`
	@rm -rf `find compile/ -name "*.bin" -printf "%p "`
	@rm -rf src/allsources
	-@sudo rm -rf compile/Aeris
	-@sudo mkdir compile/Aeris
	@echo "  [OK]"
	@echo "-------->> Fertig"

.PHONY: clean-all
clean-all: clean
	@echo "[------Lösche logs und Images------]"
	@echo -n "[clean-all]Lösche logs und Images..."
	@rm -rf `find -name "*.log" -printf "%p "`
	@rm -rf `find -name "*.img" -printf "%p "`
	@rm -rf `find compile/ -name "*.img" -printf "%p "`
	@echo "  [OK]"
	@echo "-------->> Fertig"

all: kernel image
