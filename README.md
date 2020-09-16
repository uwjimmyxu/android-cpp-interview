# android-cpp-interview

This C++ test captures a real bug that we ran into here at Highrise. 

There are two classes: EnergyBridge and Energy. 

EnergyBridge is used as an interface and is called by the UI to interact with Energy. Energy is the data model that stores the user's current energy.

The manifestation of the bug is that the isEnergyFull() function of EnergyBridge always returns true, regardless of how long it's elapsed since energy has recharged.

Please track down the root cause of this bug.
