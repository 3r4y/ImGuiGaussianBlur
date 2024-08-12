#pragma once

#include <Windows.h>
#include <d3d11.h>
#include <iostream>
#include <string>
#include <opencv2/opencv.hpp>

#include "../Library/ImGui/imgui_impl_dx11.h"
#include "../Library/ImGui/imgui_impl_win32.h"
#include "../Library/ImGui/imgui.h"
#include "../Library/stb_image.h"

#include "TextureLoader.h"
#include "ImageProcessor.h"
#include "RenderUtils.h"

#include "Render.h"
#include "Windows/WindowBase.h"
#include "Manager.h"

#include "Windows/MainWindow.h"

namespace Global
{
    inline bool ShouldExit = false;
}