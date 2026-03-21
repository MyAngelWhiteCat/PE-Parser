#pragma once

#include <iostream>
#include <filesystem>
#include <fstream>

namespace peparser {

    namespace fs = std::filesystem;

    class Parser {
    public:
        void Parse(const fs::path& pe_path);

    private:
        bool ValidatePE(std::ifstream& pe_ifstream);
        size_t GetFstreamsize(std::ifstream& pe_ifstream);
        

    };

}