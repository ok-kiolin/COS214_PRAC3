app: Iterator.o ActiveState.o MutedState.o BannedState.o \
	ChatRoom.o CtrlCat.o Dogorithm.o \
	Command.o SendMessageCommand.o SaveMessageCommand.o LogMessageCommand.o \
	User.o Name1.o Name2.o Name3.o TestingMain.o
	g++ -Wall -std=c++98 \
		Iterator.o ActiveState.o MutedState.o BannedState.o \
		ChatRoom.o CtrlCat.o Dogorithm.o \
		Command.o SendMessageCommand.o SaveMessageCommand.o LogMessageCommand.o \
		User.o Name1.o Name2.o Name3.o TestingMain.o -o app

Iterator.o: Iterator.cpp Declarations.cpp
	g++ -Wall -std=c++98 -c Iterator.cpp

ActiveState.o: ActiveState.cpp Declarations.cpp
	g++ -Wall -std=c++98 -c ActiveState.cpp

MutedState.o: MutedState.cpp Declarations.cpp
	g++ -Wall -std=c++98 -c MutedState.cpp

BannedState.o: BannedState.cpp Declarations.cpp
	g++ -Wall -std=c++98 -c BannedState.cpp

ChatRoom.o: ChatRoom.cpp Declarations.cpp
	g++ -Wall -std=c++98 -c ChatRoom.cpp

CtrlCat.o: CtrlCat.cpp Declarations.cpp ChatRoom.cpp
	g++ -Wall -std=c++98 -c CtrlCat.cpp

Dogorithm.o: Dogorithm.cpp Declarations.cpp ChatRoom.cpp
	g++ -Wall -std=c++98 -c Dogorithm.cpp

Command.o: Command.cpp Declarations.cpp
	g++ -Wall -std=c++98 -c Command.cpp

SendMessageCommand.o: SendMessageCommand.cpp Declarations.cpp Command.cpp
	g++ -Wall -std=c++98 -c SendMessageCommand.cpp

SaveMessageCommand.o: SaveMessageCommand.cpp Declarations.cpp Command.cpp
	g++ -Wall -std=c++98 -c SaveMessageCommand.cpp

LogMessageCommand.o: LogMessageCommand.cpp Declarations.cpp Command.cpp
	g++ -Wall -std=c++98 -c LogMessageCommand.cpp

User.o: User.cpp Declarations.cpp ActiveState.cpp MutedState.cpp BannedState.cpp \
	Command.cpp SendMessageCommand.cpp SaveMessageCommand.cpp LogMessageCommand.cpp ChatRoom.cpp
	g++ -Wall -std=c++98 -c User.cpp

Name1.o: Name1.cpp Declarations.cpp User.cpp
	g++ -Wall -std=c++98 -c Name1.cpp

Name2.o: Name2.cpp Declarations.cpp User.cpp
	g++ -Wall -std=c++98 -c Name2.cpp

Name3.o: Name3.cpp Declarations.cpp User.cpp
	g++ -Wall -std=c++98 -c Name3.cpp

TestingMain.o: TestingMain.cpp Declarations.cpp
	g++ -Wall -std=c++98 -c TestingMain.cpp

run: app
	./app

clean:
	rm -f app Iterator.o ActiveState.o MutedState.o BannedState.o \
		ChatRoom.o CtrlCat.o Dogorithm.o \
		Command.o SendMessageCommand.o SaveMessageCommand.o LogMessageCommand.o \
		User.o Name1.o Name2.o Name3.o TestingMain.o
