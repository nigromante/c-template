EXEDIR = ./libs ./exes


$(info )
$(info  ******************************************************)
$(info  ** Makefile : [$(EXEDIR)] )
$(info  ******************************************************)

all: build

build:
	$(info  )
	$(info Cleaning ... )
	$(foreach dir, $(EXEDIR) , $(MAKE) all -C $(dir); )
	@echo -n "\t"  
	@echo

clean:
	$(info  )
	$(info Cleaning ... )
	$(foreach dir, $(EXEDIR) , $(MAKE) clean -C $(dir); )
	@echo -n "\t"  
	@echo

