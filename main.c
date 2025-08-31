#include <float.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Jeg har haft problemmer med at kører pogrammet herinde af nogle årsager,
 * men det skulle helst virke fint når man kører det i et andet program*/
typedef enum
{
    es = 1,
    knægt = 11,
    dronning,
    konge,
    joker
}kort_vaerdi;
typedef enum
{
    klør = 1,
    ruder,
    hjerte,
    spar,
    j
}kort_kuloer;

struct kort_t
{
    kort_kuloer kuloer;
    kort_vaerdi vaerdi;
};

int compare(const void* x, const void* y);
char* omskriv_kuloer(const struct kort_t kort);
char* omskriv_vaerdi(const struct kort_t kort);
void shuffle(int array[], int length);

int main()
{
struct kort_t daek[] = {
    {j, joker},
    {j, joker},
    {j, joker},
    {spar,es},
    {spar, 2},
    {spar, 3},
    {spar, 4},
    {spar, 5},
    {spar, 6},
    {spar, 7},
    {spar, 8},
    {spar, 9},
    {spar,10},
    {spar, knægt},
    {spar, dronning},
    {spar, konge},
    {klør,es},
    {klør, 2},
    {klør, 3},
    {klør, 4},
    {klør, 5},
    {klør, 6},
    {klør, 7},
    {klør, 8},
    {klør, 9},
    {klør,10},
    {klør, knægt},
    {klør, dronning},
    {klør, konge},
    {ruder,es},
    {hjerte,es},
    {hjerte, 2},
    {hjerte, 3},
    {hjerte, 4},
    {hjerte, 5},
    {hjerte, 6},
    {hjerte, 7},
    {hjerte, 8},
    {hjerte, 9},
    {hjerte,10},
    {hjerte, knægt},
    {hjerte, dronning},
    {hjerte, konge},
    {ruder, 2},
    {ruder, 3},
    {ruder, 4},
    {ruder, 5},
    {ruder, 6},
    {ruder, 7},
    {ruder, 8},
    {ruder, 9},
    {ruder,10},
    {ruder, knægt},
    {ruder, dronning},
    {ruder, konge},


};
    int length = sizeof(daek)/sizeof(struct kort_t);
    //Bland funktion
   bland(daek, length);

    for(int i = 0; i < length; i++)
        printf("Card[%d]: %s %s \n", i + 1, omskriv_kuloer(daek[i]), omskriv_vaerdi(daek[i]));

    printf("\n \n");

    //sorterings funktion
    qsort(daek, sizeof(daek)/sizeof(struct kort_t), sizeof(struct kort_t), compare);

        for(int i = 0; i < length; i++)
            printf("Card[%d]: %s %s \n", i + 1, omskriv_kuloer(daek[i]), omskriv_vaerdi(daek[i]));
            printf("\n \n");

return 0;
}

int compare(const void* x, const void* y)
{
    struct kort_t korta = *(struct kort_t*)x;
    struct kort_t kortb = *(struct kort_t*)y;


    if (korta.kuloer > kortb.kuloer)
    {
        return 1;
    }
    if (korta.kuloer < kortb.kuloer)
    {
        return -1;
    }
    if (korta.vaerdi > kortb.vaerdi)
    {
        return 1;
    }
    if (korta.vaerdi < kortb.vaerdi)
    {
        return -1;
    }
    if (korta.vaerdi == kortb.vaerdi)
    {
        return 0;
    }
    return 0;

}

char* omskriv_kuloer(const struct kort_t kort)
{
    switch(kort.kuloer)
    {
    case klør:
        return "Kloer";
    case ruder:
        return "Ruder";
    case hjerte:
        return "Hjerte";
    case spar:
        return "Spar";
    case j:
        return "J";
    default:
        return "Error!";
    }
}

char* omskriv_vaerdi(const struct kort_t kort)
{
    switch(kort.vaerdi)
    {
    case es:
        return "Es";
    case 2:
        return "2";
    case 3:
        return "3";
    case 4:
        return "4";
    case 5:
        return "5";
    case 6:
        return "6";
    case 7:
        return "7";
    case 8:
        return "8";
    case 9:
        return "9";
    case 10:
        return "10";
    case knægt:
        return "Knaegt";
    case dronning:
        return "Dronning";
    case konge:
        return "Konge";
    case joker:
        return "Joker";
    default:
        return "Error!";
    }
}

void bland(struct kort_t *dæk, int length)
{
    srand(time(NULL));

    for (int i = 0; i < length; i++)
    {
        int swap = rand() % length;
        struct kort_t temp = dæk[i];
        dæk[i] = dæk[swap];
        dæk[swap] = temp;
    }
}

