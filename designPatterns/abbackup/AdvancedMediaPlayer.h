#include<iostream>
#include<string>
using namespace std;


class AdvancedMediaPlayer{
    public:
    virtual void playVlc(string fileName)=0;
    virtual void playMp4(string fileName)=0;
};

class VlcPlayer:public AdvancedMediaPlayer{
    public:
    void playVlc(string fileName){
        cout<<"playing vlc fileName: "<<fileName<<endl;
    }

    void playMp4(string fileName){
        //do nothing
    }
};

class Mp4Player:public AdvancedMediaPlayer{
    public:
    void playVlc(string fileName){
     //do nothing
    }

    void playMp4(string fileName){
        cout<<"playing Mp4 fileName: "<<fileName<<endl;
    }
};