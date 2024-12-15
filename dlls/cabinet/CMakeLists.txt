add_wine_dll(NAME cabinet
    IMPORTLIB
        cabinet
    IMPORTS
        ${ZLIB_PE_LIBS}
    EXTRAINCL
        ${ZLIB_PE_CFLAGS}
    SOURCES
        cabinet.rc
        cabinet_main.c
        fci.c
        fdi.c
)
