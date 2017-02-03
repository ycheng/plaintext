
all: plaintext

plaintext: plaintext.c
	$(CC) -o plaintext \
		 plaintext.c \
		`pkg-config --cflags gtk+-3.0` \
		`pkg-config --libs gtk+-3.0` \
		-Wall


clean:
	rm plaintext

install:
	cp plaintext /usr/bin/
	cp plaintext.desktop /usr/share/applications/
	

