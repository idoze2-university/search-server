# CONSTANTS #######################################################################################
FILE_CACHE_DATA_DIR= ./cached_data/

# COMPILATION #####################################################################################
SRC_DIRS=	src
BUILD_DIR=	build

SRCS:=	$(shell find $(SRC_DIRS) -mindepth 1 -name *.cpp)
OBJS:=	$(SRCS:%=$(BUILD_DIR)/%.o)
DEPS:=	$(OBJS:.o=.d)

COMPILER=		g++
DEBUG_FLAG= 	-ggdb3
COMP_FLAGS= 	$(DEBUG_FLAG) -std=c++14 -Wall -Wextra -Wshadow -Wnon-virtual-dtor -pedantic -pthread
INC_DIRS := 	$(shell find $(SRC_DIRS) -type d)
INC_FLAGS :=	$(addprefix -I,$(INC_DIRS)) -MMD -MP
CPPFLAGS:=		$(INC_FLAGS) $(COMP_FLAGS)

$(BUILD_DIR)/main:$(OBJS)
	@mkdir -p $(dir $@)
	@echo -n "[ ] $@\r"
	@$(COMPILER) $(OBJS) -o $@ $(CPPFLAGS)
	@echo -n "[X\n\r"

$(BUILD_DIR)/%.cpp.o:%.cpp
	@mkdir -p $(dir $@)
	@echo -n "[ ] $@\r"
	@$(COMPILER) -g -c $< -o $@ $(CPPFLAGS)
	@echo "[X"


-include $(DEPS)

# EXTRA TARGETS ###################################################################################
.PHONY: clean
clean: clean_cache
	@rm -rf $(BUILD_DIR)

.PHONY: clean_cache
clean_cache:
	@rm -rf $(FILE_CACHE_DATA_DIR)

###################################################################################################