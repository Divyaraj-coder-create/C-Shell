OBJ_FILES := $(shell cat pastevents.txt)

main: $(OBJ_FILES)
	gcc -g $(OBJ_FILES) main.c prompt.c warp.c peek.c pastevents.c syst.c

