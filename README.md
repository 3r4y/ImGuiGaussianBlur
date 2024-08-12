# ImGui, Gaussian Blur, OpenCV & DirectX11
![ImGuiGaussianBlur](https://github.com/3r4y/ImGuiGaussianBlur/blob/main/img/ImGuiGaussianBlur.jpg?raw=true)


![](https://img.shields.io/github/stars/3r4y/ImGuiGaussianBlur)
![](https://img.shields.io/github/forks/3r4y/ImGuiGaussianBlur)

This is an application that combines ImGui for GUI rendering, OpenCV for image processing, and DirectX11 for graphics rendering. This project demonstrates how to use these libraries together to create a simple application that loads, processes, and displays images.

## maybe i will add it later 😬
* video support
* gif support


## 🛠 Features

* ImGui Gaussian Blur with directx11 

## Install OpenCV for Linux

```
sudo apt-get install libopencv-dev
```

## Install OpenCV for Windows

```
mkdir c:\src
cd c:\src
git clone https://github.com/microsoft/vcpkg
cd vcpkg
bootstrap-vcpkg.bat
.\vcpkg.exe integrate install
.\vcpkg.exe integrate powershell
.\vcpkg.exe install opencv[contrib,core,dnn,freetype,jpeg,openmp,png,quirc,tiff,webp,world]:x64-windows
```

## For applying Gaussian Blur

```cpp

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
```

## Screenshots

![example](https://github.com/3r4y/ImGuiGaussianBlur/blob/main/img/example.png?raw=true)

## 💡 Credits

* ImGui Base by [ImGui-AppKit](https://github.com/SamuelTulach/ImGui-AppKit)
* OpenCV Install by [OPENCV_INSTALL](https://www.ccoderun.ca/programming/darknet_faq/#opencv_and_cuda)
* GaussianBlur (just python) by [GaussianBlur](https://github.com/JimmyHHua/opencv_tutorials/blob/master/python/code_022/opencv_022.py)
