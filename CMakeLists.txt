cmake_minimum_required(VERSION 3.5)

project(twine LANGUAGES C)

include(GNUInstallDirs)

find_library(MATH_LIBRARY m)

set(CFLAGS -Wall -pipe -fcf-protection=none -fvisibility=hidden -fno-stack-protector -fno-strict-aliasing -Wdeclaration-after-statement -Wempty-body -Wignored-qualifiers -Winit-self -Wlogical-op -Wno-packed-not-aligned -Wpointer-arith -Wshift-overflow=2 -Wstrict-prototypes -Wtype-limits -Wunused-but-set-parameter -Wvla -Wwrite-strings -Wno-misleading-indentation -gdwarf-4)

set(CFLAGS_1 -D__WINESRC__ -DWINE_UNIX_LIB ${CFLAGS} -g)
set(CDEFS_1 _FORTIFY_SOURCE=0)

set(CFLAGS_2 -m32 -D_UCRT -D__WINESRC__ ${CFLAGS} -fno-PIC -fasynchronous-unwind-tables -D_WIN32 -fno-builtin -fshort-wchar -Wno-format -fno-omit-frame-pointer -g)

set(GLOBAL_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
include_directories(${GLOBAL_INCLUDE_DIR})
include_directories(${CMAKE_CURRENT_BINARY_DIR}/include)

add_subdirectory(tools)

# Generate headers from all global IDL files
file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/include)
file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/include/wine)
set(GLOBAL_IDL
	include/wtypes
	include/oaidl
	include/objidl
	include/unknwn
	include/oleidl
	include/objidlbase
	include/urlmon
	include/servprov
	include/msxml
	include/propidl
	include/comcat
	include/docobj
	include/ocidl
	include/shobjidl
	include/shtypes
	include/propsys
	include/structuredquerycondition
	include/objectarray
	include/shobjidl_core
	include/d3d10_1
	include/d3d10
	include/dxgi
	include/dxgitype
	include/dxgicommon
	include/dxgiformat
	include/d3dcommon
	include/d3d10sdklayers
	include/d3d10shader
	include/d3d10effect
	include/d2d1_3
	include/d2d1_2
	include/d2d1_1
	include/d2d1
	include/dcommon
	include/d2d1effects
	include/d2d1effects_1
	include/d2d1effects_2
	include/d2d1effectauthor
	include/ctxtcall
	include/exdisp
	include/shdeprecated
	include/hlink
	include/shldisp
	include/activaut
	include/activdbg
	include/activscp
	include/dispex
	include/mlang
	include/mshtml
	include/dimm
	include/mshtmhst
	include/docobjectservice
	include/richole
	include/downloadmgr
	include/optary
	include/indexsrv
	include/htiface
	include/urlhist
	include/objsafe
	include/perhist
	include/netcon
	include/netfw
	include/icftypes
	include/natupnp
	include/msctf
	include/textstor
	include/ctfutb
	include/sensevts
	include/ocmm
	include/commoncontrols
	include/tlogstg
	include/msdasc
	include/oledb
	include/netcfgx
	include/shimgdata
	include/comsvcs
	include/directmanipulation
	include/atliface
	include/iads
	include/wine/orpc
	include/activation
	include/inspectable
	include/hstring
	include/roparameterizediid
	include/restrictederrorinfo
	include/uiautomationclient
	include/uiautomationcore
	include/oleacc
	include/wincodecsdk
	include/wincodec
	include/ieautomation
	include/mimeole
	include/wine/svcctl
	include/wine/plugplay
	include/wbemcli
	include/amsi
	include/amstream
	include/amvideo
	include/asptlb
	include/asyncinfo
	include/audioclient
	include/audiopolicy
	include/austream
	include/bdaiface
	include/bits
	include/bits1_5
	include/bits2_0
	include/bits2_5
	include/bits3_0
	include/bits5_0
	include/cdosys
	include/cmnquery
	include/control
	include/cor
	include/cordebug
	include/corsym
	include/d3d11
	include/d3d11_1
	include/d3d11_2
	include/d3d11_3
	include/d3d11_4
	include/d3d11on12
	include/d3d11sdklayers
	include/d3d12
	include/d3d12sdklayers
	include/d3d12shader
	include/d3d12video
	include/d3dx11core
	include/dcomp
	include/dcompanimation
	include/dcomptypes
	include/ddstream
	include/devicetopology
	include/dhtmled
	include/dispatcherqueue
	include/dmodshow
	include/documenttarget
	include/dragdropinterop
	include/drmexternals
	include/dvdif
	include/dwrite
	include/dwrite_1
	include/dwrite_2
	include/dwrite_3
	include/dxgi1_2
	include/dxgi1_3
	include/dxgi1_4
	include/dxgi1_5
	include/dxgi1_6
	include/dxgidebug
	include/dxva2api
	include/dxvahd
	include/endpointvolume
	include/eventtoken
	include/evr
	include/evr9
	include/filter
	include/fusion
	include/gameux
	include/holographicspaceinterop
	include/hrtfapoapi
	include/htiframe
	include/httprequest
	include/icodecapi
	include/iextag
	include/iimgctx
	include/imnact
	include/imnxport
	include/inputpaneinterop
	include/inputscope
	include/inseng
	include/ivectorchangedeventargs
	include/mediaobj
	include/medparam
	include/metahost
	include/mfd3d12
	include/mfidl
	include/mfmediaengine
	include/mfobjects
	include/mfplay
	include/mfreadwrite
	include/mftransform
	include/mimeinfo
	include/mmc
	include/mmdeviceapi
	include/mmstream
	include/mpegtype
	include/msado15_backcompat
	include/mscoree
	include/msdadc
	include/msident
	include/msinkaut
	include/msopc
	include/mstask
	include/msxml2
	include/msxml6
	include/netlistmgr
	include/proofofpossessioncookieinfo
	include/pstore
	include/qedit
	include/relogger
	include/rtworkq
	include/sapi
	include/sapiddk
	include/spatialaudioclient
	include/strmif
	include/systemmediatransportcontrolsinterop
	include/taskschd
	include/thumbcache
	include/tom
	include/transact
	include/txcoord
	include/txdtc
	include/uianimation
	include/uiribbon
	include/uiviewsettingsinterop
	include/videoacc
	include/vmr9
	include/vsbackup
	include/vss
	include/vswriter
	include/wbemdisp
	include/wbemprov
	include/weakreference
	include/wia_lh
	include/wia_xp
	include/windows.applicationmodel.activation
	include/windows.applicationmodel.background
	include/windows.applicationmodel.core
	include/windows.applicationmodel.datatransfer.dragdrop.core
	include/windows.applicationmodel.datatransfer.dragdrop
	include/windows.applicationmodel.datatransfer
	include/windows.applicationmodel
	include/windows.data.json
	include/windows.data.xml.dom
	include/windows.devices.bluetooth
	include/windows.devices.enumeration
	include/windows.devices.geolocation
	include/windows.devices.haptics
	include/windows.devices.input
	include/windows.devices.power
	include/windows.devices.radios
	include/windows.devices.usb
	include/windows.foundation.collections
	include/windows.foundation
	include/windows.foundation.metadata
	include/windows.foundation.numerics
	include/windows.gaming.input.custom
	include/windows.gaming.input.forcefeedback
	include/windows.gaming.input
	include/windows.gaming.ui
	include/windows.globalization
	include/windows.graphics.capture
	include/windows.graphics.capture.interop
	include/windows.graphics.directx.direct3d11
	include/windows.graphics.directx
	include/windows.graphics.effects
	include/windows.graphics
	include/windows.graphics
	include/windows.graphics.imaging
	include/windows.management.deployment
	include/windows.media.capture
	include/windows.media.closedcaptioning
	include/windows.media.devices
	include/windows.media.effects
	include/windows.media.faceanalysis
	include/windows.media
	include/windows.media.render
	include/windows.media.speechrecognition
	include/windows.media.speechsynthesis
	include/windows.networking.connectivity
	include/windows.networking
	include/windows.perception.spatial
	include/windows.perception.spatial.surfaces
	include/windows.security.authentication.onlineid
	include/windows.security.authorization.appcapabilityaccess
	include/windows.security.credentials
	include/windows.security.credentials.ui
	include/windows.security.cryptography
	include/windows.security.enterprisedata
	include/windows.security.exchangeactivesyncprovisioning
	include/windows.security.isolation
	include/windows.storage.fileproperties
	include/windows.storage
	include/windows.storage.search
	include/windows.storage.streams
	include/windows.system
	include/windows.system.power
	include/windows.system.profile
	include/windows.system.profile.systemmanufacturers
	include/windows.system.threading
	include/windows.system.userprofile
	include/windows.ui.composition
	include/windows.ui.composition.interop
	include/windows.ui.core
	include/windows.ui
	include/windows.ui.input
	include/windows.ui.notifications
	include/windows.ui.viewmanagement
	include/windows.ui.xaml
	include/windows.ui.xaml
	include/windows.ui.xaml.interop
	include/windowscontracts
	include/wine/fil_data
	include/wine/iaccessible2
	include/wine/itss
	include/wine/mfinternal
	include/wine/winedxgi
	include/winsxs
	include/wmcodecdsp
	include/wmdrmsdk
	include/wmiutils
	include/wmp
	include/wmprealestate
	include/wmpservices
	include/wmsbuffer
	include/wmsdkidl
	include/wmsecure
	include/wpcapi
	include/wsdbase
	include/wsddisco
	include/wsdxml
	include/wuapi
	include/xamlom
	include/xapo
	include/xaudio2
	include/xaudio2fx
	include/xmllite
	include/xpsobjectmodel
	include/xpsobjectmodel_1)

set(GLOBAL_IDL_HEADERS ${GLOBAL_IDL})
list(TRANSFORM GLOBAL_IDL PREPEND ${CMAKE_CURRENT_SOURCE_DIR}/)
list(TRANSFORM GLOBAL_IDL APPEND .idl)
list(TRANSFORM GLOBAL_IDL_HEADERS PREPEND ${CMAKE_CURRENT_BINARY_DIR}/)
list(TRANSFORM GLOBAL_IDL_HEADERS APPEND .h)

function(add_wine_target)
    cmake_parse_arguments(
        ARG
        ""
        "TYPE;NAME;IMPORTLIB;PARENTSRC;UNIXLIB"
		"SOURCES;IMPORTS;DELAYIMPORTS;EXTRADEFS;DLLDATA_EXTRADEFS;UNIX_LOADER_EXTRADEFS;EXTRAINCL;EXTRA_OBJS;EXTRADLLFLAGS;i386_EXTRADLLFLAGS;x86_64_EXTRADLLFLAGS;UNIX_CFLAGS;UNIX_LIBS"
        ${ARGN}
    )

	foreach(OUTPUT SOURCE IN ZIP_LISTS GLOBAL_IDL_HEADERS GLOBAL_IDL)
		add_idl(OUTPUT ${OUTPUT}
			FLAGS -m32 --nostdinc -I${GLOBAL_INCLUDE_DIR} -D__WINESRC__
			SOURCE ${SOURCE})
		set_source_files_properties(${OUTPUT} PROPERTIES GENERATED TRUE)
	endforeach()

	set(IDL_FILES ${ARG_SOURCES})
	list(FILTER IDL_FILES INCLUDE REGEX "\\.idl$")
	list(TRANSFORM IDL_FILES REPLACE "\\.idl$" "")

	set(NON_IDL_FILES ${ARG_SOURCES})
	list(FILTER NON_IDL_FILES EXCLUDE REGEX "\\.idl$")

	# If PARENTSRC is given, use it to locate the files missing in the current directory.
    set(result_list "")
    foreach(filename IN LISTS ${NON_IDL_FILES})
        if(EXISTS "${filename}")
            list(APPEND result_list "${filename}")
        elseif(EXISTS "${ARG_PARENTSRC}/${filename}")
            file(RELATIVE_PATH relative_path "${CMAKE_CURRENT_SOURCE_DIR}" "${ARG_PARENTSRC}/${filename}")
            list(APPEND result_list "${relative_path}")
        else()
            message(WARNING "File ${filename} not found in current directory or ${ARG_PARENTSRC}")
        endif()
    endforeach()
    set(NON_IDL_FILES ${result_list})

	if ("${ARG_TYPE}" STREQUAL "DLL")
		foreach(IDL_FILE ${IDL_FILES})
			set(FLAGS -m32 --nostdinc -D_UCRT -D__WINESRC__ -Idlls/${ARG_NAME} -I${GLOBAL_INCLUDE_DIR})
			add_idl(OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/${IDL_FILE}_p.c
				FLAGS ${FLAGS}
				SOURCE ${CMAKE_CURRENT_SOURCE_DIR}/${IDL_FILE}.idl)
			add_idl(OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/${IDL_FILE}.h
				FLAGS ${FLAGS}
				SOURCE ${CMAKE_CURRENT_SOURCE_DIR}/${IDL_FILE}.idl)
			add_idl(OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/${IDL_FILE}_r.res
				FLAGS ${FLAGS}
				SOURCE ${CMAKE_CURRENT_SOURCE_DIR}/${IDL_FILE}.idl)
			set_source_files_properties(
				${CMAKE_CURRENT_BINARY_DIR}/${IDL_FILE}_p.c
				${CMAKE_CURRENT_BINARY_DIR}/${IDL_FILE}.h
				${CMAKE_CURRENT_BINARY_DIR}/${IDL_FILE}_r.res
				PROPERTIES GENERATED TRUE)
		endforeach()
		list(TRANSFORM IDL_FILES APPEND .idl OUTPUT_VARIABLE IDL_DLL)
		list(TRANSFORM IDL_FILES PREPEND ${CMAKE_CURRENT_BINARY_DIR}/)
		list(TRANSFORM IDL_FILES APPEND .h OUTPUT_VARIABLE IDL_HEADERS)
		list(TRANSFORM IDL_FILES APPEND _p.c OUTPUT_VARIABLE IDL_SOURCES)
	elseif ("${ARG_TYPE}" STREQUAL "TLB")
		foreach(IDL_FILE ${IDL_FILES})
			set(FLAGS -m32 --nostdinc -D_UCRT -D__WINESRC__ -Idlls/${ARG_NAME} -I${GLOBAL_INCLUDE_DIR})
			add_idl(OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/${IDL_FILE}_t.res
				FLAGS ${FLAGS}
				SOURCE ${CMAKE_CURRENT_SOURCE_DIR}/${IDL_FILE}.idl)
			set_source_files_properties(
				${CMAKE_CURRENT_BINARY_DIR}/${IDL_FILE}_t.res
				PROPERTIES GENERATED TRUE)
		endforeach()
	endif()

	add_library(${ARG_NAME} OBJECT ${GLOBAL_IDL_HEADERS} ${IDL_HEADERS} ${IDL_SOURCES}
		${NON_IDL_FILES})
	target_include_directories(${ARG_NAME} PRIVATE
		${CMAKE_CURRENT_SOURCE_DIR})
	target_compile_options(${ARG_NAME} PRIVATE ${CFLAGS_2})
	target_compile_definitions(${ARG_NAME} PRIVATE ${CDEFS_1} ${ARG_EXTRADEFS})

    if (IDL_DLL)
		add_idl(OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/dlldata.c
			FLAGS --dlldata-only
			SOURCE ${IDL_DLL})
		set_source_files_properties(${CMAKE_CURRENT_BINARY_DIR}/dlldata.c PROPERTIES GENERATED TRUE)

		add_library(${ARG_NAME}_dll OBJECT ${GLOBAL_IDL_HEADERS}
			${CMAKE_CURRENT_BINARY_DIR}/dlldata.c)
		target_include_directories(${ARG_NAME}_dll PRIVATE
			${CMAKE_CURRENT_BINARY_DIR}/include)
		target_compile_options(${ARG_NAME}_dll PRIVATE ${CFLAGS_2})
		target_compile_definitions(${ARG_NAME}_dll PRIVATE ${CDEFS_1} WINE_REGISTER_DLL PROXY_DELEGATION ${DLLDATA_EXTRADEFS})
	endif()

endfunction()

function(add_wine_dll)
	add_wine_target(TYPE DLL ${ARGN})
endfunction()

function(add_wine_tlb)
	add_wine_target(TYPE TLB ${ARGN})
endfunction()

function(add_wine_drv)
	add_wine_target(TYPE DRV ${ARGN})
endfunction()

function(add_wine_staticlib)
    cmake_parse_arguments(
        ARG
        ""
        "NAME"
		"SOURCES"
        ${ARGN}
    )

	add_library(${ARG_NAME} STATIC ${ARG_SOURCES})
	target_include_directories(${ARG_NAME} PRIVATE
		${CMAKE_CURRENT_BINARY_DIR}/include
		dlls/${ARG_NAME}
		include/msvcrt)
	target_compile_options(${ARG_NAME} PRIVATE ${CFLAGS_2})
	target_compile_definitions(${ARG_NAME} PRIVATE ${CDEFS_1})

endfunction()

# Build all Wine DLLs
file(GLOB DLLS LIST_DIRECTORIES true "dlls/*")
foreach(SUBDIR ${DLLS})
    if(IS_DIRECTORY ${SUBDIR})
        add_subdirectory(${SUBDIR})
    endif()
endforeach()

