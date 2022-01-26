#include <a_samp>
#include <streamer>

#include "logging.inc"

#include <YSI_Visual\y_commands>
#include <YSI_Server\y_colours>

new
    STREAMER_TAG_3D_TEXT_LABEL: making_one,
    Text3D: making_two;

main()
{
    printf("Testing playground");
}

YCMD:create(playerid, content[], help)
{
    if (help)
    {
        SendClientMessage(playerid, X11_WHITE, "Test creating things.");
        return COMMAND_OK;
    }
    making_one = Streamer_CreateLabel("Hello World 1", X11_ORANGE, 0.0, 10.0, 3.0, 300.0);
    making_two = Create3DTextLabel("Hello World 2", X11_WHITE, 0.0, 0.0, 3.0, 300.0, 0, 0);

    SendClientMessage(playerid, X11_WHITE, "Created!");
    return COMMAND_OK;
}

YCMD:destroy(playerid, content[], help)
{
    if (help)
    {
        SendClientMessage(playerid, X11_WHITE, "Test destroying things.");
        return COMMAND_OK;
    }

    Streamer_DestroyLabel(making_one);
    Delete3DTextLabel(making_two);
    
    SendClientMessage(playerid, X11_WHITE, "Destroyed!");
    return COMMAND_OK;
}