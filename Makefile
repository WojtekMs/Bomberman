main:
	g++ *.cpp -c
	g++ *.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system
	./sfml-app
