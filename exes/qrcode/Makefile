# Bin file
EXE = qrcode 

# Folders
SRCDIR = ./src
OBJDIR = ./obj/
BINDIR = ./bin/
INSTALLDIR = ../../test/bin

# Files
SRCS := $(shell find $(SRCDIR) -name "*.c")
OBJS_TMP = $(patsubst %.c,%.o,$(SRCS))
OBJS = $(subst $(SRCDIR),$(OBJDIR), $(OBJS_TMP))
TARGET = $(BINDIR)/$(EXE)
INCLUDE = -I include -I ../../libs/libqrcode/export


# Compiler-Linker flags
CC = gcc

CFLAGS = -Wall -g
LDFLAGS = -L../../libs/libqrcode/bin
LDLIBS = -lqrcode


# Link
$(TARGET): $(OBJS) | $(BINDIR)
	$(CC) $(OBJS) -o $(TARGET) $(LDFLAGS) $(LDLIBS)

$(BINDIR):
	@mkdir -p $@


# Compile
$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	@if [ ! -d "$(dir $@)" ]; then mkdir -p $(dir $@); fi
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJDIR):
	@mkdir -p $@


clean:
	rm -f $(OBJS) $(TARGET)

build: clean $(TARGET)

all:  clean build run

run:
	@ . ./exports.sh  &&  $(TARGET)

debug:
	gdb  $(TARGET)

install:
	@echo "Installing ..."
	cp -f $(TARGET)  $(INSTALLDIR)

help:
	@clear
	@echo  "Aliases"
	@echo  "\talias mk='make'"
	@echo  "\talias mka='make all'"
	@echo  "\talias mkc='make clean'"
	@echo  "\talias mkb='make build'"
	@echo  "\talias mkr='make run'"
	@echo  "\talias mkd='make debug'"
	@echo  "\talias mki='make install'"
	@echo  "\talias mkh='make help'"
	@echo
	@echo "Folders:"
	@echo "\tSources          : " $(SRCDIR)
	@echo "\tObjects          : " $(OBJDIR)
	@echo "\tBin              : " $(BINDIR)
	@echo
	@echo "Files"
	@echo "\tSources          : " $(SRCS)
	@echo "\tObjects          : " $(OBJS)
	@echo "\tExecutable       : " $(TARGET)
	@echo
	@echo "Installer"
	@echo "\tFolder           : " $(INSTALLDIR)
	@echo
