#pragma once
#include <iostream>
#include <vector>
#ifndef _WIN32
#endif

#if defined(_WIN32)
#define EXPORT __declspec(dllexport)
#else
#define EXPORT
#endif




class EXPORT Blur {
public:
    Blur();
    void setSource(std::string path);
    void setBlurAmount(uint32_t j);
    const std::vector<uint8_t> dataChanged();
    int getChannels();
    int getRows();
    int getCols();

    //int display_dst( int delay );

private:
    std::vector<uint8_t> array;

};


