#include "SortStrategy.h"
#include <algorithm>
#include <iostream>

void SortareAlbumeDupaAnAscendent::sort(std::vector<std::shared_ptr<Album>>& albume) const {
    std::sort(albume.begin(), albume.end(), [](const std::shared_ptr<Album>& a, const std::shared_ptr<Album>& b) {
        return a->getAnLansare() < b->getAnLansare();
    });
}

void SortareAlbumeDupaRatingDescendent::sort(std::vector<std::shared_ptr<Album>>& albume) const {
    std::sort(albume.begin(), albume.end(), [](const std::shared_ptr<Album>& a, const std::shared_ptr<Album>& b) {
        return a->getNotaMedieAlbum() > b->getNotaMedieAlbum();
    });
}

void SortareAlbumeAlfabeticaDupaTitlu::sort(std::vector<std::shared_ptr<Album>>& albume) const {
    std::sort(albume.begin(), albume.end(), [](const std::shared_ptr<Album>& a, const std::shared_ptr<Album>& b) {
        return a->getTitlu() < b->getTitlu();
    });
}

void SortareAlbumeDupaNumarMelodiiDescendent::sort(std::vector<std::shared_ptr<Album>>& albume) const {
    std::sort(albume.begin(), albume.end(), [](const std::shared_ptr<Album>& a, const std::shared_ptr<Album>& b) {
        return a->getMelodii().size() > b->getMelodii().size();
    });
}

void SortareMelodiiDupaNotaDescendent::sort(std::vector<std::shared_ptr<Melodie>>& melodii) const {
    std::sort(melodii.begin(), melodii.end(), [](const std::shared_ptr<Melodie>& a, const std::shared_ptr<Melodie>& b) {
        return a->getNotaMedie() > b->getNotaMedie();
    });
}

void SortareMelodiiAlfabeticaDupaNume::sort(std::vector<std::shared_ptr<Melodie>>& melodii) const {
    std::sort(melodii.begin(), melodii.end(), [](const std::shared_ptr<Melodie>& a, const std::shared_ptr<Melodie>& b) {
        return a->getNume() < b->getNume();
    });
}

void SortareArtistiDupaNumeAscendent::sort(std::vector<std::shared_ptr<Artist>>& artisti) const {
    std::sort(artisti.begin(), artisti.end(), [](const std::shared_ptr<Artist>& a, const std::shared_ptr<Artist>& b) {
        return a->getNume() < b->getNume();
    });
}

void SortareArtistiDupaNotaMedieDescendent::sort(std::vector<std::shared_ptr<Artist>>& artisti) const {
    std::sort(artisti.begin(), artisti.end(), [](const std::shared_ptr<Artist>& a, const std::shared_ptr<Artist>& b) {
        return a->getNotaMedieArtist() > b->getNotaMedieArtist();
    });
}
