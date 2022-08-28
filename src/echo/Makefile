all: server client

LIBS = -lev

server: server.c
	gcc -Os -Wall -Wextra -o server server.c $(LIBS)

client: client.c
	gcc -Os -Wall -Wextra -o client client.c

clean:
	rm server client