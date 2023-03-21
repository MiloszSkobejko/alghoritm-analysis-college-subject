#include <stdio.h>

// +------------------------------------------------------------------+
// |
// |                    Miłosz Skobejko 187224
// |
// +------------------------------------------------------------------+

// Zoptymalizowana silnia od razu z dzieleniem
unsigned long long int factorialop(int n, int d);



unsigned long long int factorialop(int n, int d)
{
  unsigned long long int result = 1;

  for (int i = 0; i < d; i++) result = (result * (n - i)) / (i + 1);
    
  return result;
}


int main()
{
  int n, d, times;

  while (scanf("%d", &times) != EOF)
  {

    for (int i = 0; i < times; i++)
      {
        /* Wczytywanie danych */
        scanf("%d %d", &n, &d);


        /* Wyświetlanie wyniku */
        if (d > n)
          printf("0\n");
        else
        {
          unsigned long long int result = 1;

          if (n == d)
            printf("%llu\n", result << (n - 1));
          else
          {
            /* Optymalizacja dla factorialopni */
            d = (d > n - d ? n - d : d);

            printf("%llu\n", (result << (n - 1)) * (factorialop(n, d)));
          }
        }
      }
  }

  return 0;
}
