#include "Sounds.h"

Sounds::Sounds() {
	srand(time(0));

	tapBuffer.loadFromFile("src/Sounds/tap.wav");
	tapSound.setBuffer(tapBuffer);
}

void Sounds::playSounds() {
	tapSound.setPitch(1 + rand() % 3);
	tapSound.play();
}