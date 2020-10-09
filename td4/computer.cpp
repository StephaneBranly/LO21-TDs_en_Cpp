#include "computer.h"
#include <iostream>

namespace COMPUTER
{
void ExpressionManager::agrandissementCapacite()
{
    // Agrandir le tableau
    // => En allouer un plus grand
    // => recopier les adresses dans le nouveau tableau
    // => désallouer l'ancien tableau
    // => le nouveau tableau devient le tableau courant
    nbMax = (nbMax + 1) * 2;

    auto newTab = new Expression *[nbMax];
    for (size_t i = 0; i < nb; i++)
    {
        newTab[i] = exps[i];
    }
    auto old = exps;
    exps = newTab;
    delete[] old;
}

Expression &ExpressionManager::addExpression(int v)
{
    if (nb == nbMax)
        agrandissementCapacite();
    exps[nb++] = new Expression(v);
    return *exps[nb - 1];
}

void ExpressionManager::removeExpression(Expression &e)
{
    size_t i = 0;
    // retirer l'adresse &e du tableau
    while (i < nb && exps[i] != &e)
        i++;
    if (i == nb)
        throw ComputerException("Expression inexistante");

    delete exps[i]; // on désalloue l'objet expression pointé
    nb--;
    // suppression du pointer
    while (i < nb)
    {
        exps[i] = exps[i + 1];
        i++;
    }
}

ExpressionManager::~ExpressionManager()
{
    for (size_t i = 0; i < nb; i++)
        delete exps[i]; // désallocation d'un objet
    delete[] exps;      // désallocation d'un tableau de pointeurs
}

ExpressionManager::ExpressionManager(const ExpressionManager &m) : nbMax(m.nb), nb(m.nb), exps(new Expression *[m.nb])
{
    for (size_t i = 0; i < nb; i++)
        exps[i] = new Expression(*m.exps[i]); // utilisation du constructeur de recopie de Expression
};

ExpressionManager &ExpressionManager::operator=(const ExpressionManager &m)
{
    if (this != &m) // manager = manager ne s'auto détruira pas
    {
        this->~ExpressionManager();
        exps = new Expression *[m.nbMax];
        nbMax = m.nbMax;
        nb = m.nb;

        for (size_t i = 0; i < nb; i++)
            exps[i] = new Expression(*m.exps[i]);
    }
    return *this;
};

} // namespace COMPUTER