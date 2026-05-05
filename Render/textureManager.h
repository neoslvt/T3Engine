namespace T3{
    //std::map<std::string,sf::Texture*> texturesBuffer;
    std::map<std::string,Texture2D> texturesBuffer;
    std::map<std::string,Image> imageToTextureBuffer;


    //sf::Texture* loadTexture( std::string name, bool repeat = true ){
    std::string loadTexture( std::string name, bool repeat = true ){
        name = "/textures/" + name;
        
        if (T3::texturesBuffer.find("assets" + name) != T3::texturesBuffer.end())
            return "assets" + name;

        if (T3::imageToTextureBuffer.find("assets" + name) != T3::imageToTextureBuffer.end())
            return "assets" + name;


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

        //std::lock_guard<std::mutex> guard(render::renderMutex);
        imageToTextureBuffer.insert({ "assets" + name, LoadImage( ("assets" + name).c_str() ) });

        return "assets" + name;
    }

    T3::bounds loadTextureBounds( std::string name, bool repeat = true ){
        name = "/textures/" + name;
        
        if (T3::texturesBuffer.find("assets" + name) != T3::texturesBuffer.end())
            return T3::bounds(0,0,T3::texturesBuffer["assets" + name].width,T3::texturesBuffer["assets" + name].height);

        if (T3::imageToTextureBuffer.find("assets" + name) != T3::imageToTextureBuffer.end())
            return T3::bounds(0,0,T3::imageToTextureBuffer["assets" + name].width,T3::imageToTextureBuffer["assets" + name].height);


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

        //std::lock_guard<std::mutex> guard(render::renderMutex);
        Image tempImage = LoadImage( ("assets" + name).c_str() );
        imageToTextureBuffer.insert({ "assets" + name, tempImage});

        return T3::bounds(0,0,tempImage.width,tempImage.height);
    }
    
}