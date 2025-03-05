# HW ?= pc
# HW ?= f4disco
HW ?= l496disco

ELF = $(BIN)/$(BINFILE).elf
DFU = $(BIN)/$(BINFILE).dfu

include   hw/$(HW)/$(HW).mk
include  cpu/$(CPU)/$(CPU).mk
include arch/$(ARCH)/$(ARCH).mk
include   os/$(OS)/$(OS).mk

.PHONY: elf
elf: $(CWD)/hw/$(HW)/$(HW).ocd $(ELF)
	openocd -f $< -c "program $(ELF) verify reset exit"

.PHONY: dfu
dfu: $(DFU)
$(DFU): $(ELF)
	~/elf2dfuse/bin/elf2dfuse $< $@
