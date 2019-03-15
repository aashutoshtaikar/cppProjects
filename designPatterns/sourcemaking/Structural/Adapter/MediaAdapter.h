#include"AdvancedMediaPlayer.h"
#include"MediaPlayer.h"
#include<string>
using namespace std;

class MediaAdapter:public MediaPlayer{
    public:

    AdvancedMediaPlayer *amp;

    MediaAdapter(string audioType){
        if (audioType=="vlc"){
            amp = new VlcPlayer();
        }
        else if(audioType=="mp4"){
            amp = new Mp4Player();
        }
    }
    
    void play(string audioType,string fileName){
        if (audioType=="vlc"){
           amp->playVlc(fileName);
        }
        else if(audioType=="mp4"){
           amp->playMp4(fileName);
        }
    }

    ~MediaAdapter(){
        delete amp;
    }
};