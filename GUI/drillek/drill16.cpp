/*
	g++ 16_drill.cpp Graph.cpp Window.cpp GUI.cpp Lines_window.cpp -o 16_drill fltk-config --ldflags --use-images -std=c++17
*/


#include "Lines_window.h"
#include "Graph.h"
#include "GUI.h"

int main()
{

	using namespace Graph_lib;

	Lines_window win{Point{100,100}, 1200, 600, "Vector_ref"};

	return gui_main();
}