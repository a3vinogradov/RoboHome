#include "FSManagerNative.h"
#include <filesystem> // C++17 или новее
#include <fstream>

FSManagerNative::FSManagerNative(const String &root_dir) : RootDir(root_dir)
{ }

bool FSManagerNative::Setup()
{
    return true;
}

String FSManagerNative::ReadFile(const String &shortFileName)
{
    if (!Exists(shortFileName))
    {
        return "";
    }

    std::ifstream file(std::filesystem::path(RootDir) / shortFileName, std::ios::binary);
    if (!file) {
        return "";  
    }

    return std::string(
        (std::istreambuf_iterator<char>(file)),
        std::istreambuf_iterator<char>()
    );
}

bool FSManagerNative::Exists(const String &shortFileName)
{
    return std::filesystem::exists(std::filesystem::path(RootDir) / shortFileName);
}

