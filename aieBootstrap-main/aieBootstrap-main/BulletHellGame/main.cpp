#include "Application2D.h"

int main() {
	
	// allocation
	auto app = new Application2D();

	// initialise and loop
	app->run("AIE", 500, 900, false);

	// deallocation
	delete app;

	return 0;
}