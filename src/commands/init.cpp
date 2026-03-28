#include <iostream>
#include <fstream>
#include <filesystem>
#include <gollum.h>
#include <init.h>

void init(){

    std::string gollum_path = ".gollum";
    if(std::filesystem::exists(gollum_path)){
        std::cout << "gollum already initialised" << std::endl;
        return;
    }
    std::filesystem::create_directory(gollum_path);
    std::cout << "gollum initialised" << std::endl;

    std::filesystem::create_directory(gollum_path + "/objects");
    std::filesystem::create_directory(gollum_path + "/refs");
    std::filesystem::create_directory(gollum_path + "/refs/heads");
    std::ofstream(gollum_path + "/refs/heads/main") << NULL_HASH;
    std::ofstream(gollum_path + "/HEAD") << "ref: refs/heads/main";
    std::ofstream(gollum_path + "/index");
    std::ofstream(gollum_path + "/config");
  loadConfig();
}
