namespace T3{
    //std::vector<sf::Sound*> soundsVector;
    //std::map<std::string,sf::SoundBuffer*> soundsBuffer;
    void* wrongSound = nullptr;
    //sf::Sound* Music;

//    sf::SoundBuffer* loadSound( std::string name ){
//        name = "/sounds/" + name;
//        bool loaded = true;
//
//        if (T3::soundsBuffer.find( "assets" + name) != T3::soundsBuffer.end())
//            return T3::soundsBuffer[ "assets" + name ];
//
//        T3::soundsBuffer.insert({ "assets" + name, new sf::SoundBuffer });
//        if( !T3::soundsBuffer[ "assets" + name ]->loadFromFile( "assets" + name ) ){
//            loaded = false;
//
//            for (int i = 0; i < addons::dirs.size(); i++)
//            {
//                if( T3::soundsBuffer[ "assets" + name ]->loadFromFile( addons::dirs[i] + name ) ){
//                    loaded = true;
//                    break;
//                }
//            }
//        }
//
//        if( !loaded )
//            return (sf::SoundBuffer*)wrongSound;
        //
//        return T3::soundsBuffer[ "assets" + name ];
//    }

    void playSound( std::string name, float pitch = 1, float volume = 100, amath::Vector2 pos = amath::Vector2(0,0) ){
//        sf::SoundBuffer* sound = loadSound(name);
//        if( sound == wrongSound )
//            return;
//
//        T3::soundsVector.push_back( new sf::Sound );
//        T3::soundsVector[ T3::soundsVector.size()-1 ]->setBuffer( *sound );
//
//        T3::soundsVector[ T3::soundsVector.size()-1 ]->setPitch( pitch );
//
//        if( pos.x != 0 && pos.y != 0 ){
//            T3::soundsVector[ T3::soundsVector.size()-1 ]->setPosition(pos.x*0.004f, pos.y*0.004f, -5.f);
//            //T3::soundsVector[ T3::soundsVector.size()-1 ]->setRelativeToListener(true);
//            T3::soundsVector[ T3::soundsVector.size()-1 ]->setMinDistance(20.f);
//            T3::soundsVector[ T3::soundsVector.size()-1 ]->setAttenuation(25.f);
//        }else{
//            T3::soundsVector[ T3::soundsVector.size()-1 ]->setRelativeToListener(true);
//        }
//
//        T3::soundsVector[ T3::soundsVector.size()-1 ]->setVolume(volume);
//        T3::soundsVector[ T3::soundsVector.size()-1 ]->play();
    }


    void clearSoundBuffer(){
//        for (int i = 0; i < T3::soundsVector.size(); i++)
//        {
//            if( T3::soundsVector[i]->getStatus() == 0 ){
//                delete( T3::soundsVector[i] );
//                T3::soundsVector.erase( T3::soundsVector.begin() + i );
//            } 
//
//        }
    }

    namespace music{
        void init(){
            //T3::Music = new sf::Sound;
        }

        void load(std::string name ){
            //T3::Music->setBuffer( *T3::loadSound(name) );
        }

        void setVolume( float value ){
            //T3::Music->setVolume( value );
        }

        void play(){
            //T3::Music->play();
            //T3::Music->setLoop(true);
        }

        void pause(){
            //T3::Music->pause();
        }

        void stop(){
            //T3::Music->stop();
        }
    }
}