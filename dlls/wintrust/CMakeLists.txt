add_wine_dll(NAME wintrust
    IMPORTLIB
        wintrust
    IMPORTS
        crypt32
        user32
        advapi32
    DELAYIMPORTS
        cryptui
        imagehlp
    SOURCES
        asn.c
        crypt.c
        register.c
        softpub.c
        version.rc
        wintrust_main.c
)
