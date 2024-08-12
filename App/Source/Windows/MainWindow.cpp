#define STB_IMAGE_IMPLEMENTATION

#include "../Global.h"


void MainWindow::Render()
{
    Manager::SetNextSize(1155.0f, 610.0f);

    //with normal image (example from https://github.com/ocornut/imgui/wiki/Image-Loading-and-Displaying-Examples)
    int my_image_width = 0;
    int my_image_height = 0;
    ID3D11ShaderResourceView* my_texture = NULL;
    bool ret = TextureLoader::LoadTextureFromFile("C:/image.jpg", &my_texture, &my_image_width, &my_image_height);
    IM_ASSERT(ret);
    ImGui::Image((void*)my_texture, ImVec2(my_image_width, my_image_height));
   
    ImGui::SameLine();
    
    //with GaussianBlur image (example from https://github.com/JimmyHHua/opencv_tutorials/blob/master/python/code_022/opencv_022.py)
    cv::Mat src = cv::imread("C:/image.jpg");
    cv::Mat dst = ImageProcessor::ApplyGaussianBlur(src, 15);
    ID3D11Texture2D* texture_blur = RenderUtils::LoadTextureFromMat(dst, Render::Data::Device, Render::Data::DeviceContext);
    ID3D11ShaderResourceView* texture_srv = nullptr;
    D3D11_SHADER_RESOURCE_VIEW_DESC srvDesc = {};
    srvDesc.Format = DXGI_FORMAT_B8G8R8A8_UNORM;
    srvDesc.ViewDimension = D3D11_SRV_DIMENSION_TEXTURE2D;
    srvDesc.Texture2D.MipLevels = 1;
    srvDesc.Texture2D.MostDetailedMip = 0;
    Render::Data::Device->CreateShaderResourceView(texture_blur, &srvDesc, &texture_srv);
    ImGui::Image(texture_srv, ImVec2(dst.cols, dst.rows));
}
