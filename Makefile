search-cli: main.o search.o stats.o text.o Graph.o
	gcc -o search-cli main.o search.o stats.o text.o Graph.o

main.o: main.c search.h stats.h text.h
	gcc -c  main.c

stats.o: stats.c
	gcc -c stats.c

search.o: search.c
	gcc -c search.c

text.o: text.c
	gcc -c text.c

Graph.o:Graph.c
	gcc -c Graph.c

clean:
	rm search-cli.exe search-cli.out main.o search.o stats.o text.o

