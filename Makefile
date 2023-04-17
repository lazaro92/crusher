#########################################
# Author: Albert Lazaro de Lara         #
#########################################


### variables ##############

CXX      := g++
OBJECTS  := main.o Button.o Component.o Container.o Label.o Application.o \
 CommandQueue.o Player.o SoundPlayer.o StateStack.o Command.o MusicPlayer.o \
State.o SoleauState.o PhoenixState.o TitleState.o SettingsState.o Utility.o # TestState.o Npc.o
LIBRARY  := -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
CXXFLAGS := -I Include/

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

main.o: Source/main.cpp
	$(CXX) $(CXXFLAGS) -c Source/main.cpp

# GUI

Button.o: Source/GUI/Button.cpp Include/Engine/GUI/Button.hpp
	$(CXX) $(CXXFLAGS) -c Source/GUI/Button.cpp

Component.o: Source/GUI/Component.cpp Include/Engine/GUI/Component.hpp
	$(CXX) $(CXXFLAGS) -c Source/GUI/Component.cpp

Container.o: Source/GUI/Container.cpp Include/Engine/GUI/Container.hpp
	$(CXX) $(CXXFLAGS) -c Source/GUI/Container.cpp

Label.o: Source/GUI/Label.cpp Include/Engine/GUI/Label.hpp
	$(CXX) $(CXXFLAGS) -c Source/GUI/Label.cpp

# Others

Application.o: Source/Application.cpp Include/Engine/Application.hpp
	$(CXX) $(CXXFLAGS) -c Source/Application.cpp

CommandQueue.o: Source/Application.cpp Include/Engine/CommandQueue.hpp
	$(CXX) $(CXXFLAGS) -c Source/CommandQueue.cpp

Player.o: Source/Player.cpp Include/Engine/Player.hpp
	$(CXX) $(CXXFLAGS) -c Source/Player.cpp

SoundPlayer.o: Source/SoundPlayer.cpp Include/Engine/SoundPlayer.hpp
	$(CXX) $(CXXFLAGS) -c Source/SoundPlayer.cpp

StateStack.o: Source/StateStack.cpp Include/Engine/StateStack.hpp
	$(CXX) $(CXXFLAGS) -c Source/StateStack.cpp

Command.o: Source/Command.cpp Include/Engine/Command.hpp
	$(CXX) $(CXXFLAGS) -c Source/Command.cpp

MusicPlayer.o: Source/MusicPlayer.cpp Include/Engine/MusicPlayer.hpp
	$(CXX) $(CXXFLAGS) -c Source/MusicPlayer.cpp

State.o: Source/State.cpp Include/Engine/State.hpp
	$(CXX) $(CXXFLAGS) -c Source/State.cpp

# States

SoleauState.o: Source/SoleauState.cpp Include/SoleauState.hpp
	$(CXX) $(CXXFLAGS) -c Source/SoleauState.cpp

PhoenixState.o: Source/PhoenixState.cpp Include/PhoenixState.hpp
	$(CXX) $(CXXFLAGS) -c Source/PhoenixState.cpp

TitleState.o: Source/TitleState.cpp Include/TitleState.hpp
	$(CXX) $(CXXFLAGS) -c Source/TitleState.cpp

SettingsState.o: Source/SettingsState.cpp Include/SettingsState.hpp
	$(CXX) $(CXXFLAGS) -c Source/SettingsState.cpp


#TestState.o: Source/TestState.cpp Include/TestState.hpp
#	$(CXX) $(CXXFLAGS) -c Source/TestState.cpp

#Npc.o: Source/Npc.cpp Include/Npc.hpp
#	$(CXX) $(CXXFLAGS) -c Source/Npc.cpp

Utility.o: Source/Utility.cpp Include/Engine/Utility.hpp
	$(CXX) $(CXXFLAGS) -c Source/Utility.cpp


###################

# To prevent make from getting confused by an actual file called clean, me may use .PHONY:
# .hppe "-" in -rm causes make to continue in spite of errors from rm
.PHONY: clean
clean:
	-rm $(OBJECTS) crusher.out

