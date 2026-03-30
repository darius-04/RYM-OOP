#include "Recenzie.h" // Se include pe sine pentru a avea acces la declaratii.
                     // Poate parea circular, dar e ok pentru fisiere .tpp

template <typename T>
Recenzie<T>::Recenzie(const std::string& comentariu, T nota) : comentariu(comentariu), nota(nota) {
    if (nota < static_cast<T>(1.0) || nota > static_cast<T>(10.0)) {
        throw NotaInvalidaException();
    }
    idRecenzie = nota * 10;
}

template <typename T>
Recenzie<T>::Recenzie(const Recenzie<T>& other)
    : comentariu(other.comentariu), nota(other.nota), idRecenzie(other.idRecenzie) {}

template <typename T>
Recenzie<T>& Recenzie<T>::operator=(Recenzie<T> other) {
    swap(*this, other);
    return *this;
}

template <typename T>
T Recenzie<T>::getNota() const {
    return nota;
}

template <typename T>
void Recenzie<T>::afiseazaDetalii() const {
    std::cout << "Nota: " << nota << ", Comentariu: " << comentariu << ", ID Recenzie: " << idRecenzie << std::endl;
}

template <typename T>
std::shared_ptr<ObiectMuzical> Recenzie<T>::clone() const {
    return std::make_shared<Recenzie<T>>(*this);
}

template <typename T>
void Recenzie<T>::actualizeazaNota(T nouaNota) {
    if (nouaNota < static_cast<T>(1.0) || nouaNota > static_cast<T>(10.0)) {
        throw NotaInvalidaException();
    }
    this->nota = nouaNota;
    std::cout << "Nota actualizata la " << this->nota << " pentru recenzia cu ID " << this->idRecenzie << std::endl;
}

// Implementarea functiei friend swap.
// Aceasta trebuie sa fie template si ea.
template <typename T>
void swap(Recenzie<T>& prima, Recenzie<T>& aDoua) {
    std::swap(prima.comentariu, aDoua.comentariu);
    std::swap(prima.nota, aDoua.nota);
    std::swap(prima.idRecenzie, aDoua.idRecenzie);
}
