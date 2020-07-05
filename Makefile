search-cli: main.o search.o stats.o text.o
	gcc -o search-cli main.o search.o stats.o text.o

main.o: main.c search.h stats.h text.h
	gcc -c  main.c

stats.o: stats.c
	gcc -c stats.c

search.o: search.c
	gcc -c search.c

text.o: text.c
	gcc -c text.c

clean:
	rm search-cli main.o search.o stats.o text.o

