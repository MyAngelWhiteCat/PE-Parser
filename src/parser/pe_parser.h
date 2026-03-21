#pragma once

#include <iostream>
#include <filesystem>

namespace peparser {

    namespace fs = std::filesystem;

    class Parser {
    public:
        void Parse(const fs::path& pe_path);

    };

}