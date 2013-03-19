# Source files
SRC =  $(wildcard *.cc)
EXE = $(SRC:.cc=)

# Compiler options
CXX = g++
CXXFLAGS = -Werror -Wall -g -std=c++11
INC = -I ../ 

all: $(EXE) .gitignore

.cc:
	$(CXX) $(INC) $(CXXFLAGS) $< -o $@

clean:
	rm -f $(EXE) .gitignore

# Autogenerate .gitignore to ignore executable files
.gitignore:
	@echo $(EXE) | sed 's/ /\n/g' > $@

