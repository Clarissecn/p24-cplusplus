#include <iostream>
#include <stdexcept>
#include <stack>

// constante entière pour la taille de la pile
const int SIZE = 12;

// on définit un type de donnée (une classe) pour gérer une pile d'entier de taille 12 (SIZE)
class IntStack
{
private:
    // vos attributs pour représenter la pile d'entier
    // dans cette version toutes les piles sont de taille SIZE
    // votre code ici
    int tab[SIZE];
    int elem = 0;

public:
    void push(int e)
    {
        // cette fonction ajoute l'entier e dans la pile
        // votre code ici
        if (is_full() == false) { 
            tab[elem] = e;
            elem = elem + 1;
        }
        else {
            exit(0);
        }

    }
    int get_top()
    {
        // cette fonction retourne le dernier entier empilé
        // votre code ici
        if (is_empty()) { exit(0);}
        else {return tab[elem - 1];}
    }
    int pop()
    {
        // cette fonction retourne le dernier entier empilé
        // et supprime cet entier de la pile
        // votre code ici
        if (is_empty()) {
            exit(0);
        }
        else {
            int a;
            a = tab[elem-1];
            elem = elem -1;
            return a;
        }
    }
    bool is_empty()
    {
        // cette fonction teste si la pile est vide
        // votre code ici
        if (elem ==0){
            return true;
        }
        else{ return false;}
    }
    bool is_full()
    {
        // cette fonction teste si la pile est pleine
        // il y a SIZE entiers dans la pile
        // votre code ici
        if (elem == SIZE){ 
            return true;
        }
        else {
            return false;}
    }
    void print()
    {
        // cette fonction affiche la pile, par exemple
        // [1 2 3 [ pour dire que 3 entiers sont dans la pile
        // le dernier empilé est 3
        // votre code ici
        std::cout<< '[';
        for (int i = 0; i < elem; i++){
            std::cout << tab[i] << ' ';
        }
        std::cout << ']';
    }

};

// 1. réaliser le code pour faire fonctionner cette pile d'entier de taille fixée à la compilation
// 2. quelles sont les méthodes qui ne modifient pas l'objet sur lequel elles sont appelées
//    faites en sorte qu'elles puissent être appelées sur un objet constant
// 3. faites la fonction qui permet d'afficher un objet de type IntStack directement avec <<<
//    std::cout << s1;
//    il faut redéfinir l'operator<< en appelant la méthode print

int main()
{
    IntStack s1;
    s1.print(); // affichera [[
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.print();                         // affichera [1 2 3 ]
    std::cout << s1.pop() << std::endl; // affichera 3
    s1.print();                         // affichera [1 2 ]
    return 0;
}
