# ImGui, Gaussian Blur, OpenCV & DirectX11
![ImGuiGaussianBlur](https://github.com/3r4y/ImGuiGaussianBlur/blob/main/img/ImGuiGaussianBlur.jpg?raw=true)


![](https://img.shields.io/github/stars/3r4y/ImGuiGaussianBlur)
![](https://img.shields.io/github/forks/3r4y/ImGuiGaussianBlur)

Esta es una aplicación que combina ImGui para el renderizado de la GUI, OpenCV para el procesamiento de imágenes y DirectX11 para el renderizado gráfico. Este proyecto demuestra cómo utilizar estas librerías en conjunto para crear una aplicación sencilla que carga, procesa y muestra imágenes.

## tal vez lo añada más adelante 😬
* soporte para video
* soporte para gif


## 🛠 Características

* Gaussian Blur de ImGui con directx11 

## Instalar OpenCV para Linux

```
sudo apt-get install libopencv-dev
```

## Instalar OpenCV para Windows

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

## Para aplicar el Gaussian Blur

```cpp

    //con imagen GaussianBlur (ejemplo de https://github.com/JimmyHHua/opencv_tutorials/blob/master/python/code_022/opencv_022.py)
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

## Capturas de pantalla

![example](https://github.com/3r4y/ImGuiGaussianBlur/blob/main/img/example.png?raw=true)

## 💡 Créditos

* Base de ImGui por [ImGui-AppKit](https://github.com/SamuelTulach/ImGui-AppKit)
* Instalación de OpenCV por [OPENCV_INSTALL](https://www.ccoderun.ca/programming/darknet_faq/#opencv_and_cuda)
* GaussianBlur (solo python) por [GaussianBlur](https://github.com/JimmyHHua/opencv_tutorials/blob/master/python/code_022/opencv_022.py)
