#include "Logger/logger.h"


int main() {
    logging::Logger logger;
    logger.Init();
    LOG_DEBUG("Ready");
}