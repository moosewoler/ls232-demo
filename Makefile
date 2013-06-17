#
#  Makefile to build hello.c
#

CROSS_COMPILE 	=mipsel-linux-

#
# Include the make variables (CC, etc...)
#

AS		= $(CROSS_COMPILE)as
LD		= $(CROSS_COMPILE)ld
CC		= $(CROSS_COMPILE)gcc
CPP		= $(CC) -E
AR		= $(CROSS_COMPILE)ar
NM		= $(CROSS_COMPILE)nm
STRIP		= $(CROSS_COMPILE)strip
OBJCOPY		= $(CROSS_COMPILE)objcopy
OBJDUMP		= $(CROSS_COMPILE)objdump
SIZE		= $(CROSS_COMPILE)size

SRC_DIR = ./src
BIN_DIR = ./build

hello:	${SRC_DIR}/hello.c
	${CC} -G 0 -O2  -fno-pic -mno-abicalls -fno-builtin -nostdinc -mips3 -Ttext=0xffffffff80200000 -N -o ${BIN_DIR}/hello ${SRC_DIR}/hello.c -nostdlib -e main -Wl,-m -Wl,elf32ltsmip -T ld.script
clean:
	rm -fv ${BIN_DIR}/hello *.o
