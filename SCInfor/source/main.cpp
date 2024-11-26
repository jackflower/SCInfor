#include "Game/Game.h"
#include <iostream>
#include "Utilities/Miscellaneous/Integer.h"
#include "Utilities/Miscellaneous/Float.h"
#include "Utilities/Miscellaneous/Miscellaneous.h"

// 2024-03-21 - tests...
#include "Experience/Tests/Tests.hpp"

using namespace game;

int main()
{
	SingletonCleaner cleaner;
	gGame.run();
	return 0;
}
