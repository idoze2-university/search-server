# DEFINE DATA DIR #################################################################################
PROJECT_DATA_DIR=Project_Data

# COMPILATION #####################################################################################
ifndef file #sets default for 'file' variable.
override file=fly.txt
endif

COMPILER=g++
CFLAGS= -ggdb3 -std=c++14 -Wall -Wextra -Wshadow -Wnon-virtual-dtor -pedantic -pthread
MAIN_DIR=.
clean:
	@rm -fr ./*.out */*.o *.o

%.o : %.cpp
	g++ -g -o $@ -c $< $(CFLAGS)

# DEPENDENCIES ####################################################################################
ALL_DEPENDENCIES = $(foreach d, .... ,$(d).o)
_DEPENDENCIES_IDO = server_side/serial_server client_handler/test_client_handler cache_manager/file_cache_manager solver/string_reverser

# IDO (Ido) ###############################################################################
OUTFILE_IDO = ido.out
DEPENDENCIES_IDO = $(foreach d,$(_DEPENDENCIES_IDO),$(d).o) ido.cpp

$(OUTFILE_IDO):$(DEPENDENCIES_IDO)
	$(COMPILER) $(DEPENDENCIES_IDO) $(CFLAGS) -o $(OUTFILE_IDO)
# MAIN (Ido) ######################################################################################
OUTFILE_MAIN=main.out

$(OUTFILE_MAIN):$(DEPENDENCIES_MAIN)
	$(COMPILER) $(DEPENDENCIES_MAIN) $(CFLAGS) -o $(OUTFILE_MAIN)

main: $(OUTFILE_MAIN)
	./$(OUTFILE_MAIN) $(file)


