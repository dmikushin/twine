/*
 * winemac.drv entry points
 *
 * Copyright 2022 Jacek Caban for CodeWeavers
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA
 */

#include "config.h"
#include <stdarg.h>
#include "macdrv.h"


HMODULE macdrv_module = 0;

static BOOL process_attach(void)
{
    struct init_params params;

    struct localized_string *str;
    struct localized_string strings[] = {
        { .id = STRING_MENU_WINE },
        { .id = STRING_MENU_ITEM_HIDE_APPNAME },
        { .id = STRING_MENU_ITEM_HIDE },
        { .id = STRING_MENU_ITEM_HIDE_OTHERS },
        { .id = STRING_MENU_ITEM_SHOW_ALL },
        { .id = STRING_MENU_ITEM_QUIT_APPNAME },
        { .id = STRING_MENU_ITEM_QUIT },

        { .id = STRING_MENU_WINDOW },
        { .id = STRING_MENU_ITEM_MINIMIZE },
        { .id = STRING_MENU_ITEM_ZOOM },
        { .id = STRING_MENU_ITEM_ENTER_FULL_SCREEN },
        { .id = STRING_MENU_ITEM_BRING_ALL_TO_FRONT },

        { .id = 0 }
    };

    for (str = strings; str->id; str++)
        str->len = LoadStringW(macdrv_module, str->id, (WCHAR *)&str->str, 0);
    params.strings = strings;

    return !MACDRV_CALL(init, &params);
}

BOOL WINAPI DllMain(HINSTANCE instance, DWORD reason, void *reserved)
{
    if (reason != DLL_PROCESS_ATTACH) return TRUE;

    DisableThreadLibraryCalls(instance);
    macdrv_module = instance;
    return process_attach();
}
