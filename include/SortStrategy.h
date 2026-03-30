#ifndef SORT_STRATEGY_H
#define SORT_STRATEGY_H
#include <vector>
#include <memory>
#include "Album.h"
#include "Melodie.h"
#include "Artist.h"

template <typename T>
class SortStrategy {
public:
    virtual ~SortStrategy() = default;
    virtual void sort(std::vector<std::shared_ptr<T>>& obiecte) const = 0;
};

class SortareAlbumeDupaAnAscendent : public SortStrategy<Album> {
public:
    void sort(std::vector<std::shared_ptr<Album>>& albume) const override;
};

class SortareAlbumeDupaRatingDescendent : public SortStrategy<Album> {
public:
    void sort(std::vector<std::shared_ptr<Album>>& albume) const override;
};

class SortareAlbumeAlfabeticaDupaTitlu : public SortStrategy<Album> {
public:
    void sort(std::vector<std::shared_ptr<Album>>& albume) const override;
};

class SortareAlbumeDupaNumarMelodiiDescendent : public SortStrategy<Album> {
public:
    void sort(std::vector<std::shared_ptr<Album>>& albume) const override;
};

class SortareMelodiiDupaNotaDescendent : public SortStrategy<Melodie> {
public:
    void sort(std::vector<std::shared_ptr<Melodie>>& melodii) const override;
};

class SortareMelodiiAlfabeticaDupaNume : public SortStrategy<Melodie> {
public:
    void sort(std::vector<std::shared_ptr<Melodie>>& melodii) const override;
};

class SortareArtistiDupaNumeAscendent : public SortStrategy<Artist> {
public:
    void sort(std::vector<std::shared_ptr<Artist>>& artisti) const override;
};

class SortareArtistiDupaNotaMedieDescendent : public SortStrategy<Artist> {
public:
    void sort(std::vector<std::shared_ptr<Artist>>& artisti) const override;
};

#endif
