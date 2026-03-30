#ifndef ARTIST_H
#define ARTIST_H

#include <string>
#include <vector>
#include <memory>
#include "Album.h"
#include "ObiectMuzical.h"

template <typename T> class SortStrategy;

class Artist : public ObiectMuzical {
private:
    std::string nume;
    std::vector<std::shared_ptr<Album>> albume;
    std::shared_ptr<SortStrategy<Album>> algoritmSortare;

public:
    Artist(const std::string& nume);
    void adaugaAlbum(std::shared_ptr<Album> album);
    void afiseazaDetalii() const override;
    std::shared_ptr<ObiectMuzical> clone() const override;
    const std::vector<std::shared_ptr<Album>>& getAlbume() const;
    std::string getNume() const;
    double getNotaMedieArtist() const;
    void seteazaAlgoritmSortare(std::shared_ptr<SortStrategy<Album>> algoritm);
    void sorteazaAlbume();
    std::string getTipObiect() const override;
};

#endif
