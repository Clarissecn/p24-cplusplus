#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

class Graph {
    private:
        std::unordered_map<std::string, std::vector<std::pair<std::string, double> > > my_graph; 
        //la clé est un string car sommet = ex 'paris', la valeur de la clé est une paire d'un string (= sommet adjacent) et du poids de l'arrête
    public : 
        void addEdge(const std::string& sommet, const std::string& sommet_adj,const double poids) {
            my_graph[sommet].emplace_back(sommet_adj, poids); 
            //emplace_back permet d'ajouter le vecteur à la clé
        }
        void printGraph(){
            for (const auto& [sommet, valeur] : my_graph) { //auto permet de laisser le compileur choisir ce qu'il veut string, int...
                std::cout<< sommet << " = ";
                for (const auto& [sommet_adj, poids] : valeur) {
                    std::cout << '(' << sommet_adj << ',' << poids << ')';
                }
                std::cout<<std::endl;
            }
        }
};

int main() {
        Graph g;
        g.addEdge("Paris", "Lyon", 100);
        g.addEdge("Paris", "Marseille", 150);
        g.addEdge("Lyon", "Nice", 80);
        g.addEdge("Marseille", "Nice", 70);
        g.addEdge("Nice", "Paris", 200);
        g.printGraph();

        return 0;
}
