//
//  Energy.hpp
//  Highrise
//
//  Created by Jimmy Xu on 2/15/19.
//  Copyright © 2019 Pocketz World. All rights reserved.
//

#ifndef Energy_hpp
#define Energy_hpp

#include <stdio.h>
#include "time.h"

namespace highrise {
    namespace core {
        
        class Energy {
        public:
            int current();
            void setCurrent(int current);
            
            int max = 20;
            time_t nextIncrementAt = time(nullptr);
            
            bool decrement(int amount);
            void increment(int amount);
        private:
            int _current = 0;
            int _secondsPerIncrease = 20;
            
            void update();
        };
        
    }
}
#endif /* Energy_hpp */
