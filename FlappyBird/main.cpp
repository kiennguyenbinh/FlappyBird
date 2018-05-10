#include <iostream>
#include "Engine.h"
#undef main //* Fix LNK: unresolved external symbol SDL_main referenced in function main_utf8

int main(int argc, char **argv) {
	Engine::getInstance()->Execute();
	return 0;
}