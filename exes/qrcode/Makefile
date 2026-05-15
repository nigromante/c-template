$(info )
$(info  ******************************************************)
$(info  ** Makefile : QRCODE                                **)
$(info  ******************************************************)


# Bin file
EXE = qrcode 

# Folders
SRCDIR = ./src
OBJDIR = ./obj
BINDIR = ./bin
INSTALLDIR = ../../test/bin
TESTDIR = ../../libs/tests

# Files
SRCS := $(shell find $(SRCDIR) -name "*.c")
OBJS_TMP = $(patsubst %.c,%.o,$(SRCS))
OBJS = $(subst $(SRCDIR),$(OBJDIR), $(OBJS_TMP))
TARGET = $(BINDIR)/$(EXE)
INCLUDE = -I include -I $(TESTDIR)/include


# Compiler-Linker flags
CC = gcc

CFLAGS = -Wall -g
LDFLAGS = -L$(TESTDIR)
LDLIBS = -lqrcode


# Link
$(TARGET): $(OBJS) | $(BINDIR)
	$(info  )
	$(info Linking ... )
	@echo -n "\t"  
	$(CC) $(OBJS) -o $(TARGET) $(LDFLAGS) $(LDLIBS)

$(BINDIR):
	@mkdir -p $@


# Compile
$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(info Compiling ... )
	@echo -n "\t"  
	@if [ ! -d "$(dir $@)" ]; then mkdir -p $(dir $@); fi
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJDIR):
	@mkdir -p $@


clean:
	$(info  )
	$(info Cleaning ... )
	@echo -n "\t"  
	rm -rf $(OBJDIR) $(BINDIR)
	@echo

build: clean $(TARGET)

all:  clean build install

run:
	@./test.sh $(TESTDIR)  $(TARGET)

debug:
	@./test.sh $(TESTDIR)  gdb $(TARGET)
	#gdb  $(TARGET)

install:
	$(info  )
	$(info Installing ... )
	@echo -n "\t"  
	cp -f $(TARGET)  $(INSTALLDIR)
	@echo

help:
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


