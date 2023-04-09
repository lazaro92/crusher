#########################################
# Author: Albert Lazaro de Lara         #
#########################################


### variables ##############

CXX      := g++
OBJECTS  := main.o Application.o
LIBRARY  := -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
CXXFLAGS := -I include/

ifeq ($(BUILD),develop)
    CXXFLAGS += -Wall -O2 -g
else ifeq ($(BUILD),release)
    CXXFLAGS += -O2 -s -DNDEBUG
else
    CXXFLAGS += -Wall -O0 -g -D _DEBUG
endif

############################

ifneq ($(MAKECMDGOALS),clean)
    ifeq ($(BUILD),develop)
        $(info ****************** DEVELOP BUILD ********************)
    else ifeq ($(BUILD),release)
        $(info ****************** RELEASE BUILD ********************)
    else
        $(info ******************* DEBUG BUILD *********************)
    endif
endif

############################ 

output: $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(LIBRARY) -o crusher.out $(OBJECTS) 

main.o: src/main.cpp
	$(CXX) $(CXXFLAGS) -c src/main.cpp

Application.o: src/Application.cpp include/Application.hpp
	$(CXX) $(CXXFLAGS) -c src/Application.cpp


###################

# To prevent make from getting confused by an actual file called clean, me may use .PHONY:
# .hppe "-" in -rm causes make to continue in spite of errors from rm
.PHONY: clean
clean:
	-rm $(OBJECTS) crusher.out

