
all:
	make -C src all

clean:
	make -C src clean

install:
	make -C src install
	make -C icon install

