#ifndef RECENZIE_H
#define RECENZIE_H

#include <string>
#include <memory>
#include <iostream>
#include <utility>
#include "ObiectMuzical.h"
#include "Exceptii.h"

template <typename T>
class Recenzie : public ObiectMuzical {
private:
    std::string comentariu;
    T nota;

public:
    Recenzie(const std::string& comentariu, T nota);
    Recenzie(const Recenzie<T>& other);
    Recenzie<T>& operator=(Recenzie<T> other);

    T getNota() const;
    void afiseazaDetalii() const override;
    std::shared_ptr<ObiectMuzical> clone() const override;
    void actualizeazaNota(T nouaNota);

    friend void swap(Recenzie<T>& prima, Recenzie<T>& aDoua) {
        std::swap(prima.comentariu, aDoua.comentariu);
        std::swap(prima.nota, aDoua.nota);
    }

    std::string getTipObiect() const override;
};

#include "Recenzie.tpp"

#endif
