#ifndef CORE_CONFIG_H
#define CORE_CONFIG_H

#include <string>

struct Config
{
	int windowWidth = 1280;
	int windowHeight = 720;
	std::string windowTitle = "st_game_engine";
};

std::string DumpConfig(const Config &cfg);

Config LoadConfig(const std::string &path);

#endif

