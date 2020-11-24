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
typedef struct
{
    int num;
    int size;
    Object **objs;
} ObjectArray;

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
        // fig->points[i].x = center.x + distance * sin(i * angle); //CERTO
        // fig->points[i].y = center.y + distance * cos(i * angle); //CERTO
        fig->points[i].y = center.x + distance * sin(i * angle); //ERRADO
        fig->points[i].x = center.y + distance * cos(i * angle); //ERRADO
    }
    return fig;
}

ObjectArray *createObjectArray(int n)
{
    ObjectArray *array = malloc(sizeof(ObjectArray));
    array->size = n;
    array->num = 0;
    array->objs = malloc(n * sizeof(Object));
    return array;
}
void printObject(Object *obj);
void addObject(ObjectArray *array, Object *figura)
{
    if (array->size == array->num)
    {
        array->size *= 2;
        array->objs = realloc(array->objs, sizeof(Object[array->size]));
    }

    int index = array->num;
    array->objs[index] = figura;
    // printf("adicionada fig na pos %d\n",array->num);
    array->num++;
}
void destroyArray(ObjectArray *array)
{
    for (int i = 0; i < array->num; i++)
    {
        free(array->objs[i]->points);
        free(array->objs[i]);
    }
    free(array);
    return;
}
int main()
{
    int largura, altura;
    int distancia, lados;

    Point pontos[3];
    Object *figura;
    ObjectArray *figuras = createObjectArray(10);
    int n;
    scanf("%d", &n);

    int opcao;
    for (int i = 0; i < n; i++)
    {

        scanf("%d", &opcao);

        switch (opcao)
        {
        case 0:
            // puts("Triangulo");
            scanf("%f %f %f %f %f %f", &pontos[0].x, &pontos[0].y, &pontos[1].x, &pontos[1].y, &pontos[2].x, &pontos[2].y);
            figura = createTriangle(pontos[0], pontos[1], pontos[2]);
            break;
        case 1:
            // puts("Retângulo");
            scanf("%f %f %d %d", &pontos[0].x, &pontos[0].y, &largura, &altura);
            figura = createRect(pontos[0], largura, altura);
            break;
        case 2:
            // puts("Figura");
            // scanf("%f %f %d %d", &pontos[0].x, &pontos[0].y, &lados,&distancia);  // CERTO
            scanf("%f %f %d %d", &pontos[0].x, &pontos[0].y, &distancia, &lados); // ERRADO
            figura = createRegularFigure(pontos[0], lados, distancia);
            break;
        }
        addObject(figuras, figura);
        // printObject(figuras->objs[figuras->num-1]);
    }
    // printf("Figura adicionadas\n");
    for (int i = 0; i < figuras->num; i++)
    {
        printObject(figuras->objs[i]);
    }
    destroyArray(figuras);
    return 0;
}
void printObject(Object *obj)
{
    for (int i = 0; i < obj->numPoints; i++)
    {
        printf("(%.2f,%.2f)", obj->points[i].x, obj->points[i].y);
    }
    puts("");
    return;
}