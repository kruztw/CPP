all:
	nasm -fbin echo.S -o echo.bin
	g++ simple.cpp -o simple -lunicorn -lpthread 

run:
	./simple echo.bin 

clean:
	-rm echo.bin simple || true
