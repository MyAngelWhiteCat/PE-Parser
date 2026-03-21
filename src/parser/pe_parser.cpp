#include "pe_parser.h"
#include "../Logger/logger.h"

#include <fstream>
#include <string>

namespace peparser {

    using namespace std::literals;

    void Parser::Parse(const fs::path& pe_path) {
        std::ifstream file_bytes(pe_path, std::ios::binary);
        if (!file_bytes) {
            LOG_ERROR("Can't open "s + pe_path.string());
        }

        std::string line;
        while (std::getline(file_bytes, line)) {
            std::cout << line << "\n";
        }
    }

}