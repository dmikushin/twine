add_wine_dll(NAME imagehlp
    EXTRADEFS
        _IMAGEHLP_SOURCE_
    IMPORTLIB
        imagehlp
    IMPORTS
        dbghelp
    SOURCES
        access.c
        imagehlp_main.c
        integrity.c
        modify.c
)
