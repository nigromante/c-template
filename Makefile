EXEDIR = ./libs ./exes


$(info )
$(info  ******************************************************)
$(info  ** Makefile : [$(EXEDIR)] )
$(info  ******************************************************)
$(info  )

all: build

build:
	$(info ===========================================================)
	$(info Building ... )
	$(info ===========================================================)
	$(info  )
	$(foreach dir, $(EXEDIR) , $(MAKE) all -C $(dir); )
	@echo

clean:
	$(info ===========================================================)
	$(info Cleaning ... )
	$(info ===========================================================)
	$(info  )
	$(foreach dir, $(EXEDIR) , $(MAKE) clean -C $(dir); )
	@echo
	rm -f ./test/bin/* ./test/libs/include/* ./test/libs/*.so
	

