//
//  lua_admanager_manual.cpp
//  SnakeGameLua
//
//  Created by Eleven Chen on 14-8-21.
//
//

#include "lua_admanager_manual.h"
#ifdef __cplusplus
extern "C" {
#endif
#include  "tolua_fix.h"
#ifdef __cplusplus
}
#endif

#include "AdManager.h"


static int lua_adManager_showAds(lua_State* L)
{
    if (nullptr == L)
        return 0;
    CCLOG("lua_adManager_showAds");
    AdManager::getInstance()->showAds();

    return 0;
}

static int lua_adManager_hideAds(lua_State* L)
{
	if (nullptr == L)
		return 0;
	CCLOG("lua_adManager_hideAds");
	AdManager::getInstance()->hideAds();

	return 0;
}

int register_all_admanager_manual(lua_State* L)
{
	tolua_open(L);
	tolua_module(L, NULL, 0);
	tolua_beginmodule(L, NULL);
	tolua_function(L, "showAds", lua_adManager_showAds);
	tolua_function(L, "hideAds", lua_adManager_hideAds);
	tolua_endmodule(L);
	return 0;
}

