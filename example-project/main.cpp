#include <iostream>
#include <fstream>
#include <vector>

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

    globalWriteFunc();
    return 0;
}
