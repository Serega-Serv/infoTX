client: client.o myLib.so
	g++ -L ./lib/ client.o ./lib/myLib.so -o client -std=c++17
client.o: client.cpp lib/myLib.h
	g++ -I ./lib/ -c client.cpp -o client.o -std=c++17
myLib.so: myLib.o
	g++ -shared ./lib/myLib.o -o ./lib/myLib.so
myLib.o: lib/myLib.cpp 
	g++ -fPIC -c lib/myLib.cpp -o ./lib/myLib.o -std=c++17
clean:
	rm --force  lib/*.o lib/*.so  *.o *.so client