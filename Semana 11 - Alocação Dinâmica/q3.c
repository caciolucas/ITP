#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct
{
    float x, y;
} Point;

typedef struct
{
    int numPoints;
    Point *points;
} Object;

Object *createTriangle(Point p1, Point p2, Point p3)
{
    Object *triangle = malloc(sizeof(Object));
    triangle->numPoints = 3;

    triangle->points = malloc(sizeof(Point[triangle->numPoints]));
    triangle->points[0] = p1;
    triangle->points[1] = p2;
    triangle->points[2] = p3;
    return triangle;
}
Object *createRect(Point topleft, float width, float height)
{
    Object *rect = malloc(sizeof(Object));
    rect->numPoints = 4;

    rect->points = malloc(sizeof(Point[rect->numPoints]));

    Point topright;
    Point botleft;
    Point botright;

    topright.y = topleft.y;
    topright.x = topleft.x + width;

    botleft.x = topleft.x;
    botleft.y = topleft.y - height;

    botright.x = topright.x;
    botright.y = botleft.y;

    rect->points[0] = topleft;
    rect->points[1] = topright;
    rect->points[2] = botright;
    rect->points[3] = botleft;
    return rect;
}
Object *createRegularFigure(Point center, int num, float distance)
{
    Object *fig = malloc(sizeof(Object));
    fig->numPoints = num;

    fig->points = malloc(sizeof(Point[fig->numPoints]));

    float angle = (2 * M_PI) / num;

    for (int i = 0; i < num; i++)
    {
        fig->points[i].x = center.x + distance * cos(i * angle); //CERTO
        fig->points[i].y = center.y + distance * sin(i * angle); //CERTO
        // fig->points[i].y = center.x + distance * sin(i * angle); //ERRADO
        // fig->points[i].x = center.y + distance * cos(i * angle); //ERRADO
    }
    return fig;
}

void printObject(Object *obj);
int main()
{
    int largura, altura;
    int distancia, lados;

    Point pontos[3];
    Object figura;

    int opcao;

    scanf("%d", &opcao);

    switch (opcao)
    {
    case 0:
        // puts("Triangulo");
        scanf("%f %f %f %f %f %f", &pontos[0].x, &pontos[0].y, &pontos[1].x, &pontos[1].y, &pontos[2].x, &pontos[2].y);
        figura = *createTriangle(pontos[0], pontos[1], pontos[2]);
        break;
    case 1:
        // puts("Retângulo");
        scanf("%f %f %d %d", &pontos[0].x, &pontos[0].y, &largura, &altura);
        figura = *createRect(pontos[0], largura, altura);
        break;
    case 2:
        // puts("Figura");
        // scanf("%f %f %d %d", &pontos[0].x, &pontos[0].y, &lados,&distancia);  // CERTO
        scanf("%f %f %d %d", &pontos[0].x, &pontos[0].y, &distancia, &lados); // ERRADO
        figura = *createRegularFigure(pontos[0], lados, distancia);
        break;
    }
    printObject(&figura);
    return 0;
}
void printObject(Object *obj)
{
    for (int i = 0; i < obj->numPoints; i++)
    {
        printf("(%.2f,%.2f)", obj->points[i].x, obj->points[i].y);
    }
    return;
}