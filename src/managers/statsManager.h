//
// Created by Artur on 25.09.2025.
//

#ifndef NOTSIMPLEGAME_STATSMANAGER_H
#define NOTSIMPLEGAME_STATSMANAGER_H



class statsManager {
public:
    statsManager() = default;
    ~statsManager() = default;
    static statsManager& getInstance() {
        static statsManager instance;
        return instance;
    }





};


#endif //NOTSIMPLEGAME_STATSMANAGER_H