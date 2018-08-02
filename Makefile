main: Parser.o DataSequence.o SymbolTable.o Builtin.o main.o MetaActions.o Engine.o StateNode.o ConsoleStreamWriter.o FileStreamReader.o Rule.o Segment.o Sequence.o RuleActivation.o
	g++ -o main *.o

Parser.o: Parser.cpp
	g++ -c Parser.cpp

SymbolTable.o: SymbolTable.cpp
	g++ -c SymbolTable.cpp

Builtin.o: Builtin.cpp
	g++ -c Builtin.cpp

main.o: main.cpp
	g++ -c main.cpp

StateNode.o: StateNode.cpp
	g++ -c StateNode.cpp

MetaActions.o: MetaActions.cpp
	g++ -c MetaActions.cpp

DataSequence.o: DataSequence.cpp
	g++ -c DataSequence.cpp

Engine.o: Engine.cpp
	g++ -c Engine.cpp

ConsoleStreamWriter.o: ConsoleStreamWriter.cpp
	g++ -c ConsoleStreamWriter.cpp

FileStreamReader.o: FileStreamReader.cpp
	g++ -c FileStreamReader.cpp

Rule.o: Rule.cpp
	g++ -c Rule.cpp

RuleActivation.o: RuleActivation.cpp
	g++ -c RuleActivation.cpp

Segment.o: Segment.cpp
	g++ -c Segment.cpp

Sequence.o: Sequence.cpp
	g++ -c Sequence.cpp

