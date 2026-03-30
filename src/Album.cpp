#include "Album.h"
#include <iostream>
#include <numeric>
#include <iomanip>

Album::Album(const std::string& titlu, int anLansare) : titlu(titlu), anLansare(anLansare) {}

void Album::adaugaMelodie(std::shared_ptr<Melodie> melodie) {
    melodii.push_back(melodie);
}

void Album::afiseazaDetalii() const {
    std::cout << "Album: " << titlu << " (" << anLansare << ")" << " (Nota: " << std::fixed << std::setprecision(2) << getNotaMedieAlbum() << ")";
}

const std::vector<std::shared_ptr<Melodie>>& Album::getMelodii() const {
    return melodii;
}

std::shared_ptr<ObiectMuzical> Album::clone() const {
    return std::make_shared<Album>(*this);
}

std::string Album::getTitlu() const {
    return titlu;
}

int Album::getAnLansare() const {
    return anLansare;
}

double Album::getNotaMedieAlbum() const {
    if (melodii.empty()) return 0.0;
    double sumaNoteMelodii = 0;
    int numarMelodiiCuRecenzii = 0;

    for (const auto& melodie : melodii) {
        double notaMelodie = melodie->getNotaMedie();
        if (notaMelodie > 0) {
            sumaNoteMelodii += notaMelodie;
            numarMelodiiCuRecenzii++;
        }
    }

    if (numarMelodiiCuRecenzii == 0) return 0.0;
    return sumaNoteMelodii / numarMelodiiCuRecenzii;
}

std::string Album::getTipObiect() const {
    return "Album";
}
