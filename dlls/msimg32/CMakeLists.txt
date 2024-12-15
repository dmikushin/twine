add_wine_dll(NAME msimg32
    IMPORTLIB
        msimg32
    IMPORTS
        gdi32
    SOURCES
        msimg32_main.c
)
