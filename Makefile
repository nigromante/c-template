RED    := $(shell tput -Txterm setaf 1)
GREEN  := $(shell tput -Txterm setaf 2)
YELLOW := $(shell tput -Txterm setaf 3)
BLUE   := $(shell tput -Txterm setaf 4)
RESET  := $(shell tput -Txterm sgr0)

EXEDIR = ./libs ./exes

# $(info [$(BLUE)$(EXEDIR)$(RESET)] )

build:
	$(foreach dir, $(EXEDIR) , $(MAKE) build -C $(dir);  )
	@echo

all:
	$(foreach dir, $(EXEDIR) , $(MAKE) all -C $(dir); )
	@echo

clean:
	$(foreach dir, $(EXEDIR) , $(MAKE) clean -C $(dir); )
	@echo -n "\t${YELLOW}"
	rm -f ./test/bin/* ./test/libs/include/* ./test/libs/*.so analisis
	@echo -n "${RESET}"

.phony run:
run:
	 @bash ./test/run.sh ./test/bin/qrcode

