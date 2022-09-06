all:  compile

compile:
	g++ -c glad.c 
	g++ main.cpp  glad.o -lglfw -lrt -lm -ldl -lX11 -lpthread -lxcb -lXau -lXdmcp -lncurses -o dagame
	
run:
	./dagame

test:  all run

clean:
	rm glad.o dagame