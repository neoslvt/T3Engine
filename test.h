
namespace scenes{
    

    void music(){
        //T3::music.loadFromFile("T3bass/test.mendi");

        //T3::playSound("T3bass/Bossa Brazil.wav");

        T3::window->process();
    }

    void test(){
        //T3::music.loadFromFile("T3bass/test.mendi");
        //T3::playSound("T3bass/Bossa Brazil.wav");
        //
//        for (int i = 0; i < 100; i++)
//        {
//            T3::dynamic* sfml = new T3::dynamic("ball.png");
//            sfml->velocity.x = -30 + rand()%60;
//            sfml->velocity.y = -30 + rand()%60;
//            sfml->sprite->setPosition(i*15 + rand()%50,rand()%60);
//            sfml->sprite->setScale(0.15,0.15);
//            sfml->pixel_collision = false;
//            sfml->weight = 1.3f;
//            sfml->screenBorders = true;
//
//            sfml->addHook([](T3::dynamic* sfml){
//                sfml->sprite->setRotation( sfml->sprite->getPosition().x*2.5 );
//            });
//
//        }

        //T3::light* newLight1 = new T3::light( sf::Vector2f(0.3,0.5), sf::Color(255,0,0) );
//        T3::dynamic* sfml1 = new T3::dynamic("ball.png");
//        sfml1->sprite->setScale(0.15,0.15);
//        sfml1->weight = 1.3f;
//        sfml1->pixel_collision = false;
//        sfml1->screenBorders = true;
//        sfml1->addHook(player_phys);
        //sfml1->custom.push_back( newLight1 );
        //sfml1->addHook([](T3::dynamic* sfml){
            //T3::light* temp = (T3::light*)sfml->custom[0];
            //temp->position = sfml->sprite->getPosition() + sf::Vector2f(0,0);
        //});


//        T3::light* newLight2 = new T3::light( sf::Vector2f(0.3,0.5), sf::Color(0,255,0) );
//        T3::dynamic* sfml2 = new T3::dynamic("ball.png");
//        sfml2->sprite->setScale(0.0,0.0);
//        sfml2->weight = 1.3f;
//        sfml2->screenBorders = true;
//        sfml2->addHook(player_phys);
//        sfml2->custom.push_back( newLight2 );
//        sfml2->addHook([](T3::dynamic* sfml){
//            T3::light* temp = (T3::light*)sfml->custom[0];
//            temp->position = sfml->sprite->getPosition() + sf::Vector2f(0,0);
//        });
//
//
//
//        T3::light* newLight3 = new T3::light( sf::Vector2f(0.3,0.5), sf::Color(0,0,255) );
//        T3::dynamic* sfml3 = new T3::dynamic("ball.png");
//        sfml3->sprite->setScale(0.0,0.0);
//        sfml3->weight = 1.3f;
//        sfml3->screenBorders = true;
//        sfml3->addHook(player_phys);
//        sfml3->custom.push_back( newLight3 );
//        sfml3->addHook([](T3::dynamic* sfml){
//            T3::light* temp = (T3::light*)sfml->custom[0];
//            temp->position = sfml->sprite->getPosition() + sf::Vector2f(0,0);
//        });

        //T3::dynamic* walls = new T3::dynamic("logo.png");
        //walls->active = false;
        //walls->sprite->setPosition(1920/2,1080/2);
        //walls->pixel_collision = true;

        //T3::window->sky = true;

        if( global::load_map == "" )
            luaManager::loadFile("main.lua");
        else
            scene::load( global::load_map );
        
        for (int i = 0; i < addons::dirs.size(); i++)
        {
            std::filesystem::path filepath = std::string(addons::dirs[i] + "/logic/autorun/");
            bool filepathExists = std::filesystem::is_directory(filepath.parent_path());
            if( !filepathExists )
                continue;
            
            for(auto& p : std::filesystem::recursive_directory_iterator( addons::dirs[i] + "/logic/autorun" )){
                if (!p.is_directory()){
                    luaFunctions::loadString( file::readRaw( p.path().string() ) );
                    luaFunctions::print( p.path().string() + " was executed!" );
                }
            }
        }

        //luaManager::print( "Test\nTest\nTest\nTest\nTest\nTest\nTest\n" );
        T3::window->process();
    }

}