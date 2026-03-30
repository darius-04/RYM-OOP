#include "Artist.h"
#include "Exceptii.h"
#include <iostream>
#include <algorithm>
#include <numeric>
#include <map>
#include <limits>
#include <iomanip>
#include "SortStrategy.h"

Artist::Artist(const std::string& nume) : nume(nume) {
    algoritmSortare = std::make_shared<SortareAlbumeDupaRatingDescendent>();
}

void Artist::adaugaAlbum(std::shared_ptr<Album> album) {
    albume.push_back(album);
}

void Artist::afiseazaDetalii() const {
    std::cout << "Artist: " << nume << " (Nota: " << std::fixed << std::setprecision(2) << getNotaMedieArtist() << ")";
}

double Artist::getNotaMedieArtist() const {
    if (albume.empty()) return 0.0;
    double suma = 0;
    for (const auto& a : albume) {
        suma += a->getNotaMedieAlbum();
    }
    return suma / albume.size();
}

const std::vector<std::shared_ptr<Album>>& Artist::getAlbume() const {
    return albume;
}

std::shared_ptr<ObiectMuzical> Artist::clone() const {
    return std::make_shared<Artist>(*this);
}

std::string Artist::getNume() const {
    return nume;
}

void Artist::seteazaAlgoritmSortare(std::shared_ptr<SortStrategy<Album>> algoritm) {
    this->algoritmSortare = algoritm;
}

void Artist::sorteazaAlbume() {
    if (algoritmSortare) {
        algoritmSortare->sort(albume);
    } else {
        std::cerr << "Eroare: Nu exista un algoritm de sortare setat.\n";
    }
}

std::string Artist::getTipObiect() const {
    return "Artist";
}
