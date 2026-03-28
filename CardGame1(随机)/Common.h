#ifndef COMMON_H
#define COMMON_H

#include <iostream>
#include <string.h>

using PlayerGameR = std::pair<std::pair<uint64_t, std::string>, std::pair<int, int>>;

using OutFunc = void(*)(std::string);

using InputFunc = void(*)(std::string&);

#endif // !COMMON_H