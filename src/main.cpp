#include "Logger/logger.h"
#include "Parser/pe_parser.h"

int main() {
    logging::Logger logger;
    logger.Init();
    LOG_DEBUG("Ready");
    peparser::Parser parser;
    auto curpath = std::filesystem::current_path();
    parser.Parse(curpath / "example.exe");
    parser.Parse(curpath / "wrong_example");
}