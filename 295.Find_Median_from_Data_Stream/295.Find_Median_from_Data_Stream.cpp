class MedianFinder {
private:
    // numeros maiores 
    std::priority_queue<int> Valormax;
    // ordem crescente
    std::priority_queue<int, std::vector<int>, std::greater<int>> crescente;

public:
  
    MedianFinder() {}

    // Adiciona um numero
    void addNum(int num) {
        // Adiciona o número à Valormax
        Valormax.push(num);

        // Garante que o maior elemento da Valormax vá para a crescente
        crescente.push(Valormax.top());
        Valormax.pop();

        // Garante que Valormax tenha pelo menos o mesmo tamanho que crescente
        if (Valormax.size() < crescente.size()) {
            Valormax.push(crescente.top());
            crescente.pop();
        }
    }

    // Retorna a mediana
    double findMedian() {
        // Se o número total de elementos for ímpar, o topo da Valormax é a mediana
        if (Valormax.size() > crescente.size()) {
            return Valormax.top();
        }
        // Se for par, a mediana é a média dos topos de ambas as heaps
        return (Valormax.top() + crescente.top()) / 2.0;
    }
};
