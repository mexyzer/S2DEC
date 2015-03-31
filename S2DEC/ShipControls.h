#pragma once

#include "Component.h"
#include "Controls.h"

using namespace S2D;

class ShipControls : public Component{
private:
	Controls* controls{nullptr};

	bool pressedOrHeld(KeyState ks){
		if(ks == KEY_PRESSED || ks == KEY_HELD){
			return true;
		}
		return false;
	}

public:
	ShipControls(Controls* controls) : controls(controls){
		assert(controls != nullptr);
	}

	bool up(){
		KeyState ks = controls->getKeyState(sf::Keyboard::W);
		return pressedOrHeld(ks);
	}

	bool down(){
		KeyState ks = controls->getKeyState(sf::Keyboard::S);
		return pressedOrHeld(ks);
	}

	bool left(){
		KeyState ks = controls->getKeyState(sf::Keyboard::A);
		return pressedOrHeld(ks);
	}

	bool right(){
		KeyState ks = controls->getKeyState(sf::Keyboard::D);
		return pressedOrHeld(ks);
	}
};