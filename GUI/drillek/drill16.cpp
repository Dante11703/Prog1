/*
	g++ 16_drill.cpp Graph.cpp Window.cpp GUI.cpp Lines_window.cpp -o 16_drill fltk-config --ldflags --use-images -std=c++17
*/


#include "../source/Lines_window.h"
#include "../source/Graph.h"
#include "../source/GUI.h"

int main()
{
try {
	Lines_window win{Point{100,100},1280,720,"Lines"};
	return gui_main();
} catch (exception& e){
	cerr <<e.what() << endl;
	return 1;
}catch(...){
	cerr << "Something went wrong!" <<endl;
	return 2;
}
}