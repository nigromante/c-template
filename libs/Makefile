RED    := $(shell tput -Txterm setaf 1)
GREEN  := $(shell tput -Txterm setaf 2)
YELLOW := $(shell tput -Txterm setaf 3)
BLUE   := $(shell tput -Txterm setaf 4)
RESET  := $(shell tput -Txterm sgr0)

EXEDIR = ./libqrcode ./libqrcode2

$(info )
$(info  ----------------------------------------------------------)
$(info  ** Makefile : [$(RED)$(EXEDIR)$(RESET)] )
$(info  ----------------------------------------------------------)
$(info )

build:
	$(info  ----------------------------------------------------------)
	$(info Building ... )
	$(info  ----------------------------------------------------------)
	$(info  )
	$(foreach dir, $(EXEDIR) , $(MAKE) build install -C $(dir); )
	@echo

all:
	$(info  ----------------------------------------------------------)
	$(info Rebuilding ... )
	$(info  ----------------------------------------------------------)
	$(info  )
	$(foreach dir, $(EXEDIR) , $(MAKE) all -C $(dir); )
	@echo

clean:
	$(info  ----------------------------------------------------------)
	$(info Cleaning ... )
	$(info  ----------------------------------------------------------)
	$(info  )
	$(foreach dir, $(EXEDIR) , $(MAKE) clean -C $(dir); )
	@echo
	rm -f ./tests/include/* ./tests/*.so

