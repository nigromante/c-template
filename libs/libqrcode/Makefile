# Bin file
EXE = libqrcode.so 

# Folders
SRCDIR = ./src
INCDIR = include
OBJDIR = ./obj
BINDIR = ./bin
INSTALLDIR = ../../test/libs
EXPDIR = ./export

# Files
SRCS := $(shell find $(SRCDIR) -name "*.c")
OBJS_TMP = $(patsubst %.c,%.o,$(SRCS))
OBJS = $(subst $(SRCDIR),$(OBJDIR), $(OBJS_TMP))
TARGET = $(BINDIR)/$(EXE)
INCLUDE = -I $(INCDIR)


# Compiler-Linker flags
CC = gcc

CFLAGS = -Wall -g -fPIC -fvisibility=hidden
LDFLAGS = -L./lib -shared 
LDLIBS = -lqrencode


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


install:
	@echo "Installing ..."
	cp -f $(TARGET)   $(INSTALLDIR)
	cp -f $(EXPDIR)/*.h  $(INSTALLDIR)/include

help:
	@clear
	@echo  "Aliases"
	@echo  "\talias mk='make'"
	@echo  "\talias mka='make all'"
	@echo  "\talias mkc='make clean'"
	@echo  "\talias mkb='make build'"
	@echo  "\talias mki='make install'"
	@echo  "\talias mkh='make help'"
	@echo
	@echo "Folders:"
	@echo "\tSources        : " $(SRCDIR)
	@echo "\tIncludes       : " $(INCDIR)
	@echo "\tObjects        : " $(OBJDIR)
	@echo "\tBin            : " $(BINDIR)
	@echo
	@echo "Files"
	@echo "\tSources        : " $(SRCS)
	@echo "\tObjects        : " $(OBJS)
	@echo "\tExecutable     : " $(TARGET)
	@echo
	@echo "Installer"
	@echo "\tFolder         : " $(INSTALLDIR)
	@echo
	@echo "Depends"
	@echo "\tLibs           : " $(LDLIBS)
	@echo
