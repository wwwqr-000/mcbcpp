#pragma once

class Function {
    private:
        std::string name;
        FunctionType type;
        std::vector<std::string> contentVec;

    public:
        Function(std::string name, FunctionType type, std::vector<std::string> contentVec): name(name), type(type), contentVec(contentVec) {}
        Function(std::string& name, FunctionType& type, std::vector<std::string>& contentVec) : name(name), type(type), contentVec(contentVec) {}
        Function(std::string& name, FunctionType& type) : name(name), type(type) {}
        Function(std::string name, FunctionType type) : name(name), type(type) {}

        void write() {
            std::string realName = this->name;
            switch (this->type) {
                case FunctionType::LOAD:
                    realName = "load";
                break;
            }
            funcWrite(realName, this->contentVec, this->type);
        }

        std::string& getName() { return this->name; }
        std::vector<std::string>& getContentVec() { return this->contentVec; }
        FunctionType& getType() { return this->type; }
        void add(std::string content) { this->contentVec.push_back(content); }
        void add(std::string& content) { this->contentVec.emplace_back(content); }
};
