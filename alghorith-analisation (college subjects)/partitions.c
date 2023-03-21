// +-------------------------------------------------------------------------------------+
// |
// |                       Miłosz Skobejko
// |
// |                       To już chyba 4 podejście do tego problemu,
// |                       Piersze 3 były iteracyjne, natomist żadna z prób
// |                       nie była na tyle dobra, aby ją tu wrzucić
// |                       (Po prostu nie działały do końca)
// |
// |                       Ostatni algorytm iteracyjny na który wpadłem
// |                       działał całkowicie, ale mimo wielu godzin prób nie
// |                       byłem w stanie go "odwrócić", gdyż wyświetlał wyniki
// |                       od najmniej rozłożonych do najbardziej
// |
// |
// |
// |                       Rekurencyjnie w końcu działa
// |
// +------------------------------------------------------------------------------------+

#include <stdio.h>
#include <stdbool.h>

#define MIN 2         // <--  Określa najmiejszą partcję (można dać np 1, wtedy rozłoży 4 na 1 + 1 + 1 + 1)
#define PRIMES 31     // <--  Określa rozmiar tablicy liczb pierwszych

int parts[60];        // Tablica partycji

void printVector(int index);
void partiate(int curr_n, int k, int index);
bool allprimes(int index);

/*  Sprawdza, czy wszystkie elementy tablicy są liczbami pierwszymi  */
bool allprimes(int index)
{
  int primes[PRIMES] = {2, 3, 5, 7,    11,    13,    17,    19,    23,    29,    31,    37,    41,    43,    47, 53,    59,    61,    67,    71, 73,    79,    83,    89,    97,    101,    103,    107,    109,    113,    127};

  int count = 0;

  for (int i = 0; i < index; i++)
    for (int j = 0; j < PRIMES; j++)
      if (parts[i] == primes[j])
        count++;

  return (count != index) ? false : true;
}


/*  Wyświetla tablicę z partycjami (tylko liczby pierwsze) */
void printVector(int index)
{
  if (allprimes(index))
  {
    for (int i = 0; i < index - 1; i++)
      printf("%d+", parts[i]);
    printf("%d\n", parts[index - 1]);
  }
}


/*  Wywołuje siebie samą, aż zostaną same 1 w tablicy */
void partiate(int curr_n, int k, int index)
{

    if (curr_n != 0)
    {

      // jeśli index jest to
      // int i = (index == 0 ? k : MIN);
      int i = MIN;

      for (; i <= k; i++)
      {
        if (i <= curr_n)
        {
            parts[index] = i;
            partiate(curr_n - i, i, index + 1);
        }
      }
    }
    else printVector(index);
}




int main()
{
    int n, k, times;

    while (scanf("%d", &times) != EOF)
      {
        for (int i = 0; i < times; i++)
          {
            scanf("%d %d", &n, &k);

            //       n, k, index
            partiate(n, k, 0);
          }
      }

    return 0;
}
