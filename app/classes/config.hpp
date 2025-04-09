const std::string MAIN_PATH = "../example-project/src/main.mcb";
std::string GLOBAL_BUFFER = "";

void globalWriteFunc() {
    std::ofstream file(MAIN_PATH);

    file.clear();
    file << GLOBAL_BUFFER;
    file.close();
}

std::string call(std::string funcName) {
    return "function main:" + funcName;
}

std::string schedule(std::string funcName, size_t delayInSeconds) {
    return "schedule function main:" + funcName + " " + std::to_string(delayInSeconds) + "s replace";
}

std::string repeat(std::string command, size_t times) {
    return "REPEAT (0, " + std::to_string(times) + ") {\n\t\t" + command + "\n\t}";
}

std::string itemInDistance(std::string itemName, size_t distance, size_t itemCount) {
    return "@e[type=minecraft:item,limit=1,distance=.." + std::to_string(distance) + ",nbt={Item:{id:\"" + itemName + "\", count: " + std::to_string(itemCount) + "}}]";
}

std::string killItem(std::string itemName, size_t distance, size_t itemCount) {
    return "kill @e[type=minecraft:item,limit=1,distance=.." + std::to_string(distance) + ",nbt={Item:{id:\"" + itemName + "\", count: " + std::to_string(itemCount) + "}}]";
}

std::string block(std::vector<std::string>& items) {
    std::string buff = "block {\n\t\t";
    for (std::string& s : items) {
        buff += s;
        buff += "\n\t\t";
    }
    for (int i = 0; i < 3; i++) {
        buff.pop_back();
    }
    buff += "\n\t}";
    return buff;
}

void funcWrite(std::string& name, std::vector<std::string>& contentVec, FunctionType& type) {
    std::string typeStr = "";
    switch (type) {
        case FunctionType::LOAD:
            typeStr = " load";
        break;
        case FunctionType::TICK:
            typeStr = " tick";
        break;
    }
    std::string buff = "function " + name + typeStr + " {\n";

    for (std::string& s : contentVec) {
        buff += "\t";
        buff += s;
        buff += "\n";
    }
    buff.pop_back();//Del last char '\n'
    buff += "\n}\n";
    GLOBAL_BUFFER += buff;
}
