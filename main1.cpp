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

int produtoVetorial(ponto a, ponto b, ponto p)
{
    return (b.x - a.x) * (p.y - a.y) - (p.x - a.x) * (b.y - a.y);
}

int lado(ponto a, ponto b, ponto p)
{
    int prodVetorial = produtoVetorial(a, b, p);

    if (prodVetorial > 0)
    {
        return -1; // p esta a direita de ab
    }
    else if (prodVetorial < 0)
    {
        return 1; // p esta a esquerda de ab
    }
    else
    {
        return 0; // p esta alinhado com ab
    }
}

using namespace std;

int main()
{
    ponto a, b, p;

    cout << "Digite as coordenadas do ponto A (x y): ";
    cin >> a.x >> a.y;

    cout << "Digite as coordenadas do ponto B (x y): ";
    cin >> b.x >> b.y;

    cout << "Digite as coordenadas do ponto P (x y): ";
    cin >> p.x >> p.y;

    int resultado = lado(a, b, p);

    cout << "Resultado para P: " << resultado << endl;

    return 0;
}
