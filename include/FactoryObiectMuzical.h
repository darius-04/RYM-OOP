#ifndef FACTORY_OBIECT_MUZICAL_H
#define FACTORY_OBIECT_MUZICAL_H

#include <string>
#include <memory>
#include "ObiectMuzical.h"
#include "Artist.h"
#include "Album.h"
#include "Melodie.h"
#include "Recenzie.h"

class FactoryObiectMuzical {
public:
    virtual ~FactoryObiectMuzical() = default;
    virtual std::shared_ptr<ObiectMuzical> creeazaObiectMuzical(const std::string& tipObiect, const std::string& parametru1, double parametru2 = 0) const = 0;
};

class FactoryMelodie : public FactoryObiectMuzical {
public:
    std::shared_ptr<ObiectMuzical> creeazaObiectMuzical(const std::string& tipObiect, const std::string& numeMelodie, double = 0) const override;
};

class FactoryRecenzie : public FactoryObiectMuzical {
public:
    std::shared_ptr<ObiectMuzical> creeazaObiectMuzical(const std::string& tipObiect, const std::string& comentariu, double nota = 0) const override;
};

#endif
