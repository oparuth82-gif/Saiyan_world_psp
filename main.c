
#include <pspkernel.h>
#include <pspdebug.h>
#include <pspdisplay.h>

PSP_MODULE_INFO("Saiyan World PSP", 0, 1, 0);
PSP_MAIN_THREAD_ATTR(THREAD_ATTR_USER);

int main(void)
{
    pspDebugScreenInit();

    pspDebugScreenSetTextColor(0xFFFFFFFF);
    pspDebugScreenPrintf("SAIYAN WORLD PSP\n\n");

    pspDebugScreenPrintf("Welcome, Saiyan!\n\n");
    pspDebugScreenPrintf("World 1: Earth\n");
    pspDebugScreenPrintf("World 2: Planet Namek\n");
    pspDebugScreenPrintf("World 3: Planet Vegeta\n");
    pspDebugScreenPrintf("World 4: Other World\n\n");

    pspDebugScreenPrintf("Your adventure begins!");

    sceKernelSleepThread();
    return 0;
}
