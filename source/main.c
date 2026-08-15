#include <3ds.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
    gfxInitDefault();

    consoleInit(GFX_TOP, NULL);
    consoleInit(GFX_BOTTOM, NULL);

    printf("\x1b[5;7HLuK DRIVER ACADEMY");
    printf("\x1b[7;5HCar Parking Multiplayer");
    printf("\x1b[9;6HVersion 0.1");

    printf("\x1b[5;3HLuK Driver Academy");
    printf("\x1b[7;2H[A] Voitures");
    printf("\x1b[9;2H[B] Moniteurs");
    printf("\x1b[11;2H[X] Formations");
    printf("\x1b[13;2H[Y] Informations");
    printf("\x1b[15;2H[START] Quitter");

    while (aptMainLoop())
    {
        hidScanInput();

        u32 kDown = hidKeysDown();

        if (kDown & KEY_START)
            break;

        if (kDown & KEY_A)
        {
            consoleClear();
            printf("VOITURES\n\n");
            printf("Les voitures de l'academie\n");
            printf("arriveront dans la prochaine version.\n");
        }

        if (kDown & KEY_B)
        {
            consoleClear();
            printf("MONITEURS\n\n");
            printf("L. Dufour\n");
            printf("France\n");
            printf("Boite automatique\n\n");

            printf("MrBread\n");
            printf("Malaysia\n");
            printf("Boite manuelle\n");
        }

        if (kDown & KEY_X)
        {
            consoleClear();
            printf("FORMATIONS\n\n");
            printf("Formations de pilotage\n");
            printf("et categories de course.");
        }

        if (kDown & KEY_Y)
        {
            consoleClear();
            printf("LUK DRIVER ACADEMY\n\n");
            printf("Academie internationale\n");
            printf("Car Parking Multiplayer");
        }
        
        gfxFlushBuffers();
        gfxSwapBuffers();
        gspWaitForVBlank();
    }

    gfxExit();
    return 0;
}

