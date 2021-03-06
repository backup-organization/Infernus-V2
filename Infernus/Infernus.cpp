#include "Other/Utils.h"
#include "Client/ClientManager.h"

void Init(LPVOID lpParam) {
    Utils::hModule = (HMODULE)lpParam;
    Utils::DeletePath("Infernus/Output.txt");
    Utils::DebugLogOutput("Injected...");

    ClientManager::InitHooks();
    ClientManager::InitCommands();
    ClientManager::InitModules();
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved) {
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        CreateThread(0, 0, (LPTHREAD_START_ROUTINE)Init, hModule, 0, 0);
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}