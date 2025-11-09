#include "core/Config.h"
#include <fstream>
#include <sstream>

std::string DumpConfig(const Config &cfg)
{
	std::string out;
	out += "Config { ";
	out += "windowWidth=" + std::to_string(cfg.windowWidth);
	out += ", windowHeight=" + std::to_string(cfg.windowHeight);
	out += ", windowTitle=\"" + cfg.windowTitle + "\"";
	out += " }";
	return out;
}

Config LoadConfig(const std::string &path)
{
	Config cfg;
	std::ifstream f(path);
	if (!f.is_open()) return cfg;

	std::string line;
	while (std::getline(f, line))
	{
		if (line.empty()) continue;
		std::istringstream iss(line);
		std::string key;
		if (std::getline(iss, key, '='))
		{
			std::string value;
			if (std::getline(iss, value))
			{
				if (key == "window_width") cfg.windowWidth = std::stoi(value);
				else if (key == "window_height") cfg.windowHeight = std::stoi(value);
				else if (key == "window_title") cfg.windowTitle = value;
			}
		}
	}
	return cfg;
}

