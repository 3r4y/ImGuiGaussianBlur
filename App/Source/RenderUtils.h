#pragma once

class RenderUtils {
public:
    static ID3D11Texture2D* LoadTextureFromMat(cv::Mat& mat, ID3D11Device* device, ID3D11DeviceContext* context);
};
