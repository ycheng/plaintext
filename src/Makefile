
all: plaintext

plaintext: plaintext.c
	$(CC) -O plaintext.c \
		`pkg-config --cflags gtk+-3.0` \
		`pkg-config --libs gtk+-3.0` \
		-o plaintext

clean:
	rm plaintext

install:
	cp plaintext /usr/bin/
	cp plaintext.desktop /usr/share/applications/
	

