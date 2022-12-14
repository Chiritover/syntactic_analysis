#include<filesystem>

#include "base/config.h"
#include "base/common.h"
#include "driver.h"
#include "utils/logger.h"


namespace fs = std::filesystem;

int main(int argc, char* argv[]) {
    Logger::Info("Starting the compiler...");
    if(argc < 2){
        Logger::Error("No input file specified.");
        return 1;
    }
    auto driver = Driver();
    const auto infile = fs::path{argv[1]};
    const auto outfile_name = infile.filename().replace_extension(".txt");
    const auto outfile = OUTPUT_DIR/outfile_name;
    if(!fs::exists(infile)){
        Logger::Error("Input file does not exist.");
        return 1;
    }
    Logger::Info("Input file: " + infile.string());
    Logger::Info("Output file: " + outfile.string());
    Logger::Info("Starting the compilation...");
    int out = driver.Parse(infile,outfile);
    Logger::Info("Compilation finished.");
    return out;
}