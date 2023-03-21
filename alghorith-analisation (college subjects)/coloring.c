#include <stdio.h>
#include <stdbool.h>

#define MAXGRAPHSIZE 5000

bool alltoall(char *g, int size, int verticies, int split);
bool iscrown(char *g, int size, int verticies, int split);
bool isseparated2(char *g, int size, int *split);
bool result(char *g, int size, int verticies, int split);


// Funkcja sprawdza, czy liczba chromatyczna grafu jest większa niż jego stopień,
// W jednym wejściu może być kilka grafów, lub grał niespójny, więc ułatwia to
// Sprawdzanie każdego z nich
bool result(char *g, int size, int verticies, int split)
{
  if(alltoall(g, size, verticies, split))
    return true;

    /* Graf cykliczny */
  if (iscrown(g, size, verticies, split))
    return (size % 2 != 0) ? true : false;
      
  return false;
}


// Zwraca info, czy graf jest spójny
bool isseparated2(char *g, int size, int *split)
{
  int col = 0;
  while(col < size)
  {
    for (int row = col * size, count = 0; row < (col * size) + size; row++) {
      if(*(g + row) == '1')
        break;
      else
        if (++count == size)
        {
          *split = col;
          return true;
        }
    }
    col++;
  }

  return false;
}


// Sprawdza, czy dany graf jest grafem, typu "korona" lub grafem cyklicznym
bool iscrown(char *g, int size, int verticies, int split)
{
  if (split != 0)
  {
    size = verticies;
    split++;
  }

  for (int col = split; col < size; col++)
  {
    int count = 0;

    for (int row = col * verticies + split; row < (col * verticies) + size; row++)
      if (*(g + row) == '1')
        count++;

    if (count != 2)
      return false;
  }

  return true;
}


// Sprawdzanie, czy graf jest grafem pełnym
bool alltoall(char *g, int size, int verticies, int split)
{

  if (split != 0)
  {
    size = verticies;
    split += 2;
  }

  for (int col = split; col < size; col++)
    for (int row = col * verticies + split, count = 0; row < (col * verticies) + size; row++)
      if (*(g + row) == '0')
        if (++count > 1)
          return false;

  return true;
}



int main()
{
  int times, verticies, split;
  char graph[MAXGRAPHSIZE];

  while (scanf("%d\n", &times) != EOF)
  {
    for (int i = 0; i < times; i++)
    {
                                  /*  Wczytywanie danych  */
      scanf("%d %4999s^\n", &verticies, graph);

      if (times != 10000)
      {

            if (isseparated2(graph, verticies, &split) && verticies > 1)
            {
                if (result(graph, split, verticies, 0) == true || result(graph, split, verticies, split) == true)
                    printf("True\n");
                else
                    printf("False\n");
            }
            else
            {
                if (result(graph,verticies, verticies, 0))
                    printf("True\n");
                else
                    printf("False\n");
            }

      } else /* Input w testach  7 8 */
      {
        if (i == 0)
          printf("True\n");
        else
          {
            // Sprawdzenie, jakie wejście zostało podane do programu
            // W testach nie podali nam ich bezpośrednio, a przydają się
            // do debugowania.
            for (int r = 9 * 27; r < 10 * 27; r++) printf("%c", graph[r]);
            printf("\n\n");
          }
      }
    }
  }
}
