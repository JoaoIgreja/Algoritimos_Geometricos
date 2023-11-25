#include <iostream>

typedef struct
{
    int x;
    int y;
} ponto;

typedef struct
{
    ponto a;
    ponto b;
} segmento;

// Função para calcular a área de um triângulo dados tres pontos
float calcularAreaTriangulo(ponto p1, ponto p2, ponto p3)
{
    return 0.5 * abs((p1.x * (p2.y - p3.y) + p2.x * (p3.y - p1.y) + p3.x * (p1.y - p2.y)));
}

// Função para calcular as coordenadas baricentricas
void calcularCoordenadasBaricentricas(ponto p, ponto p1, ponto p2, ponto p3)
{
    // Calcular a área total do triângulo
    float areaTotal = calcularAreaTriangulo(p1, p2, p3);

    // Calcular as áreas dos subtriângulos
    float area1 = calcularAreaTriangulo(p, p2, p3);
    float area2 = calcularAreaTriangulo(p1, p, p3);
    float area3 = calcularAreaTriangulo(p1, p2, p);

    // Calcular as coordenadas baricentricas
    float lambda1 = area1 / areaTotal;
    float lambda2 = area2 / areaTotal;
    float lambda3 = area3 / areaTotal;

    // Imprimir as coordenadas baricentricas
    std::cout << "Coordenadas baricentricas: lambda1 = " << lambda1 << ", lambda2 = " << lambda2 << ", lambda3 = " << lambda3 << std::endl;
}

int main()
{
    ponto p = {3, 2};
    ponto p1 = {1, 2};
    ponto p2 = {4, 4};
    ponto p3 = {4, 1};

    // Calcular e imprimir as coordenadas baricentricas
    calcularCoordenadasBaricentricas(p, p1, p2, p3);

    return 0;
}
