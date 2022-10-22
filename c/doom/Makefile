include ../Makefile

export MODULES = texture.o player.o doom.o

doom.hp: *.c *.h
	make $(MODULES)
	$(LD) $(LD_FLAGS) $(MODULES) $(LIBS) -o $@
	$(ELF2HP) doom.exe doom.hp
