#include <stdio.h>
#include<stdbool.h>

#define MAXTREESIZE 80000
#define NOEXIST -1

int isitleave(char *tree, int row, int size);
int root(char *tree, int row, int verticies);
int countedges(char *tree, int row, int size);
bool isbananatree(char *tree, int root, int verticies, long int *bananas);


                    /* Znajdowanie korzenia */
int root(char *tree, int row, int verticies)
{
    
    if (row >= verticies) return NOEXIST;
    
    int branch = isitleave(tree, row, verticies);

    if (branch != NOEXIST)
    {
      for (int i = branch * verticies, index = 0; i < (branch * verticies) + verticies; i++, index++)
        if (tree[i] == '1')
          if (isitleave(tree, index, verticies) == NOEXIST)
            return index;
      return NOEXIST;
    }

    return root(tree, row + 1, verticies);
}


              /* sprawdzanie stopnia wierzchołka  */
int countedges(char *tree, int row, int size)
{
  int count = 0;

  for (int i = row * size; i < (row * size) + size; i++)
    if (tree[i] == '1') count ++;

  return count;
}


            /* sprawdzanie, czy dany wierzchołek to liść  */
int isitleave(char *tree, int row, int size)
{
  // NOEXIST w tym kontekście służy jako oznaczenie, że sprawdzany wierzchołek nie jest liściem.
  // count liczy wierzchołki połączone ze sprawdzanym.
  int count = 0, index = NOEXIST;

  for (int i = row * size; i < (row * size) + size; i++)
  {
    if (tree[i] == '1')
    {
      index = i % size;
      count++;
      
      // skoro count mierzy liczbę krawędzi połączonych z danym wierzchołkiem, jeśli będzie większe niż 1
      // to znaczy, że wierzchołek nie jest liściem
      if (count > 1) return NOEXIST;
    }
  }
    
  return index;
}


              /* sprawdzanie, czy drzewo jest bananowe */
bool isbananatree(char *tree, int root, int verticies, long int *bananas)
{
  // Jeśli nie ma korzenia to albo ma n - 1 wierzchołków albo 2 dla verticies == 2
  if (root == NOEXIST)
  {
    if (verticies != 2)
      *bananas = verticies - 1;
    else
      *bananas = 2;

    return true;
  }

  
  int first = 0, count = 0;

  for(int i = root * verticies, f = 0; i < (root * verticies) + verticies; i++, f++)
  {
    if (tree[i] == '1')
    {
      int bananas_on_branch = countedges(tree, f, verticies) - 1; // odjęty wierzchołek, do którego podpięte są banany
        
      // Funkcja iteruje po każdej kiści w drzewie. funkcja countedges sprawdza stopień wierzchołka, który jest jednocześnie
      // ilością bananów na kiści - 1. każda kiść musi mieć tyle samo bananów, aby drzewo było bananowe, dlatego zapisuje
      // wynik pierwszego sprawdzenia do zmiennej first, a następnie porównuje z nią ilość bananów każdej kolejne kiści. Jeśli
      // l. bananów się różni to zwracane jest false
      if (count == 0) first = bananas_on_branch;
      if (bananas_on_branch != first) return false;

      *bananas += bananas_on_branch;
      count++;
    }
  }

  // Sprawdzanie czy wystąpiła sytuacja typu 2 korzenie, jeśli tak to drzewo nie jest bananowe
  if (*bananas + count + 1 != verticies) return false;
  return true;
}



int main()
{
  int times, verticies;
  char tree[MAXTREESIZE];

  while (scanf("%d\n", &times) != EOF)
  {
    for (int i = 0; i < times; i++)
    {
      long int bananas = 0;

                                  /*  Wczytywanie danych  */
      scanf("%d %79999s^\n", &verticies, tree);


              /* Znajdywanie korzenia i sprawdzanie, czy drzewo jest bananowe */
      if (isbananatree(tree, root(tree, 0, verticies), verticies, &bananas) == true)
        printf("%ld bananas :)\n", bananas);
      else
        printf("0 bananas :(\n");


    }
  }
}
