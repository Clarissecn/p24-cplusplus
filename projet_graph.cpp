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
        void dfs_voisins(const std::string& sommet, std::unordered_map<std::string, bool>& visit){
            visit[sommet] = true;
            std::cout << sommet << " ";
            for (const auto& [voisins, poids] : my_graph.at(sommet)) {
                if (!visit[voisins]) {
                    dfs_voisins(voisins, visit);
                }
            }
        }
        void dfs(){
            std::unordered_map<std::string, bool> visit; //on créé un dictionnaire "visited" qui a pour clé les sommets et valeur true si déjà visité, sinon faux     
            for (const auto& [sommet, _] : my_graph) {
                visit[sommet] = false;
                } //on initialise tous les sommets comme non visités
                    
            for (const auto& [sommet, _] : my_graph) {
                if (!visit[sommet]) {
                    dfs_voisins(sommet, visit);
                    std::cout << std::endl;
                }
            }
        }

        // Parcours DFS itératif
        void dfs_iteratif() {
            std::unordered_map<std::string, bool> visit;
            for (const auto& [sommet, _] : my_graph) {
                visit[sommet] = false;
            }

            for (const auto& [sommet, _] : my_graph) {
                if (!visit[sommet]) {
                    std::stack<std::string> pile;
                    pile.push(sommet);

                    while (!pile.empty()) {
                        std::string current = pile.top();
                        pile.pop();

                        if (!visit[current]) {
                            visit[current] = true;
                            std::cout << current << " ";

                            for (const auto& [voisin, poids] : my_graph[current]) {
                                std::cout << "-> (" << voisin << ", " << poids << ") ";
                                if (!visit[voisin]) {
                                    pile.push(voisin);
                                }
                            }
                        }
                    }
                    std::cout << std::endl;
                }
            }
        }
        // Parcours BFS (largeur)
        void bfs() {
            std::unordered_map<std::string, bool> visit;
            for (const auto& [sommet, _] : my_graph) {
                visit[sommet] = false;
            }

            for (const auto& [sommet, _] : my_graph) {
                if (!visit[sommet]) {
                    std::queue<std::string> file;
                    file.push(sommet);

                    while (!file.empty()) {
                        std::string current = file.front();
                        file.pop();

                        if (!visit[current]) {
                            visit[current] = true;
                            std::cout << current << " ";

                            for (const auto& [voisin, poids] : my_graph[current]) {
                                std::cout << "-> (" << voisin << ", " << poids << ") ";
                                if (!visit[voisin]) {
                                    file.push(voisin);
                                }
                            }
                        }
                    }
                    std::cout << std::endl;
                }
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

    std::cout << "Graph adjacency list:\n";
    g.printGraph();

    std::cout << "\nDFS Recursive:\n";
    g.dfs();

    std::cout << "\nDFS Iterative:\n";
    g.dfs_iteratif();

    std::cout << "\nBFS:\n";
    g.bfs();

    return 0;
}