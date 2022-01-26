#if defined _inc_logging
    #undef _inc_logging
#endif

#if defined _logging_included
    #endinput
#endif

#define _logging_included

// Find y_hooks
#if !defined _INC_y_hooks
    #tryinclude <YSI_Coding\y_hooks>
#endif
#if !defined _INC_y_hooks
    #tryinclude <YSI\y_hooks>
#endif
#if !defined _INC_y_hooks
    #error Cannot find y_hooks, download it from https://github.com/pawn-lang/YSI-Includes
#endif

// Streamer takes almost 31 characters, to trim it we need to rewrote the native.
native STREAMER_TAG_3D_TEXT_LABEL:Streamer_CreateLabel(const text[], color, Float:x, Float:y, Float:z, Float:drawdistance, attachedplayer = INVALID_PLAYER_ID, attachedvehicle = INVALID_VEHICLE_ID, testlos = 0, worldid = -1, interiorid = -1, playerid = -1, Float:streamdistance = STREAMER_3D_TEXT_LABEL_SD, STREAMER_TAG_AREA:areaid = STREAMER_TAG_AREA:-1, priority = 0) = CreateDynamic3DTextLabel;
native Streamer_DestroyLabel(STREAMER_TAG_3D_TEXT_LABEL:id) = DestroyDynamic3DTextLabel;

/*
    -----------------------
        Hook Functions
    -----------------------

*/

hook native STREAMER_TAG_3D_TEXT_LABEL:Streamer_CreateLabel(const text[], color, Float:x, Float:y, Float:z, Float:drawdistance, attachedplayer, attachedvehicle, testlos, worldid, interiorid, playerid, Float:streamdistance, STREAMER_TAG_AREA:areaid, priority)
{
    new STREAMER_TAG_3D_TEXT_LABEL:return_1 = STREAMER_TAG_3D_TEXT_LABEL:continue(text, color, x, y, z, drawdistance, attachedplayer, attachedvehicle, testlos, worldid, interiorid, playerid, streamdistance, areaid, priority);

    printf("[Function Log]: CreateDynamic3DTextLabel(text[] = \"%s\", color = %d, x = %f, y = %f, z = %f, drawdistance = %f, attachedplayer = %d, attachedvehicle = %d, teslos = %d, worldid = %d, interiorid = %d, playerid = %d, streamdistance = %d, areaid = %d, priority = %d) = Text3D:%d",
        text, color,
        x, y, z, drawdistance, attachedplayer, attachedvehicle, 
        testlos, worldid, interiorid, playerid, _:streamdistance, _:areaid, priority,
        _:return_1
    );
    return return_1;
}

hook native Streamer_DestroyLabel(STREAMER_TAG_3D_TEXT_LABEL:id)
{
    new return_2 = continue(id);

    printf("[Function Log]: DestroyDynamic3DTextLabel(STREAMER_TAG_3D_TEXT_LABEL id = %d) = %d", _:id, return_2);
    return return_2;
}

hook native Text3D:Create3DTextLabel(text[], color, Float:X, Float:Y, Float:Z, Float:DrawDistance, virtualworld, testLOS=0)
{
    new Text3D:return_3 = Text3D:continue(text, color, X, Y, Z, DrawDistance, virtualworld, testLOS);

    printf("[Function Log]: Create3DTextLabel(text[] = \"%s\", color = %d, X = %f, Y = %f, Z = %f, DrawDistance = %f, virtualworld = %d, tesLOS = %d) = Text3D:%d",
        text, color,
        X, Y, Z, DrawDistance,
        virtualworld, testLOS,
        _:return_3
    );
    return return_3;
}

hook native Delete3DTextLabel(Text3D:id)
{
    new return_4 = continue(id);

    printf("[Function Log]: Delete3DTextLabel(Text3D:id = %d) = %d", _:id, return_4);
    return return_4;
}


/*
    -----------------------
        Hook Callbacks
    -----------------------

*/
hook OnGameModeInit()
{
    print("[Callback Log]: OnGameModeInit()");
    return 1;
}

hook OnPlayerConnect(playerid)
{
    printf("[Callback Log]: OnPlayerConnect(playerid = %d)", playerid);
    return 1;
}

hook OnPlayerSpawn(playerid)
{
    printf("[Callback Log]: OnPlayerSpawn(playerid = %d)", playerid);
    return 1;
}

hook OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
    printf("[Callback Log]: OnDialogResponse(playerid = %d, dialogid = %d, response = \"%s\", listitem = %d, inputtext[] = \"%s\")",
        playerid, dialogid,
        response ? "Player clicked Yes" : "Player clicked No",
        listitem, inputtext
    );
    return 0;
}

hook OnPlayerCommandText(playerid, cmdtext[])
{
    printf("[Callback Log]: OnPlayerCommandText(playerid = %d, cmdtext[] = \"%s\")", playerid, cmdtext);
    return 0;
}

hook OnPlayerDisconnect(playerid, reason)
{
    new arrExitReason[3][24] = {
        "Timeout/Crash",
        "Quit",
        "Kicked/Banned"
    };
    printf("[Callback Log]: OnPlayerDisconnect(playerid = %d, reason = \"%s\")", playerid, arrExitReason[reason]);
    return 1;
}

hook OnGameModeExit()
{
    print("[Callback Log]: OnGameModeExit()");
    return 1;
}
