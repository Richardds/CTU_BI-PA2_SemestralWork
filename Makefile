# make all nebo make vytvoří veškeré výstupy, generované ze zdrojového kódu.
# make compile vytvoří binární podobu semestrální práce, výsledek bude uložen do souboru <login>/<login>.
# make run spustí binární podobu semestrální práce.
# make clean smaže všechny vygenerované soubory a uvede adresář <login> do původního stavu.
# make doc vygeneruje dokumentaci do adresáře <login>/doc. Dokumentace může být vytvořená staticky ve formátu HTML (pak make doc nebude dělat nic) nebo dynamicky generovaná programem doxygen (generována pouze v HTML).

USERNAME = boldiric
CC = g++
CXXFLAGS = -Wall -pedantic -std=c++14
LDFLAGS = -lSDL2

all: compile doc

compile: $(USERNAME)

run:
	./$(USERNAME)

clean:
	rm -rf obj/*
	rm -rf doc/html
	rm -f $(USERNAME)

doc:
	doxygen Doxyfile

$(USERNAME): obj/$(USERNAME).o
	$(CC) $(CXXFLAGS) $^ $(LDFLAGS) -o $@

obj/$(USERNAME).o: obj/main.o obj/BuildingGenerator.o obj/SemestralWork.o obj/Core/Renderer.o obj/Core/Window.o obj/Game/Objects/Building.o obj/Game/Objects/BuildingConfig.o obj/Game/GameLogic.o obj/Game/WorldStats.o obj/Graphics/Entity.o obj/Graphics/HasPosition.o obj/Graphics/Rectangle.o obj/System/Containers/IdentifyingCollection.o obj/System/BinaryReader.o obj/System/BinaryWriter.o obj/System/Logger.o obj/System/Trace.o obj/Tools/BuildingConfigGenerator.o
	ld -r $^ -o $@

obj/main.o: src/main.cpp \
 src/SemestralWork.h \
 src/Core/core.h \
 src/System/Trace.h \
 src/System/Logger.h \
 src/Core/Window.h \
 src/Core/Renderer.h \
 src/Graphics/Entity.h \
 src/Graphics/HasPosition.h \
 src/Core/Renderer.h src/Game/GameLogic.h \
 src/Game/WorldStats.h \
 src/System/Containers/IdentifyingCollection.h \
 src/Game/Exportable.h \
 src/System/BinaryReader.h \
 src/System/BinaryWriter.h \
 src/Game/Objects/BuildingConfig.h \
 src/Game/Objects/Building.h \
 src/Graphics/Rectangle.h \
 src/Tools/BuildingConfigGenerator.h \
 src/BuildingGenerator.h
	$(CC) $(CXXFLAGS) -c -o $@ $<

obj/BuildingGenerator.o: src/BuildingGenerator.cpp \
 src/BuildingGenerator.h \
 src/Tools/BuildingConfigGenerator.h \
 src/Core/core.h \
 src/System/Trace.h \
 src/System/Logger.h \
 src/Game/WorldStats.h \
 src/System/Containers/IdentifyingCollection.h \
 src/Game/Exportable.h \
 src/System/BinaryReader.h \
 src/System/BinaryWriter.h \
 src/Game/Objects/BuildingConfig.h \
 src/Game/WorldStats.h
	$(CC) $(CXXFLAGS) -c -o $@ $<

obj/SemestralWork.o: src/SemestralWork.cpp \
 src/SemestralWork.h \
 src/Core/core.h \
 src/System/Trace.h \
 src/Core/../System/Logger.h \
 src/Core/Window.h \
 src/Core/Renderer.h \
 src/Graphics/Entity.h \
 src/Graphics/HasPosition.h \
 src/Game/GameLogic.h \
 src/Game/WorldStats.h \
 src/System/Containers/IdentifyingCollection.h \
 src/Game/Exportable.h \
 src/System/BinaryReader.h \
 src/System/BinaryWriter.h \
 src/Game/Objects/BuildingConfig.h \
 src/Game/WorldStats.h \
 src/Game/Objects/Building.h \
 src/Graphics/Rectangle.h
	$(CC) $(CXXFLAGS) -c -o $@ $<

obj/Core/Renderer.o: src/Core/Renderer.cpp \
 src/Core/Renderer.h \
 src/Core/Window.h \
 src/Core/core.h \
 src/System/Trace.h \
 src/System/Logger.h \
 src/Graphics/Entity.h \
 src/Graphics/HasPosition.h
	mkdir -p obj/Core
	$(CC) $(CXXFLAGS) -c -o $@ $<

obj/Core/Window.o: src/Core/Window.cpp src/Core/Window.h
	mkdir -p obj/Core
	$(CC) $(CXXFLAGS) -c -o $@ $<

obj/Game/Objects/Building.o: src/Game/Objects/Building.cpp \
 src/Game/Objects/Building.h \
 src/Graphics/Rectangle.h \
 src/Graphics/Entity.h \
 src/Graphics/HasPosition.h \
 src/Core/core.h \
 src/System/Trace.h \
 src/System/Logger.h \
 src/Core/Renderer.h \
 src/Core/Window.h \
 src/Game/Objects/BuildingConfig.h \
 src/Game/WorldStats.h \
 src/System/Containers/IdentifyingCollection.h \
 src/Game/Exportable.h \
 src/System/BinaryReader.h \
 src/System/BinaryWriter.h \
 src/Game/GameLogic.h \
 src/Game/Objects/../WorldStats.h
	mkdir -p obj/Game/Objects
	$(CC) $(CXXFLAGS) -c -o $@ $<

obj/Game/Objects/BuildingConfig.o: src/Game/Objects/BuildingConfig.cpp \
 src/Game/Objects/BuildingConfig.h \
 src/Core/core.h \
 src/System/Trace.h \
 src/System/Logger.h \
 src/Game/WorldStats.h \
 src/System/Containers/IdentifyingCollection.h \
 src/Game/Exportable.h \
 src/System/BinaryReader.h \
 src/System/BinaryWriter.h
	mkdir -p obj/Game/Objects
	$(CC) $(CXXFLAGS) -c -o $@ $<

obj/Game/GameLogic.o: src/Game/GameLogic.cpp \
 src/Game/GameLogic.h \
 src/Core/Renderer.h \
 src/Core/Window.h \
 src/Core/core.h \
 src/System/Trace.h \
 src/System/Logger.h \
 src/Graphics/Entity.h \
 src/Graphics/HasPosition.h \
 src/Game/WorldStats.h \
 src/System/Containers/IdentifyingCollection.h \
 src/Game/Exportable.h \
 src/System/BinaryReader.h \
 src/System/BinaryWriter.h \
 src/Game/Objects/BuildingConfig.h \
 src/Game/Objects/Building.h \
 src/Graphics/Rectangle.h
	mkdir -p obj/Game
	$(CC) $(CXXFLAGS) -c -o $@ $<

obj/Game/WorldStats.o: src/Game/WorldStats.cpp \
 src/Game/WorldStats.h \
 src/Core/core.h \
 src/System/Trace.h \
 src/System/Logger.h \
 src/System/Containers/IdentifyingCollection.h \
 src/Game/Exportable.h \
 src/System/BinaryReader.h \
 src/System/BinaryWriter.h \
 src/Game/Objects/Building.h \
 src/Graphics/Rectangle.h \
 src/Graphics/Entity.h \
 src/Graphics/HasPosition.h \
 src/Core/Renderer.h \
 src/Core/Window.h \
 src/Game/Objects/BuildingConfig.h
	mkdir -p obj/Game
	$(CC) $(CXXFLAGS) -c -o $@ $<

obj/Graphics/Entity.o: src/Graphics/Entity.cpp \
 src/Graphics/Entity.h \
 src/Graphics/HasPosition.h \
 src/Core/core.h \
 src/System/Trace.h \
 src/System/Logger.h \
 src/Core/Renderer.h \
 src/Core/Window.h
	mkdir -p obj/Graphics
	$(CC) $(CXXFLAGS) -c -o $@ $<

obj/Graphics/HasPosition.o: src/Graphics/HasPosition.cpp \
 src/Graphics/HasPosition.h \
 src/Core/core.h \
 src/System/Trace.h \
 src/System/Logger.h
	mkdir -p obj/Graphics
	$(CC) $(CXXFLAGS) -c -o $@ $<

obj/Graphics/Rectangle.o: src/Graphics/Rectangle.cpp \
 src/Graphics/Rectangle.h \
 src/Graphics/Entity.h \
 src/Graphics/HasPosition.h \
 src/Core/core.h \
 src/System/Trace.h \
 src/System/Logger.h \
 src/Core/Renderer.h \
 src/Core/Window.h
	mkdir -p obj/Graphics
	$(CC) $(CXXFLAGS) -c -o $@ $<

obj/System/Containers/IdentifyingCollection.o: src/System/Containers/IdentifyingCollection.cpp \
 src/System/Containers/IdentifyingCollection.h \
 src/Core/core.h \
 src/System/Trace.h \
 src/System/Logger.h
	mkdir -p obj/System/Containers
	$(CC) $(CXXFLAGS) -c -o $@ $<

obj/System/BinaryReader.o: src/System/BinaryReader.cpp \
 src/System/BinaryReader.h \
 src/Game/Exportable.h \
 src/System/BinaryWriter.h \
 src/Game/Exportable.h
	mkdir -p obj/System
	$(CC) $(CXXFLAGS) -c -o $@ $<

obj/System/BinaryWriter.o: src/System/BinaryWriter.cpp \
 src/System/BinaryWriter.h \
 src/Game/Exportable.h \
 src/System/BinaryReader.h
	mkdir -p obj/System
	$(CC) $(CXXFLAGS) -c -o $@ $<

obj/System/Logger.o: src/System/Logger.cpp \
 src/System/Logger.h \
 src/System/Trace.h
	mkdir -p obj/System
	$(CC) $(CXXFLAGS) -c -o $@ $<

obj/System/Trace.o: src/System/Trace.cpp \
 src/System/Trace.h
	mkdir -p obj/System
	$(CC) $(CXXFLAGS) -c -o $@ $<

obj/Tools/BuildingConfigGenerator.o: src/Tools/BuildingConfigGenerator.cpp \
 src/Tools/BuildingConfigGenerator.h \
 src/Core/core.h \
 src/System/Trace.h \
 src/System/Logger.h \
 src/Game/WorldStats.h \
 src/System/Containers/IdentifyingCollection.h \
 src/Game/Exportable.h \
 src/System/BinaryReader.h \
 src/System/BinaryWriter.h \
 src/Game/Objects/BuildingConfig.h
	mkdir -p obj/Tools
	$(CC) $(CXXFLAGS) -c -o $@ $<
