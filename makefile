# CONSTANTS #######################################################################################
FILE_CACHE_DATA_DIR= ./cached_data/
PORT = 5400
# COMPILATION #####################################################################################
SRCS_DIRS=	src
BUILD_DIR=	build
EXCLUDE_D=	algorithm/_legacy algorithm/main.cpp demo

ifdef EXCLUDE_D
EXCLUDE_LAST:= 	$(lastword $(EXCLUDE_D))
EXCLUDE_FIRST:= $(filter-out $(EXCLUDE_LAST), $(EXCLUDE_D))
EXCLUDE:= 		\( $(EXCLUDE_FIRST:%=-path $(SRCS_DIRS)/% -prune -o) -path $(SRCS_DIRS)/$(EXCLUDE_LAST) -prune \) -o
endif

SRCS:=	$(shell find $(SRCS_DIRS) -mindepth 1 $(EXCLUDE) -name *.cpp -print)
OBJS:=	$(SRCS:%=$(BUILD_DIR)/%.o)
DEPS:=	$(OBJS:.o=.d)

COMPILER=		g++
COMP_FLAGS= 	-ggdb3 -std=c++14 -Wall -Wextra -Wshadow -Wnon-virtual-dtor -pedantic -pthread
ifdef DEBUG
COMP_FLAGS+= 	-D DEBUG_OUTPUT
endif
ifdef ALGO
COMP_FLAGS+= 	-D USE_$(ALGO) -D USE_ALGORITHM
endif
INC_DIRS:=	 	$(shell find $(SRCS_DIRS) -type d)
INC_FLAGS:=		$(addprefix -I,$(INC_DIRS)) -MMD -MP
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

# Main Targets ####################################################################################
OUTFLIE_NAME = a
ifdef ALGO
OUTFLIE_NAME = $(ALGO)
endif
.PHONY: compile
compile: $(BUILD_DIR)/main
	@cp $(BUILD_DIR)/main $(OUTFLIE_NAME).out

a.out: compile
run: a.out
	@./a.out

# EXTRA TARGETS ###################################################################################
.PHONY: clean
clean: clean_cache clean_benchmark_data
	@rm -rf $(BUILD_DIR) *.out

.PHONY: clean_cache
clean_cache:
	@rm -rf $(FILE_CACHE_DATA_DIR)

# BENCHMARK #######################################################################################
BENCHMARK_FOLDER = benchmark
BENCHMARK_DATA = $(BENCHMARK_FOLDER)/data
ALGORITHMS = BEST \
ASTAR \
BFS \
DFS

.PHONY: $(ALGORITHMS)
$(ALGORITHMS): clean_cache
	@echo -n "[ ] Generating $@ algorithm results...\r"
	@rm -f build/src/boot/boot.cpp.o
	@$(MAKE) -s ALGO=$@ compile > /dev/null
	@mkdir -p $(BENCHMARK_DATA)/
	@mv $@.out $(BENCHMARK_DATA)/.
	@./$(BENCHMARK_DATA)/$@.out $(PORT) & \
	cd $(BENCHMARK_FOLDER) ; \
	python3 benchmark_client.py --algorithm '$@' --target-port $(PORT) >/dev/null 2>&1
	@rm -f $(BENCHMARK_DATA)/$@.out
	@fuser -k $(PORT)/tcp >/dev/null 2>&1
	@echo -n "[X\n\r"

.PHONY: generate_benchmark_data
generate_benchmark_data: clean_benchmark_data
	@PORT=5600 ;\
		for alg in $(ALGORITHMS); do \
	$(MAKE) -s PORT=$$((PORT)) $$alg ; \
	PORT=$$((PORT+1)) ;\
	done

.PHONY: benchmark
benchmark:
	@echo '### BEGIN BENCHMARK ####'
	@$(MAKE) -s generate_benchmark_data
	@$(MAKE) -s $(BENCHMARK_FOLDER)/result.png
	@echo '### END BENCHMARK ####'

$(BENCHMARK_FOLDER)/result.png:
	@echo '### NOW DRAWING BENCHMARK RESULT GRAPH ####'
	@-cd $(BENCHMARK_FOLDER) ; \
	python3 draw_result.py 2>/dev/null ; \
	echo '### RESULT GRAP DRAWN AT $@ ####'
	@rm -rf data


.PHONY: clean_benchmark_data
clean_benchmark_data:
	@rm -rf $(BENCHMARK_DATA)/*solutions $(BENCHMARK_FOLDER)/result.png
###################################################################################################
