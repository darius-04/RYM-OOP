#ifndef ALBUM_H
#define ALBUM_H

#include <string>
#include <vector>
#include <memory>
#include "Melodie.h"
#include "ObiectMuzical.h"

class Album : public ObiectMuzical {
private:
    std::string titlu;
    int anLansare;
    std::vector<std::shared_ptr<Melodie>> melodii;

public:
    Album(const std::string& titlu, int anLansare);
    void adaugaMelodie(std::shared_ptr<Melodie> melodie);
    void afiseazaDetalii() const override;
    std::shared_ptr<ObiectMuzical> clone() const override;
    const std::vector<std::shared_ptr<Melodie>>& getMelodii() const;
    std::string getTitlu() const;
    int getAnLansare() const;
    double getNotaMedieAlbum() const;
    std::string getTipObiect() const override;
};

#endif
