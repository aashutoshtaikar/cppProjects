#include <iostream>

int main(int argc, char const *argv[])
{
    int i, sum = 0;
    printf("argc= %d\n", argc);

    if (argc > 1)
    {
        for (int i = 0; i < argc; i++)
        {
            printf("argv[%d] = %s\n", i, argv[i]);
            sum += atoi(argv[i]);
        }
        printf("total=%d\n",sum);
    }

    return 0;
}
