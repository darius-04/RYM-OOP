#ifndef MELODIE_H
#define MELODIE_H

#include <string>
#include <vector>
#include <memory>
#include "Recenzie.h"
#include "ObiectMuzical.h"

class Melodie : public ObiectMuzical {
private:
    std::string nume;
    std::vector<std::shared_ptr<Recenzie<double>>> recenzii;

public:
    Melodie(const std::string& nume);
    void adaugaRecenzie(std::shared_ptr<Recenzie<double>> recenzie);
    void afiseazaDetalii() const override;
    std::shared_ptr<ObiectMuzical> clone() const override;
    const std::vector<std::shared_ptr<Recenzie<double>>>& getRecenzii() const;
    std::string getNume() const;
    double getNotaMedie() const;
    std::string getTipObiect() const override;
};

#endif
