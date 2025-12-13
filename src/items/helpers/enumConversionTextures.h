#ifndef NOTSIMPLEGAME_ENUMCONVERSIONTEXTURES_H
#define NOTSIMPLEGAME_ENUMCONVERSIONTEXTURES_H
#include <map>
#include <string>


enum class Rarity;

class enumConversionTextures {
    enumConversionTextures() {
        // Initialize everything automatically
        RarityToFilepath();
    }
    std::map<Rarity, std::string> RarityTexturePaths;
    const std::string ASSETS_BASE = "assets/";
public:
    // Singletone
    static enumConversionTextures& getInstance() {
        static enumConversionTextures instance;
        return instance;
    }
    void RarityToFilepath();

    std::map<Rarity, std::string> GetRarityTexturePaths() {
        return RarityTexturePaths;
    }
};


#endif //NOTSIMPLEGAME_ENUMCONVERSIONTEXTURES_H