#pragma once

#include <cstdint>
#include <string_view>
#include <numbers>
#include <tuple>

class WindowClass
{
private:

public:
    void Draw(std::string_view label);
};

void render(WindowClass &window_obj);