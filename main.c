
#include <pspkernel.h>
#include <pspdebug.h>
#include <pspctrl.h>

PSP_MODULE_INFO("Saiyan World PSP", 0, 1, 0);
PSP_MAIN_THREAD_ATTR(THREAD_ATTR_USER);

int main(void)
{
    int selected = 0;
    int entered = -1;
    unsigned int oldButtons = 0;
    SceCtrlData pad;

    const char *worlds[] = {
        "Earth",
        "Planet Namek",
        "Planet Vegeta",
        "Other World"
    };

    pspDebugScreenInit();
    sceCtrlSetSamplingCycle(0);
    sceCtrlSetSamplingMode(PSP_CTRL_MODE_DIGITAL);

    while (1)
    {
        sceCtrlReadBufferPositive(&pad, 1);

        unsigned int pressed =
            pad.Buttons & ~oldButtons;

        if (entered == -1)
        {
            if (pressed & PSP_CTRL_UP)
                selected = (selected + 3) % 4;

            if (pressed & PSP_CTRL_DOWN)
                selected = (selected + 1) % 4;

            if (pressed & PSP_CTRL_CROSS)
                entered = selected;
        }
        else
        {
            if (pressed & PSP_CTRL_CIRCLE)
                entered = -1;
        }

        pspDebugScreenClear();
        pspDebugScreenSetXY(8, 2);
        pspDebugScreenPrintf("SAIYAN WORLD PSP");

        if (entered == -1)
        {
            pspDebugScreenSetXY(7, 5);
            pspDebugScreenPrintf("SELECT YOUR WORLD");

            int i;
            for (i = 0; i < 4; i++)
            {
                pspDebugScreenSetXY(7, 8 + i * 2);

                if (i == selected)
                    pspDebugScreenPrintf("> %s <", worlds[i]);
                else
                    pspDebugScreenPrintf("  %s", worlds[i]);
            }

            pspDebugScreenSetXY(7, 19);
            pspDebugScreenPrintf("UP/DOWN: MOVE");
            pspDebugScreenSetXY(7, 20);
            pspDebugScreenPrintf("X: SELECT");
        }
        else
        {
            pspDebugScreenSetXY(7, 8);
            pspDebugScreenPrintf("WELCOME TO:");

            pspDebugScreenSetXY(7, 10);
            pspDebugScreenPrintf("%s", worlds[entered]);

            pspDebugScreenSetXY(7, 14);
            pspDebugScreenPrintf("YOUR ADVENTURE BEGINS!");

            pspDebugScreenSetXY(7, 19);
            pspDebugScreenPrintf("O: BACK");
        }

        oldButtons = pad.Buttons;
        sceKernelDelayThread(50000);
    }

    return 0;
}
