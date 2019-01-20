#include"AudioPlayer.h"

int main(){
    AudioPlayer *ap = new AudioPlayer();

    ap->play("mp3","beyond the horizon.mp3");
    ap->play("mp4","alone.mp4");
    ap->play("vlc","far far away.vlc");
    ap->play("avi","mind me.avi");
}