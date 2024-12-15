add_wine_dll(NAME wevtsvc
    IMPORTS
        rpcrt4
        advapi32
    SOURCES
        wevtsvc.c
)
