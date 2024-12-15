add_wine_dll(NAME mswsock
    IMPORTLIB
        mswsock
    IMPORTS
        ws2_32
    SOURCES
        mswsock.c
        version.rc
)
