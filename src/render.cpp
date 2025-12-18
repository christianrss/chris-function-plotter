#include <iostream>
#include <cmath>
#include <set>
#include <string_view>

#include <fmt/format.h>
#include <imgui.h>
#include <implot.h>

#include "render.hpp"

void WindowClass::Draw(std::string_view label)
{
    constexpr static auto window_flags =
        ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove |
        ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar;
    constexpr static auto window_size = ImVec2(640.0F, 480.0F);
    constexpr static auto window_pos = ImVec2(0.0F, 0.0F);

    ImGui::SetNextWindowSize(window_size);
    ImGui::SetNextWindowPos(window_pos);

    ImGui::Begin(label.data(), nullptr, window_flags);

    DrawSelection();
    DrawPlot();

    ImGui::End();
}

void WindowClass::DrawSelection()
{
    for (const auto func_name : functionNames)
    {
        const auto curr_function = functionNameMapping(func_name);
        auto selected = selectedFunctions.contains(curr_function);

        if (ImGui::Checkbox(func_name.data(), &selected))
        {
            if (selected)
                selectedFunctions.insert(curr_function);
            else
                selectedFunctions.erase(curr_function);
        }
    }
}

void WindowClass::DrawPlot()
{

}

WindowClass::Function WindowClass::functionNameMapping(std::string_view function_name)
{
    if (std::string_view{"sin(x)"} == function_name)
        return WindowClass::Function::SIN;

    if (std::string_view{"cos(x)"} == function_name)
        return WindowClass::Function::COS;

    return WindowClass::Function::NONE;
}

double evaluateFunction(const WindowClass::Function function, const double x)
{
    switch (function)
    {
        case WindowClass::Function::SIN:
        {
            return std::sin(x);
        }
        case WindowClass::Function::COS:
        {
            return std::sin(x);
        }
        case WindowClass::Function::NONE:
        default:
        {
            return 0.0F;
        }
    }
}

void render(WindowClass &window_obj)
{
    window_obj.Draw("Chris Function Plotter");
}