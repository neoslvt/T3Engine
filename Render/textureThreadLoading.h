namespace textureThread{

    void asyncLoadTextureBuffer(){
        if( !T3::imageToTextureBuffer.size() )
            return;

        std::lock_guard<std::mutex> guard(render::renderMutex);

        for (auto const& [key, val] : T3::imageToTextureBuffer)
        {
            Texture2D tempTexture = LoadTextureFromImage( val );

            if( tempTexture.id <= 0 ){
                std::cerr << "Failed to load texture: " << key << "\n";
                continue;
            }

            GenTextureMipmaps( &tempTexture );
            //usleep(5000);
            T3::texturesBuffer.insert({ key, tempTexture });
            UnloadImage(val);
        }
        T3::imageToTextureBuffer.clear();

        for (int i = 0; i < T3::renderablesBuffer.size(); i++)
        {
            renderable::base* temp = (renderable::base*)T3::renderablesBuffer[i];
            if( !temp->screen && !temp->removed ){

                switch( temp->type ){
                    case 2:{
                        renderable::brush* tempObj = (renderable::brush*)T3::renderablesBuffer[i];
                        if( T3::texturesBuffer.find(tempObj->texture) != T3::texturesBuffer.end() )
                            tempObj->textureLoaded = true;
                    }
                    case 1:{
                        renderable::sprite* tempObj = (renderable::sprite*)T3::renderablesBuffer[i];
                        if( T3::texturesBuffer.find(tempObj->texture) != T3::texturesBuffer.end() )
                            tempObj->textureLoaded = true;
                    } 
                }
            }
        }

    }

}