//
//  Energy.cpp
//  Highrise
//
//  Created by Jimmy Xu on 2/15/19.
//  Copyright © 2019 Pocketz World. All rights reserved.
//

#include "Energy.hpp"
#include <chrono>
#include <thread>
#include <future>

using namespace highrise::core;

int Energy::current() {
    return _current;
}

void Energy::setCurrent(int current) {
    _current = current;
}

void Energy::update() {
    while (nextIncrementAt - time(nullptr) < 0 && _current < max) {
        nextIncrementAt = nextIncrementAt + time_t(_secondsPerIncrease);
        
        auto nextCurrent = _current + 1;
        nextCurrent = std::min(nextCurrent, max);
        setCurrent(nextCurrent);
    }
}

bool Energy::decrement(int amount) {
    if (_current < amount) {
        return false;
    }
    if(_current == max) {
        nextIncrementAt = _secondsPerIncrease;
    }
    auto nextCurrent = _current - amount;
    setCurrent(nextCurrent);
    
    return true;
}

void Energy::increment(int amount) {
    auto nextCurrent = _current + amount;
    nextCurrent = std::min(nextCurrent, max);
    setCurrent(nextCurrent);
}

