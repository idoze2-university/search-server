# COMPILATION #####################################################################################
SRC_DIRS=	src
BUILD_DIR=	build

SRCS:=	$(shell find $(SRC_DIRS) -mindepth 1 -name *.cpp)
OBJS:=	$(subst $(SRC_DIRS),$(BUILD_DIR),$(SRCS:%=%.o))
DEPS:=	$(OBJS:.o=.d)

COMPILER=	g++
DEBUG_FLAG= -ggdb3
COMP_FLAGS= $(DEBUG_FLAG) -std=c++14 -Wall -Wextra -Wshadow -Wnon-virtual-dtor -pedantic -pthread
INC_DIRS := $(shell find $(SRC_DIRS) -type d)
INC_FLAGS := $(addprefix -I,$(INC_DIRS)) -MMD -MP
CPPFLAGS:=	$(INC_FLAGS) $(COMP_FLAGS)

$(BUILD_DIR)/%.cpp.o:$(SRC_DIRS)/%.cpp
	@mkdir -p $(dir $@)
	@echo -n "[ ] Compiling ($(COMPILER)) $@\r"
	@$(COMPILER) -g -c $< -o $@ $(CPPFLAGS)
	@echo "[X] Compiling ($(COMPILER)) $@"

$(BUILD_DIR)/%.out:$(OBJS)
	@mkdir -p $(dir $@)
	@echo -n "[ ] Compiling $@\r"
	@$(COMPILER) $(OBJS) -o $@ $(CPPFLAGS)
	@echo "[X] Compiling $@"

-include $(DEPS)
# CONSTANTS #######################################################################################
FILE_CACHE_DATA_DIR = cache_manager/file_cache_data/

# EXTRA TARGETS ###################################################################################
.PHONY: clean
clean: clean_cache
	@rm -rf $(BUILD_DIR)

.PHONY: clean_cache
clean_cache:
	@rm -rf $(FILE_CACHE_DATA_DIR)



