add_wine_dll(NAME version
    IMPORTLIB
        version
    IMPORTS
        kernelbase
    SOURCES
        version.c
        version.rc
)
