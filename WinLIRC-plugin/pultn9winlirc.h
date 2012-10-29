#pragma once

#if defined(PULTN9WINLIRC_EXPORTS)
#  define PULTN9WINLIRC_EXPORT __declspec(dllexport)
#else
#  define PULTN9WINLIRC_EXPORT __declspec(dllimport)
#endif

#ifdef __cplusplus
#define PULTN9WINLIRC_LINKAGE extern "C"
#else 
#define PULTN9WINLIRC_LINKAGE
#endif

#define PULTN9WINLIRC_API PULTN9WINLIRC_LINKAGE PULTN9WINLIRC_EXPORT

PULTN9WINLIRC_API int init(HANDLE exitEvent);
PULTN9WINLIRC_API void deinit();
PULTN9WINLIRC_API int hasGui();
PULTN9WINLIRC_API void loadSetupGui();
PULTN9WINLIRC_API int sendIR(struct ir_remote *remote, struct ir_ncode *code, int repeats);
PULTN9WINLIRC_API int decodeIR(struct ir_remote *remotes, char *out);
PULTN9WINLIRC_API struct hardware* getHardware();
