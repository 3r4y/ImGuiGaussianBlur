#pragma once

class TextureLoader {
public:
    static bool LoadTextureFromFile(const std::string& file_name, ID3D11ShaderResourceView** out_srv, int* out_width, int* out_height);
    static bool LoadTextureFromMemory(const void* data, size_t data_size, ID3D11ShaderResourceView** out_srv, int* out_width, int* out_height);
};
