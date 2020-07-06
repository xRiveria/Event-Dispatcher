#pragma once

//----- C++ Library
#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <sstream>
#include <utility>
#include <functional>

//Windows API
#include <Windows.h>


#define EVENT_SYSTEM_ASSERT(value) std::cout << "Event Detected: " << value << std::endl;
#define EVENT_SYSTEM_SUCCESS(value) std::cout << "Success: " << value <<std::endl;