#pragma once
#include <string>
#include <vector>

namespace hr {

	std::string output_str(const char* path);

	std::vector<std::string> split_string(std::string input_string);
	std::vector<std::string> split(const std::string&);

	std::string ltrim(const std::string&);
	std::string rtrim(const std::string&);
}

