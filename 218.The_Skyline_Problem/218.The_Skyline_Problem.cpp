class Solution {
public:

//Funçao q trabalha com os dados dos predios 
struct Evento {
    //variavel que representa um evento 
    int x;      // Coordenada horizontal 
    int altura; // Altura 
    bool comeco; // Indica se é início de um prédio

    // comparando dois objetos 
    bool operator<(const Evento& other) const {
        //se as cordenadas forem diferentes, retorna o menor 
        if (x != other.x)
            return x < other.x; 
        /// se for iguais, a priomirade e do ponto que inicia
        if (comeco != other.comeco)
            return comeco > other.comeco; 
        //desempate com a altura
        return comeco ? altura > other.altura : altura < other.altura;
    }
};

//calculando o horizonte 
vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
    vector<Evento> Eventos;

    // Criar Eventoos para cada prédio
    for (const auto& b : buildings) {
        int inicio = b[0], termina = b[1], altura = b[2];
        Eventos.push_back({inicio, altura, true});  // Início do prédio
        Eventos.push_back({termina, altura, false}); // Fim do prédio
    }

    // Ordenando os eventos
    sort(Eventos.begin(), Eventos.end());

    // Multiset para armazenar alturas ativas
    multiset<int> alturaPredios = {0};
    vector<vector<int>> result;
    int ultAltMax = 0;

    // Processar Eventoos
    for (const auto& Evento : Eventos) {
        ///se for um inicio de um predio
        if (Evento.comeco) {
           alturaPredios.insert(Evento.altura);
        } else {
            //se for o fim do predio 
            alturaPredios.erase(alturaPredios.find(Evento.altura));
        }

    
        int altMax = *alturaPredios.rbegin();

        //Adicionar um ponto ao horizonte
        if (altMax != ultAltMax) {
            result.push_back({Evento.x, altMax});
            ultAltMax = altMax;
        }
    }

    return result;
}


};




