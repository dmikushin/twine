add_wine_dll(NAME coml2
    EXTRADEFS
        WINOLE32API=
    IMPORTLIB
        coml2
    IMPORTS
        uuid
    SOURCES
        memlockbytes.c
        stg_prop.c
        storage32.c
)
