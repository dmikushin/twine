add_wine_dll(NAME iphlpapi
    IMPORTLIB
        iphlpapi
    IMPORTS
        advapi32
        dnsapi
        nsi
        uuid
        ws2_32
    SOURCES
        iphlpapi_main.c
        version.rc
)
