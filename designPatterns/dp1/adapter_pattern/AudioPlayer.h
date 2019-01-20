#include"MediaAdapter.h"



class AudioPlayer:public MediaPlayer{
    public:
    void play(string audioType, string fileName){
        if(audioType=="mp3"){
            cout<<"playing mp3 fileName: "<<fileName<<endl;
        }
        else if(audioType=="vlc" || audioType=="mp4"){
            MediaAdapter *ma = new MediaAdapter(audioType);
            ma->play(audioType,fileName);            
        }
        else{
            cout<<"Invalid media "<<audioType<<" format not supported"<<endl;
        }
    }
};