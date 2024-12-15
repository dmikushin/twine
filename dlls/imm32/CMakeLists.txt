add_wine_dll(NAME imm32
    IMPORTLIB
        imm32
    IMPORTS
        user32
        gdi32
        advapi32
        kernelbase
        win32u
    DELAYIMPORTS
        ole32
    SOURCES
        ime.c
        imm.c
        version.rc
)
