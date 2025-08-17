#pragma once
#include <iostream>
#include <SFML/Audio.hpp>
#include <ctime>
#include <cstdlib>

using namespace std;
using namespace sf;

class Sounds
{
private:
	SoundBuffer tapBuffer;

public:
	Sound tapSound;
	Sounds();
	void playSounds();
};

