#include "FactoryObiectMuzical.h"

std::shared_ptr<ObiectMuzical> FactoryMelodie::creeazaObiectMuzical(const std::string& tipObiect, const std::string& numeMelodie, double) const {
    if (tipObiect == "Melodie") {
        return std::make_shared<Melodie>(numeMelodie);
    }
    return nullptr;
}

std::shared_ptr<ObiectMuzical> FactoryRecenzie::creeazaObiectMuzical(const std::string& tipObiect, const std::string& comentariu, double nota) const {
    if (tipObiect == "Recenzie") {
        return std::make_shared<Recenzie<double>>(comentariu, nota);
    }
    return nullptr;
}
