make:
	g++ -c glad.c 
	g++ main.cpp  glad.o -lglfw -lrt -lm -ldl -lX11 -lpthread -lxcb -lXau -lXdmcp -o dagame
	