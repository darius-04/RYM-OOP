#include "Topuri.h"
#include <iostream>
#include <algorithm>
#include <map>
#include <limits>
#include <iomanip>
#include "SortStrategy.h"

void Topuri::topMelodii(const std::vector<std::shared_ptr<ObiectMuzical>>& colectie, int numar, std::shared_ptr<SortStrategy<Melodie>> sortStrategy)
{
    std::vector<std::shared_ptr<Melodie>> toateMelodiile;
    for (const auto& obiect : colectie)
    {
        if (auto artist = std::dynamic_pointer_cast<Artist>(obiect))
        {
            for (const auto& album : artist->getAlbume())
            {
                for (const auto& melodie : album->getMelodii())
                {
                    toateMelodiile.push_back(melodie);
                }
            }
        }
    }

    if (toateMelodiile.empty())
    {
        std::cout << "Nu exista melodii pentru a crea un top.\n";
        return;
    }

    if (sortStrategy)
    {
        sortStrategy->sort(toateMelodiile);
        std::cout << "Top " << numar << " Melodii (sortate conform strategiei):\n";
    }
    else
    {
        std::sort(toateMelodiile.begin(), toateMelodiile.end(), [](const std::shared_ptr<Melodie>& a, const std::shared_ptr<Melodie>& b)
        {
            return a->getNotaMedie() > b->getNotaMedie();
        });
        std::cout << "Top " << numar << " Melodii (sortate dupa nota medie implicit):\n";
    }

    for (int i = 0; i < std::min((int)toateMelodiile.size(), numar); ++i)
    {
        std::cout << i + 1 << ". " << toateMelodiile[i]->getNume()
                  << " (Nota: " << std::fixed << std::setprecision(2) << toateMelodiile[i]->getNotaMedie() << ")\n";
    }
}

void Topuri::topAlbume(const std::vector<std::shared_ptr<ObiectMuzical>>& colectie, int numar, std::shared_ptr<SortStrategy<Album>> sortStrategy)
{
    std::vector<std::shared_ptr<Album>> toateAlbumele;
    for (const auto& obiect : colectie)
    {
        if (auto artist = std::dynamic_pointer_cast<Artist>(obiect))
        {
            for (const auto& album : artist->getAlbume())
            {
                toateAlbumele.push_back(album);
            }
        }
    }

    if (toateAlbumele.empty())
    {
        std::cout << "Nu exista albume pentru a crea un top.\n";
        return;
    }

    if (sortStrategy)
    {
        std::cout << "Top " << numar << " Albume (sortate conform strategiei):\n";
        sortStrategy->sort(toateAlbumele);
    }
    else
    {
        std::cout << "Top " << numar << " Albume (sortate dupa nota medie implicit):\n";
        std::sort(toateAlbumele.begin(), toateAlbumele.end(), [](const std::shared_ptr<Album>& a, const std::shared_ptr<Album>& b)
        {
            return a->getNotaMedieAlbum() > b->getNotaMedieAlbum();
        });
    }

    for (int i = 0; i < std::min((int)toateAlbumele.size(), numar); ++i)
    {
        std::cout << i + 1 << ". " << toateAlbumele[i]->getTitlu();
        std::cout << " (Melodii: " << toateAlbumele[i]->getMelodii().size() << ")";
        std::cout << " (Nota: " << std::fixed << std::setprecision(2) << toateAlbumele[i]->getNotaMedieAlbum() << ")\n";
    }
}

void Topuri::topArtisti(const std::vector<std::shared_ptr<ObiectMuzical>>& colectie, int numar,
                        std::shared_ptr<SortStrategy<Artist>> sortStrategy)
{
    std::vector<std::shared_ptr<Artist>> totiArtistii;
    for (const auto& obiect : colectie)
    {
        if (auto artist = std::dynamic_pointer_cast<Artist>(obiect))
        {
            totiArtistii.push_back(artist);
        }
    }

    if (totiArtistii.empty())
    {
        std::cout << "Nu exista artisti pentru a crea un top.\n";
        return;
    }

    if (sortStrategy)
    {
        sortStrategy->sort(totiArtistii);
        std::cout << "Top " << numar << " Artisti (sortati conform strategiei):\n";
    }
    else
    {
        std::sort(totiArtistii.begin(), totiArtistii.end(), [](const std::shared_ptr<Artist>& a, const std::shared_ptr<Artist>& b)
        {
            return a->getNotaMedieArtist() > b->getNotaMedieArtist();
        });
        std::cout << "Top " << numar << " Artisti (sortati dupa nota medie implicit):\n";
    }

    for (int i = 0; i < std::min((int)totiArtistii.size(), numar); ++i)
    {
        std::cout << i + 1 << ". " << totiArtistii[i]->getNume()
                  << " (Nota: " << std::fixed << std::setprecision(2) << totiArtistii[i]->getNotaMedieArtist() << ")\n";
    }
}

void Topuri::topAlbumeDinAn(const std::vector<std::shared_ptr<ObiectMuzical>>& colectie, int an)
{
    std::vector<std::shared_ptr<Album>> albumeDinAn;
    for (const auto& obiect : colectie)
    {
        if (auto artist = std::dynamic_pointer_cast<Artist>(obiect))
        {
            for (const auto& album : artist->getAlbume())
            {
                if (album->getAnLansare() == an)
                {
                    albumeDinAn.push_back(album);
                }
            }
        }
    }

    if (albumeDinAn.empty())
    {
        std::cout << "Nu exista albume lansate in anul " << an << ".\n";
        return;
    }

    std::sort(albumeDinAn.begin(), albumeDinAn.end(), [](const std::shared_ptr<Album>& a, const std::shared_ptr<Album>& b)
    {
        return a->getNotaMedieAlbum() > b->getNotaMedieAlbum();
    });

    std::cout << "\n--- Top Albume din " << an << " ---\n";
    for (int i = 0; i < albumeDinAn.size(); ++i)
    {
        std::cout << i + 1 << ". " << albumeDinAn[i]->getTitlu()
                  << " (Melodii: " << albumeDinAn[i]->getMelodii().size() << ")" // Afiseaza si aici
                  << " (Nota: " << std::fixed << std::setprecision(2) << albumeDinAn[i]->getNotaMedieAlbum() << ")\n";
    }
}
