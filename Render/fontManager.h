namespace T3{
    //std::map<std::string,sf::Texture*> texturesBuffer;
    std::map<std::string,Font> fontBuffer;
    
    //sf::Texture* loadTexture( std::string name, bool repeat = true ){
    std::string loadFont( std::string name ){
        name = "/fonts/assets" + name;
        if (T3::fontBuffer.find(name) != T3::fontBuffer.end())
            return name;


        // Addons texture loading      
//        for (int i = 0; i < addons::dirs.size(); i++)
//        {
//            if( T3::texturesBuffer[ "assets" + name ]->loadFromFile( addons::dirs[i] + name ) ){
//                T3::texturesBuffer[ "assets" + name ]->setRepeated( repeat );
//                T3::texturesBuffer[ "assets" + name ]->generateMipmap();
                //
//                return T3::texturesBuffer[ "assets" + name ];
//            }
//        }

        auto temp = LoadFontEx( name.c_str(), 32, 0, 250 );
        T3::fontBuffer.insert({ name, temp });

        return name;
    }
    
}