#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

#include "classes/enums.hpp"
#include "classes/config.hpp"
#include "classes/function.hpp"

int main() {
    //Check for glass_bottle in cauldron
    Function cauldron("glass_check", FunctionType::DEFAULT);
    std::vector<std::string> items;
    items.push_back(killItem("minecraft:glass_bottle", 1, 1));
    items.push_back("say deleted glass bottle");
    cauldron.add("execute as " + itemInDistance("minecraft:glass_bottle", 10, 1) + " at " + itemInDistance("minecraft:glass_bottle", 10, 1) + " run " + block(items));
    cauldron.write();
    //

    //Player tick
    Function playerTick("player_tick", FunctionType::DEFAULT);
    playerTick.add("say Hello from me!");
    playerTick.add(call(cauldron.getName()));
    playerTick.write();
    //

    //World tick
    Function worldTick("world_tick", FunctionType::DEFAULT);
    worldTick.add("execute as @a at @s run " + call(playerTick.getName()));
    worldTick.add(schedule(worldTick.getName(), 10));
    worldTick.write();
    //

    //Load
    Function mainLoad("main_load", FunctionType::LOAD);
    mainLoad.add("say Loaded!");
    mainLoad.add(call(worldTick.getName()));
    mainLoad.write();
    //

    globalWriteFunc();
    return 0;
}
