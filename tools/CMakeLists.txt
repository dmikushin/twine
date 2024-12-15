find_package(BISON REQUIRED)
find_package(FLEX REQUIRED)

file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/widl)
file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/wrc)

BISON_TARGET(widl_ParserY widl/parser.y ${CMAKE_CURRENT_BINARY_DIR}/widl/parser.tab.c
             DEFINES_FILE ${CMAKE_CURRENT_BINARY_DIR}/widl/parser.tab.h)
FLEX_TARGET(widl_ParserL widl/parser.l ${CMAKE_CURRENT_BINARY_DIR}/widl/parser.yy.c)
ADD_FLEX_BISON_DEPENDENCY(widl_ParserL widl_ParserY)

BISON_TARGET(wrc_PpyY wrc/ppy.y ${CMAKE_CURRENT_BINARY_DIR}/wrc/ppy.tab.c
             DEFINES_FILE ${CMAKE_CURRENT_BINARY_DIR}/wrc/ppy.tab.h)
FLEX_TARGET(wrc_PplL wrc/ppl.l ${CMAKE_CURRENT_BINARY_DIR}/wrc/ppl.yy.c)
ADD_FLEX_BISON_DEPENDENCY(wrc_PplL wrc_PpyY)

add_executable(widl
	widl/attribute.c
	widl/client.c
	widl/expr.c
	widl/hash.c
	widl/header.c
	widl/proxy.c
	widl/register.c
	widl/server.c
	widl/typegen.c
	widl/typelib.c
	widl/typetree.c
	widl/utils.c
	widl/widl.c
	wrc/wpp.c
	widl/write_msft.c
	widl/write_sltg.c
    ${BISON_widl_ParserY_OUTPUTS}
    ${FLEX_widl_ParserL_OUTPUTS}
    ${BISON_wrc_PpyY_OUTPUTS}
    ${FLEX_wrc_PplL_OUTPUTS})
target_include_directories(widl PRIVATE
	widl
	${CMAKE_CURRENT_BINARY_DIR}/widl
	wrc
	${CMAKE_CURRENT_BINARY_DIR}/wrc)
target_compile_options(widl PRIVATE ${CFLAGS_1})
target_compile_definitions(widl PRIVATE ${CDEFS_1}
	INCLUDEDIR=\"/src/wine/build/../install/include\"
	BINDIR=\"/src/wine/build/../install/bin\"
	LIBDIR=\"src/wine/build/../install/lib\")
set_target_properties(widl
    PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/widl")

function(add_idl)
    cmake_parse_arguments(
        ARG
        ""
        "OUTPUT"
        "FLAGS;SOURCE"
        ${ARGN}
    )
    add_custom_command(
        OUTPUT ${ARG_OUTPUT}
        COMMAND $<TARGET_FILE:widl> ${ARG_FLAGS} ${ARG_SOURCE} -o ${ARG_OUTPUT}
        DEPENDS ${ARG_SOURCE} widl
        COMMENT "Processing ${ARG_SOURCE}"
    )
endfunction()

BISON_TARGET(wrc_Parser wrc/parser.y ${CMAKE_CURRENT_BINARY_DIR}/wrc/parser.tab.c
             DEFINES_FILE ${CMAKE_CURRENT_BINARY_DIR}/wrc/parser.tab.h)
FLEX_TARGET(wrc_Lexer wrc/parser.l ${CMAKE_CURRENT_BINARY_DIR}/wrc/parser.yy.c)
ADD_FLEX_BISON_DEPENDENCY(wrc_Lexer wrc_Parser)

add_executable(wrc
	wrc/genres.c
	wrc/newstruc.c
	wrc/po.c
	wrc/utils.c
	wrc/wpp.c
	wrc/wrc.c
    ${FLEX_wrc_Lexer_OUTPUTS}
    ${BISON_wrc_Parser_OUTPUTS}
    ${BISON_wrc_PpyY_OUTPUTS}
    ${FLEX_wrc_PplL_OUTPUTS})
target_include_directories(wrc PRIVATE
	wrc
	${CMAKE_CURRENT_BINARY_DIR}/wrc)
target_compile_options(wrc PRIVATE ${CFLAGS_1})
target_compile_definitions(wrc PRIVATE ${CDEFS_1}
	BINDIR=\"/src/wine/build/../install/bin\"
	DATADIR=\"/src/wine/build/../install/share\"
	INCLUDEDIR=\"/src/wine/build/../install/include\")
set_target_properties(wrc
    PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/wrc")

add_executable(winebuild
	winebuild/import.c
	winebuild/main.c
	winebuild/parser.c
	winebuild/relay.c
	winebuild/res16.c
	winebuild/res32.c
	winebuild/spec16.c
	winebuild/spec32.c
	winebuild/utils.c)
target_include_directories(winebuild PRIVATE
	winebuild)
target_compile_options(winebuild PRIVATE ${CFLAGS_1})
target_compile_definitions(winebuild PRIVATE ${CDEFS_1})

