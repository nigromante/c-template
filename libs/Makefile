RED    := $(shell tput -Txterm setaf 1)
GREEN  := $(shell tput -Txterm setaf 2)
YELLOW := $(shell tput -Txterm setaf 3)
BLUE   := $(shell tput -Txterm setaf 4)
RESET  := $(shell tput -Txterm sgr0)

EXEDIR = ./libqrcode

$(info [$(RED)$(EXEDIR)$(RESET)] )

build:
	$(foreach dir, $(EXEDIR) , $(MAKE) build install -C $(dir); )
	@echo

all:
	$(foreach dir, $(EXEDIR) , $(MAKE) all -C $(dir); )
	@echo

clean:
	$(foreach dir, $(EXEDIR) , $(MAKE) clean -C $(dir); )
	@echo -n "\t${YELLOW}"
	rm -f ./tests/include/* ./tests/*.so
	@echo -n "${RESET}"

