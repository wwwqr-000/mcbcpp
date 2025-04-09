#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

#include "classes/enums.hpp"
#include "classes/config.hpp"
#include "classes/function.hpp"

int main() {
    Function minClock("clock_60_sec", FunctionType::DEFAULT);
    minClock.add("say 1 minute passed...");
    minClock.add(repeat("give @a minecraft:stick 1", 4));
    minClock.add(schedule(minClock.getName(), 60));
    minClock.write();

    Function welcome("on_load", FunctionType::LOAD);
    welcome.add("say Thanks for installing this example datapack!");
    welcome.add(call(minClock.getName()));
    welcome.write();


    //Check for glass_bottle in cauldron
    Function cauldron("glass_check", FunctionType::DEFAULT);
    std::stringstream ss;
    ss << "execute as " + itemInDistance("minecraft:glass_bottle", 10, 1) + " at " + itemInDistance("minecraft:glass_bottle", 10, 1) + " run ";
    ss << killItem("minecraft:glass_bottle", 1, 1);
    cauldron.add(ss.str());
    cauldron.write();
    //

    Function globalTick("globTick", FunctionType::TICK);
    globalTick.add(call(cauldron.getName()));
    globalTick.write();

    globalWriteFunc();
    return 0;
}
