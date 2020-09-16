//
//  EnergyBridge.cpp
//  Highrise
//
//  Created by Jimmy Xu on 2/15/19.
//  Copyright © 2019 Pocketz World. All rights reserved.
//

#include "EnergyBridge.hpp"

using namespace highrise::core;

bool EnergyBridge::isEnergyFull() {
	return (_energy.current() < _energy.max);
}

int EnergyBridge::updateAndGetCurrentEnergy() {
	return calculateCurrentEnergy(_energy);
}

void EnergyBridge::consumeEnergy() {
	_energy.decrement(1);
}

void EnergyBridge::refillEnergy() {
	_energy.setCurrent(_energy.max);
}

int EnergyBridge::energyUpdateHelper(Energy energy) {
	energy.update();
	return energy.current();
}
