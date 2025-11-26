bin/testCircle:src/testCircle.cpp src/Circle.cpp src/Shape.cpp src/Point2D.cpp
	
	g++ -c src/Point2D.cpp -o bin/Point2D.o
	g++ -c src/Shape.cpp -o bin/Shape.o
	g++ -c src/Circle.cpp -o bin/Circle.o
	g++ -c src/testCircle.cpp -o bin/testCircle.o
	g++ -o bin/testCircle bin/testCircle.o bin/Circle.o bin/Shape.o bin/Point2D.o
bin/testRectangle: src/testRectangle.cpp src/Rectangle.cpp src/Shape.cpp src/Point2D.cpp
	g++ -c src/Point2D.cpp -o bin/Point2D.o
	g++ -c src/Shape.cpp -o bin/Shape.o
	g++ -c src/Rectangle.cpp -o bin/Rectangle.o
	g++ -c src/testRectangle.cpp -o bin/testRectangle.o
	g++ -o bin/testRectangle bin/Point2D.o bin/Shape.o bin/Rectangle.o bin/testRectangle.o
 
bin/testSquare: src/testSquare.cpp src/Rectangle.cpp src/Shape.cpp src/Point2D.cpp src/Square.cpp

	g++ -c src/Point2D.cpp -o bin/Point2D.o
	g++ -c src/Shape.cpp -o bin/Shape.o
	g++ -c src/Rectangle.cpp -o bin/Rectangle.o
	g++ -c src/Square.cpp -o bin/Square.o
	g++ -c src/testSquare.cpp -o bin/testSquare.o
	g++ -o bin/testSquare bin/Point2D.o bin/Shape.o bin/Rectangle.o bin/Square.o bin/testSquare.o 
