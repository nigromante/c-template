EXEDIR = ./libqrcode

$(info )
$(info  ******************************************************)
$(info  ** Makefile : [$(EXEDIR)] )
$(info  ******************************************************)
$(info  )

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
	rm -f ./tests/*.so ./tests/include/*

