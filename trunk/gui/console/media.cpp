#include <iostream>
#include <windows.h>
#include <mmsystem.h>
#include "media.h"

media::media()
{
}
media::~media()
{
}
void media::play(char* f)
{
    PlaySound(f,NULL,SND_SYNC);
}
