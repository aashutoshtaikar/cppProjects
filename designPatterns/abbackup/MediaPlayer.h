#include<iostream>
#include<string>
using namespace std;

class MediaPlayer{
    public:
    virtual void play(string audioType, string fileName)=0;
};

