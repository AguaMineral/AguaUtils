.PHONY: clean All

All:
	@echo "----------Building project:[ DataStructures - Debug ]----------"
	@"$(MAKE)" -f  "DataStructures.mk"
clean:
	@echo "----------Cleaning project:[ DataStructures - Debug ]----------"
	@"$(MAKE)" -f  "DataStructures.mk" clean
