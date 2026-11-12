
TARGET = main
OBJS = Scripts/main.o

CFLAGS = -O2 -G0 -Wall
LIBS = -lpspdebug

EXTRA_TARGETS = EBOOT.PBP
PSP_EBOOT_TITLE = Saiyan World PSP

PSPSDK = $(shell psp-config --pspsdk-path)
include $(PSPSDK)/lib/build.mak
