# Makefile for the overo-arduino-i2c test program

ifeq ($(strip $(OETMP)),)
	OETMP = $(HOME)/overo-oe/tmp 
endif


TOOLDIR = $(OETMP)/sysroots/`uname -m`-linux/usr/armv7a/bin
STAGEDIR = ${OETMP}/sysroots/armv7a-angstrom-linux-gnueabi/usr

CC = ${TOOLDIR}/arm-angstrom-linux-gnueabi-gcc
CFLAGS = -Wall

LIBDIR = $(STAGEDIR)/lib
INCDIR = $(STAGEDIR)/include

TARGET = overo-i2c 

$(TARGET) : overo-i2c.c
	$(CC) $(CFLAGS) -I $(INCDIR) -L $(LIBDIR) overo-i2c.c -o $(TARGET)

install:
	scp $(TARGET) root@192.168.10.106:/home/root


clean :
	rm -f $(TARGET)

