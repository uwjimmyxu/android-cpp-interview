//
//  EnergyBridge.hpp
//  Highrise
//
//  Created by Jimmy Xu on 2/15/19.
//  Copyright © 2019 Pocketz World. All rights reserved.
//

#ifndef Energy_hpp
#define Energy_hpp

#include <stdio.h>
#include "time.h"
#include "Energy.hpp"

namespace highrise {
    namespace core {
        
        class EnergyBridge {
        public:
            bool isEnergyFull(); //BUG: This always returns true. Why?

            int updateAndGetCurrentEnergy(); //This is called on a 0.5s timer to update and display the latest energy value
            
            void consumeEnergy();
            void refillEnergy();

        private:
            Energy _energy;            
            int energyUpdateHelper(Energy energy);
        };
        
    }
}
#endif /* Energy_hpp */
