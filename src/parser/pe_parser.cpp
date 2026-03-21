#include "pe_parser.h"
#include "../Logger/logger.h"

#include <fstream>
#include <string>

namespace peparser {

    using namespace std::literals;

    void Parser::Parse(const fs::path& pe_path) 
    {
        std::ifstream file_bytes(pe_path, std::ios::binary);
        if (!file_bytes) {
            LOG_ERROR("Can't open "s + pe_path.string());
        }
        LOG_DEBUG("Load "s + pe_path.string());
        if (ValidatePE(file_bytes)) {
            LOG_INFO("PE file");
        }
        else {
            LOG_ERROR("Not PE file");
        }
    }

    bool Parser::ValidatePE(std::ifstream& pe_ifstream)
    {
        const size_t mz_bytes_count = 2;
        if (GetFstreamsize(pe_ifstream) <= mz_bytes_count) {
            return false;
        }
        char mz_bytes[2];
        pe_ifstream.read(mz_bytes, mz_bytes_count);
        if (mz_bytes[0] != 'M' || mz_bytes[1] != 'Z') {
            return false;
        }
        // more validate logic?;
        return true;
    }

    size_t Parser::GetFstreamsize(std::ifstream& pe_ifstream)
    {
        size_t current_streampos = pe_ifstream.tellg();
        pe_ifstream.seekg(0, std::ios::end);
        if (pe_ifstream.fail()) {
            return 0;
        }
        size_t file_size = pe_ifstream.tellg();
        pe_ifstream.seekg(current_streampos);
        return file_size;
    }

}