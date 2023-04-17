#########################################
# Author: Albert Lazaro de Lara         #
#########################################


### variables ##############

CXX      := g++
OBJECTS  := main.o Button.o Component.o Container.o Label.o Application.o \
 CommandQueue.o Player.o SoundPlayer.o StateStack.o Command.o MusicPlayer.o \
State.o SoleauState.o PhoenixState.o TitleState.o SettingsState.o Utility.o # TestState.o Npc.o
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

# GUI

Button.o: src/GUI/Button.cpp include/Engine/GUI/Button.hpp
	$(CXX) $(CXXFLAGS) -c src/GUI/Button.cpp

Component.o: src/GUI/Component.cpp include/Engine/GUI/Component.hpp
	$(CXX) $(CXXFLAGS) -c src/GUI/Component.cpp

Container.o: src/GUI/Container.cpp include/Engine/GUI/Container.hpp
	$(CXX) $(CXXFLAGS) -c src/GUI/Container.cpp

Label.o: src/GUI/Label.cpp include/Engine/GUI/Label.hpp
	$(CXX) $(CXXFLAGS) -c src/GUI/Label.cpp

# Others

Application.o: src/Application.cpp include/Engine/Application.hpp
	$(CXX) $(CXXFLAGS) -c src/Application.cpp

CommandQueue.o: src/Application.cpp include/Engine/CommandQueue.hpp
	$(CXX) $(CXXFLAGS) -c src/CommandQueue.cpp

Player.o: src/Player.cpp include/Engine/Player.hpp
	$(CXX) $(CXXFLAGS) -c src/Player.cpp

SoundPlayer.o: src/SoundPlayer.cpp include/Engine/SoundPlayer.hpp
	$(CXX) $(CXXFLAGS) -c src/SoundPlayer.cpp

StateStack.o: src/StateStack.cpp include/Engine/StateStack.hpp
	$(CXX) $(CXXFLAGS) -c src/StateStack.cpp

Command.o: src/Command.cpp include/Engine/Command.hpp
	$(CXX) $(CXXFLAGS) -c src/Command.cpp

MusicPlayer.o: src/MusicPlayer.cpp include/Engine/MusicPlayer.hpp
	$(CXX) $(CXXFLAGS) -c src/MusicPlayer.cpp

State.o: src/State.cpp include/Engine/State.hpp
	$(CXX) $(CXXFLAGS) -c src/State.cpp

# States

SoleauState.o: src/SoleauState.cpp include/SoleauState.hpp
	$(CXX) $(CXXFLAGS) -c src/SoleauState.cpp

PhoenixState.o: src/PhoenixState.cpp include/PhoenixState.hpp
	$(CXX) $(CXXFLAGS) -c src/PhoenixState.cpp

TitleState.o: src/TitleState.cpp include/TitleState.hpp
	$(CXX) $(CXXFLAGS) -c src/TitleState.cpp

SettingsState.o: src/SettingsState.cpp include/SettingsState.hpp
	$(CXX) $(CXXFLAGS) -c src/SettingsState.cpp


#TestState.o: src/TestState.cpp include/TestState.hpp
#	$(CXX) $(CXXFLAGS) -c src/TestState.cpp

#Npc.o: src/Npc.cpp include/Npc.hpp
#	$(CXX) $(CXXFLAGS) -c src/Npc.cpp

Utility.o: src/Utility.cpp include/Engine/Utility.hpp
	$(CXX) $(CXXFLAGS) -c src/Utility.cpp


###################

# To prevent make from getting confused by an actual file called clean, me may use .PHONY:
# .hppe "-" in -rm causes make to continue in spite of errors from rm
.PHONY: clean
clean:
	-rm $(OBJECTS) crusher.out

