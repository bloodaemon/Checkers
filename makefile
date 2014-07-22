OBJS = ArrayStack.o Captured.o Board.o Node.o LinkedStack.o LinkedQueue.o Action.o ActionNode.o ActionQueue.o GameTreeNode.o PostOrderIterator.o GameTree.o Game.o Checkers.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFlAGS = -Wall $(DEBUG)
FNAME = Checkers.out

Checkers.out: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o $(FNAME)

Checkers.o: Checkers.cpp Game.h
	$(CC) $(CFLAGS) Checkers.cpp

Game.o: Game.h Game.cpp Board.h GameTree.h ActionQueue.h Action.h globals.h
	$(CC) $(CFLAGS) Game.cpp

GameTree.o: GameTree.h GameTree.cpp PostOrderIterator.h GameTreeNode.h LinkedQueue.h ActionQueue.h globals.h
	$(CC) $(CFLAGS) GameTree.cpp

PostOrderIterator.o: PostOrderIterator.h PostOrderIterator.cpp GameTreeNode.h LinkedStack.h
	$(CC) $(CFLAGS) PostOrderIterator.cpp

GameTreeNode.o: GameTreeNode.h GameTreeNode.cpp GameTree.h ActionQueue.h Action.h Board.h
	$(CC) $(CFLAGS) GameTreeNode.cpp

ActionQueue.o: ActionQueue.h ActionQueue.cpp ActionNode.h Action.h
	$(CC) $(CFLAGS) ActionQueue.cpp

ActionNode.o: ActionNode.h ActionNode.cpp Action.h
	$(CC) $(CFLAGS) ActionNode.cpp

Action.o: Action.h Action.cpp
	$(CC) $(CFLAGS) Action.cpp

LinkedQueue.o: LinkedQueue.h LinkedQueue.cpp Node.h
	$(CC) $(CFLAGS) LinkedQueue.cpp

LinkedStack.o: LinkedStack.h LinkedStack.cpp Node.h
	$(CC) $(CFLAGS) LinkedStack.cpp

Node.o: Node.h Node.cpp
	$(CC) $(CFLAGS) Node.cpp

Board.o: Board.h Board.cpp Captured.h GameTree.h globals.h
	$(CC) $(CFLAGS) Board.cpp

Captured.o: Captured.h Captured.cpp ArrayStack.h
	$(CC) $(CFLAGS) Captured.cpp

ArrayStack.o: ArrayStack.h ArrayStack.cpp
	$(CC) $(CFLAGS) ArrayStack.cpp

clean:
	rm *.o $(FNAME)
