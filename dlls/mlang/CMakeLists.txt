add_wine_dll(NAME mlang
    IMPORTLIB
        mlang
    IMPORTS
        uuid
        ole32
        gdi32
        advapi32
    DELAYIMPORTS
        oleaut32
    SOURCES
        mlang.c
        mlang.rc
        mlang_classes.idl
)
