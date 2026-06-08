RED    := $(shell tput -Txterm setaf 1)
GREEN  := $(shell tput -Txterm setaf 2)
YELLOW := $(shell tput -Txterm setaf 3)
BLUE   := $(shell tput -Txterm setaf 4)
RESET  := $(shell tput -Txterm sgr0)

# Bin file
EXE = libvio.so

$(info [$(YELLOW)$(EXE)$(RESET)] )

# Folders
SRCDIR = ./src
INCDIR = ./include
OBJDIR = ./obj
BINDIR = ./bin
INSTALLDIR = ../../libs/tests
RELEASEDIR = ../../test/libs
EXPDIR = ./export

# Files
SRCS := $(shell find $(SRCDIR) -name "*.c")
DEPS := $(SRCS:.c=.d)
OBJS_TMP = $(patsubst %.c,%.o,$(SRCS))
OBJS = $(subst $(SRCDIR),$(OBJDIR), $(OBJS_TMP))
TARGET = $(BINDIR)/$(EXE)
INCLUDE = -I $(INCDIR)


# Compiler-Linker flags
CC = gcc

CFLAGS = -Wall -g -fPIC -fvisibility=hidden
#LDFLAGS = -L./lib -shared 
LDFLAGS = -shared 
LDLIBS = 

DEPSFLAGS = -MMD -MP -MF $(SRCDIR)

# Link
$(TARGET): $(OBJS) | $(BINDIR)
	$(info  )
	$(info Linking ... )
	@echo -n "\t${YELLOW}"  
	$(CC) $(OBJS) -o $@ $(LDFLAGS) $(LDLIBS)
	@echo -n "${RESET}"  

$(BINDIR):
	@mkdir -p $@

-include $(DEPS)

# Compile
$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	@if [ ! -d "$(dir $@)" ]; then mkdir -p $(dir $@); fi
	@echo -n "\t${YELLOW}"  
	$(CC) $(DEPSFLAGS)/$*.d $(CFLAGS) $(INCLUDE) -c $< -o $@
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


install:
	$(info  )
	$(info Installing ... )
	@echo -n "\t${YELLOW}"  
	cp -f $(TARGET)   $(INSTALLDIR)
	@echo -n "\t"  
	cp -f $(TARGET)   $(RELEASEDIR)
	@echo "${RESET}"

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
