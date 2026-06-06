RED    := $(shell tput -Txterm setaf 1)
GREEN  := $(shell tput -Txterm setaf 2)
YELLOW := $(shell tput -Txterm setaf 3)
BLUE   := $(shell tput -Txterm setaf 4)
RESET  := $(shell tput -Txterm sgr0)

# Bin file
EXE = qrcode

$(info [$(YELLOW)$(EXE)$(RESET)] )


# Folders
SRCDIR = ./src
OBJDIR = ./obj
BINDIR = ./bin
INSTALLDIR = ../../test/bin
TESTDIR = ../../libs/tests

# Files
SRCS := $(shell find $(SRCDIR) -name "*.c")
DEPS := $(SRCS:.c=.d)
OBJS_TMP = $(patsubst %.c,%.o,$(SRCS))
OBJS = $(subst $(SRCDIR),$(OBJDIR), $(OBJS_TMP))
TARGET = $(BINDIR)/$(EXE)
INCLUDE = -I include -I $(TESTDIR)/include

# Compiler-Linker flags
CC = gcc

CFLAGS = -Wall -g
LDFLAGS = -L$(TESTDIR)
LDLIBS = -lqrcode

DEPSFLAGS = -MMD -MP -MF $(SRCDIR)/$*.d 

# Link
$(TARGET): $(OBJS) | $(BINDIR)
	$(info  )
	$(info Linking ... )
	@echo -n "\t${YELLOW}"  
	$(CC) $(OBJS) -o $(TARGET) $(LDFLAGS) $(LDLIBS)
	@echo -n "${RESET}"  

$(BINDIR):
	@mkdir -p $@

-include $(DEPS)

# Compile
$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	@if [ ! -d "$(dir $@)" ]; then mkdir -p $(dir $@); fi
	@echo -n "\t${YELLOW}"  
	$(CC) $(DEPSFLAGS) $(CFLAGS) $(INCLUDE) -c $< -o $@
	@echo -n "${RESET}"  

$(OBJDIR):
	@mkdir -p $@


.PHONY: clean
clean:
	$(info  )
	$(info Cleaning ... )
	@echo -n "\t${YELLOW}"  
	rm -rf $(OBJDIR) $(BINDIR) $(DEPS)
	@echo "${RESET}"

build: $(TARGET)

all:  clean build install

run:
	@./test.sh $(TESTDIR)  $(TARGET)

debug:
	@./test.sh $(TESTDIR)  gdb $(TARGET)
	#gdb  $(TARGET)

install:
	$(info  )
	$(info Installing ... )
	@echo -n "\t${YELLOW}"  
	cp -f $(TARGET)  $(INSTALLDIR)
	@echo "${RESET}"

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


