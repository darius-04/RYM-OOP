#ifndef TOPURI_H
#define TOPURI_H
#include <vector>
#include <memory>
#include <string>
#include "ObiectMuzical.h"
#include "Artist.h"
#include "Album.h"
#include "Melodie.h"

template <typename T> class SortStrategy;

class Topuri {
public:
    static void topMelodii(const std::vector<std::shared_ptr<ObiectMuzical>>& colectie, int numar, std::shared_ptr<SortStrategy<Melodie>> sortStrategy = nullptr);
    static void topAlbume(const std::vector<std::shared_ptr<ObiectMuzical>>& colectie, int numar, std::shared_ptr<SortStrategy<Album>> sortStrategy = nullptr);
    static void topArtisti(const std::vector<std::shared_ptr<ObiectMuzical>>& colectie, int numar, std::shared_ptr<SortStrategy<Artist>> sortStrategy = nullptr);
    static void topAlbumeDinAn(const std::vector<std::shared_ptr<ObiectMuzical>>& colectie, int an);

private:
    Topuri() = delete;
};

#endif
