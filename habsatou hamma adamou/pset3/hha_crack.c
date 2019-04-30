#define _XOPEN_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <cs50.h>
int main(int argc, string argv[])
{
    if (argc !=2)
    {
        printf("usage: crack <hash>\n");
        return 1;
    }
    const int letters_count =53;
    string letters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string hash = argv[1];
    char salt[3];
    memcpy(salt, hash, 2);
    salt[2]='\0';
    char key_people[5]="\0\0\0\0\0";
    for (int fourth =0; fourth < letters_count;fourth++)
    {
       for (int third =0; third < letters_count;third++)
       {
           for (int second =0; second < letters_count;second++)
           {
              for (int first =0; first < letters_count;first++)
              {
                key_people[0] = letters[first];
                key_people[1] = letters[second];
                key_people[2] = letters[third];
                key_people[3] = letters[fourth];
                if (strcmp(crypt(key_people, salt), hash) == 0)
                {
                    printf("%s\n", key_people);
                    return 0;
                }
              }
           }
       }
    }
    printf("passwrd couldn't be cracked");
    return 2;
}
