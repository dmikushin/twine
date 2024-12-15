add_wine_dll(NAME advpack
    IMPORTLIB
        advpack
    IMPORTS
        ole32
        setupapi
        version
        advapi32
    SOURCES
        advpack.c
        files.c
        install.c
        reg.c
)
