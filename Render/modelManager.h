namespace T3{
    //std::map<std::string,sf::Texture*> texturesBuffer;
    std::map<std::string,Model> modelsVerteciesBuffer;
    
    //sf::Texture* loadTexture( std::string name, bool repeat = true ){
    Model loadModel( std::string name ){
        name = "/models/" + name;
        if (T3::modelsVerteciesBuffer.find("assets" + name) != T3::modelsVerteciesBuffer.end())
            return T3::modelsVerteciesBuffer[ "assets" + name ];


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

        Model tempModel = LoadModel( ("assets" + name).c_str() );

        //if( tempModel.id <= 0 )
        //    std::cerr << "Failed to load texture: " << "assets" << name << "\n";

        //GenTextureMipmaps( &tempModel );
        T3::modelsVerteciesBuffer.insert({ "assets" + name, tempModel });

        //T3::texturesBuffer[ "assets" + name ]->loadFromFile( "assets" + name );
        //T3::texturesBuffer[ "assets" + name ]->loadFromFile( "assets" + name );
        //T3::texturesBuffer[ "assets" + name ]->setRepeated( repeat );
        //T3::texturesBuffer[ "assets" + name ]->generateMipmap();
        
        return T3::modelsVerteciesBuffer[ "assets" + name ];
    }
    
}