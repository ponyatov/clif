.PHONY: ocd
ocd: $(CWD)/hw/$(HW)/$(HW).ocd
	openocd -f $<

.PHONY: gdb
gdb: $(CWD)/hw/$(HW)/$(HW).gdb $(ELF)
	gdb-multiarch -q -se $(ELF) -x $<
