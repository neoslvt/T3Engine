
namespace T3{

    class object
    {
    public:
        int id;
        //sf::Shader* shader;
        //sf::Shader* depth;
        renderable::sprite* sprite;
        //sf::Image textureBuffer;
        std::vector<void*> custom;
        amath::Vector2 rectSize;
        amath::Vector2 rectPos;
        bool local = false;

        object( std::string texture ){
            T3::renderablesBuffer.push_back( new renderable::sprite() );

            this->sprite = (renderable::sprite*)T3::renderablesBuffer[T3::renderablesBuffer.size()-1];
            this->sprite->id = rand() % 99999999999;
            this->sprite->setTextureStr( texture );

            //this->textureBuffer = this->sprite->getTexture()->copyToImage();

            
            //this->id = static_cast<int>(T3::renderablesBuffer.size());
            this->id = rand() % 99999999999;
            this->rectSize = amath::Vector2(0,0);
            this->rectPos = amath::Vector2(0,0);

            //this->shader = T3::loadShader("ent/obj.glsl");
            //this->depth = T3::loadShader("ent/depth.glsl");
            //T3::spriteShadersBuffer.push_back( this->shader );
            //T3::spriteShadersBufferDepth.push_back( this->depth );
        };

        int getLayer(){
            return this->sprite->layer;
        }

        void setLayer( int newLayer = 0 ){
            this->sprite->layer = newLayer;
        }

        void setShaderFloatArray( std::string variable, std::vector<float> arr ){
            //this->sprite->setShaderFloatArray(variable, arr);
        }

        void setShaderInt(std::string variable, int parameter){
            //this->sprite->setShaderInt(variable, parameter);
        }

        void setShaderFloat(std::string variable, float parameter){
            //this->sprite->setShaderFloat(variable, parameter);
        }

        void setShaderColor(std::string variable, T3::color parameter){
            //this->sprite->setShaderColor(variable, parameter);
        }

        amath::Vector2 getBounds(){
            auto temp = this->sprite->getGlobalBounds();
            return amath::Vector2(temp.width,temp.height);
        }

        ~object(){
            for (int i = 0; i < T3::renderablesBuffer.size(); i++)
            {
                if( ((renderable::sprite*)T3::renderablesBuffer[i])->id == this->sprite->id ){
                    this->sprite->removed = true;
                    T3::renderablesBuffer.erase(T3::renderablesBuffer.begin() + i);
                    break;
                }
            }
        }

        void setRectSizeXY( float x, float y){
            this->rectSize = amath::Vector2(x,y);
            this->sprite->setTextureRect( T3::bounds(this->rectPos, this->rectSize) );
            this->sprite->setOrigin( sprite->getLocalBounds().width/2, sprite->getLocalBounds().height/2 );
        };

        void setRectSize( amath::Vector2 rectSize ){
            this->rectSize = rectSize;
            this->sprite->setTextureRect( T3::bounds(this->rectPos, this->rectSize) );
            this->sprite->setOrigin( sprite->getLocalBounds().width/2, sprite->getLocalBounds().height/2 );
        };

        void setRectPosXY( float x, float y ){
            this->rectPos = amath::Vector2(x,y);
            this->sprite->setTextureRect( T3::bounds(this->rectPos, this->rectSize) );
            this->sprite->setOrigin( sprite->getLocalBounds().width/2, sprite->getLocalBounds().height/2 );
        };

        void setRectPos( amath::Vector2 rectPos ){
            this->rectPos = rectPos;
            this->sprite->setTextureRect( T3::bounds(this->rectPos, this->rectSize) );
            this->sprite->setOrigin( sprite->getLocalBounds().width/2, sprite->getLocalBounds().height/2 );
        };

        void setPosition( float x, float y){
            this->sprite->setRenderPosition(x,y);
        };

        void loadShader( std::string path ){
            this->sprite->loadShader(path);
        };

        void setPositionByVectorLua( amath::Vector2 position ){
            this->sprite->setRenderPosition(position.x,position.y);
        };

        void setPositionByVector( amath::Vector2 position ){
            this->sprite->setRenderPosition(position.x,position.y);
        };

        void setScale( float factor ){
            this->sprite->setScale( factor,factor );
        };

        void setScaleXY( float factorX, float factorY ){
            this->sprite->setScale( factorX,factorY );
        };

        void setRotation( float degree ){
            this->sprite->setRenderRotation( degree );
        }

        float getRotation(){
            return this->sprite->getRotation();
        }

        amath::Vector2 getPosition(){
            return this->sprite->getPosition();
        };

        amath::Vector2 getPositionLua(){
            return this->sprite->getPosition();
        }

        object(){};
    };

    class light{
    public:
        amath::Vector2 position;
        float distance;
        T3::color color;

        light( amath::Vector2 position, T3::color color ){
            this->position = position;
            this->color = color;

            T3::lightsBuffer.push_back( this );
        };
    };

    class dynamic: public object
    {
    public:
        float weight = 1;
        bool active = false;
        bool pixel_collision = false;
        //bool customShader = false;
        bool screenBorders = false;
        bool screenCords = false;

        luabridge::LuaRef localRef = luabridge::LuaRef( luaInit::luaState );
        bool haveRef = false;

        dynamic( std::string texture, bool interpolation = false, bool buffer = true ){
            T3::renderablesBuffer.push_back( new renderable::sprite() );
            this->sprite = (renderable::sprite*)T3::renderablesBuffer[T3::renderablesBuffer.size()-1];
            this->sprite->id = rand() % 99999999999;
            this->sprite->setTextureStr( texture );
            this->sprite->setOrigin( sprite->getLocalBounds().width/2, sprite->getLocalBounds().height/2 );

            this->sprite->interpolation = interpolation;

            //this->screen = &this->sprite->screen;
            //this->textureBuffer = this->sprite->getTexture()->copyToImage();


            //T3::renderablesBuffer.push_back( this->sprite );
            //this->id = static_cast<int>(T3::renderablesBuffer.size());
            this->id = rand() % 99999999999;

            //this->shader = T3::loadShader("ent/obj.glsl");
            //this->depth = T3::loadShader("ent/depth.glsl");
            //T3::spriteShadersBuffer.push_back( this->shader );
            //T3::spriteShadersBufferDepth.push_back( this->depth );

            if( buffer )
                T3::dynamicsBuffer.push_back( this );
        };

        ~dynamic(){
            this->sprite->removed = true;
            
            for (int i = 0; i < T3::renderablesBuffer.size(); i++)
            {
                if( ((renderable::sprite*)T3::renderablesBuffer[i])->id == this->sprite->id ){
                    T3::renderablesBuffer.erase(T3::renderablesBuffer.begin() + i);
                    break;
                }
            }

            for (int i = 0; i < T3::dynamicsBuffer.size(); i++)
            {
                if( ((dynamic*)T3::dynamicsBuffer[i])->id == this->id ){
                    T3::dynamicsBuffer.erase(T3::dynamicsBuffer.begin() + i);
                    break;
                }
            }
        }

        void setInterpolation( bool value ){
            this->sprite->interpolation = value;
        }

        void remove() {
            for (int i = 0; i < T3::renderablesBuffer.size(); i++)
            {
                if( ((renderable::sprite*)T3::renderablesBuffer[i])->id == this->sprite->id ){
                    this->sprite->removed = true;
                    //T3::renderablesBuffer.erase(T3::renderablesBuffer.begin() + i);
                    break;
                }
            }

            for (int i = 0; i < T3::dynamicsBuffer.size(); i++)
            {
                if( ((dynamic*)T3::dynamicsBuffer[i])->id == this->id ){
                    T3::dynamicsBuffer[i] = nullptr;
                    T3::dynamicsBuffer.erase(T3::dynamicsBuffer.begin() + i);
                    break;
                }
            }
        }
        
        void screenCoords( bool onoff ){
            this->sprite->screen = onoff;
        }

        void setColor( T3::color rgba ){
            this->sprite->setColor( rgba );
        }

        void setScreenCords( bool value ){
            this->sprite->screenCords = value;
        }

        void setDepth( float newDepth ){
            this->sprite->depthLayer = newDepth;
        }

        void loadTexture( std::string name ){
            this->sprite->setTextureStr( name );
            //this->sprite->setOrigin( this->sprite->getLocalBounds().width/2, this->sprite->getLocalBounds().height/2 );
        }

        void setShader( std::string path ){
            this->sprite->loadShader(path);
        }

        void setRef( luabridge::LuaRef ref ){
            this->localRef = ref;
            this->haveRef = true;
        }

        luabridge::LuaRef getRef(){
            return this->localRef;
        }
    };

    class brush
    {
    public:
        std::vector<amath::Vector2> points;
        int id;
        float scale;
        bool removed = false;
        bool collision = true;
        body::rigidbody* body;
        //sf::ConvexShape polygon;
        renderable::brush *polygon;
        std::string hitSound = "fall.wav";

        brush(){
            this->scale = 1;
            
            b2BodyDef newBodyDef;
            
            newBodyDef.type = b2_staticBody;
            //this->body = physics::world->CreateBody(&newBodyDef);
            T3::brushBuffer.push_back(this);

            T3::renderablesBuffer.push_back( new renderable::brush() );
            this->polygon = (renderable::brush*)T3::renderablesBuffer[T3::renderablesBuffer.size()-1];
            this->polygon->id = rand() % 99999999999;
            //this->polygon->setTexture( *T3::loadTexture( texture ) );
            //this->sprite->setOrigin( sprite->getLocalBounds().width/2, sprite->getLocalBounds().height/2 );
        };

        void done(){

            if( this->collision ){
                b2Vec2 vertices[this->points.size()];
                for (int i = 0; i < this->points.size(); i++)
                {
                    vertices[i].Set(this->points[i].x/physics::worldSize, this->points[i].y/physics::worldSize);
                    //std::cout << "X: " << this->points[i].x << " Y: " << this->points[i].y << "\n";
                }

                b2ChainShape chain;
                chain.CreateLoop(vertices, this->points.size());

    //            b2FixtureDef fixtureDef;
    //            fixtureDef.shape = &chain;
    //            fixtureDef.density = 2.0f;
    //            fixtureDef.restitution = 0.5f;
    //            fixtureDef.friction = 0.5f;

                //this->body->CreateFixture(&fixtureDef);
                //this->body->GetUserData().pointer = this;

                this->body = new body::rigidbody(&chain);
                this->body->setType("static");
                //this->body = physicsObj->body;
            }

            this->polygon->convex( this->points );

            //this->polygon.setPointCount(this->points.size());
            //for (int g = 0; g < this->points.size(); g++){
            //    this->polygon.setPoint(g, this->points[g].sfml());
            //}
        }

        ~brush(){
            //physics::world->DestroyBody(this->body);

            for (int i = 0; i < T3::brushBuffer.size(); i++)
            {
                if( ((brush*)T3::brushBuffer[i])->id == this->id ){
                    T3::brushBuffer.erase(T3::brushBuffer.begin() + i);
                    break;
                }
            }

            for (int i = 0; i < T3::renderablesBuffer.size(); i++)
            {
                if( ((renderable::sprite*)T3::renderablesBuffer[i])->id == this->polygon->id ){
                    this->polygon->removed = true;
                    T3::renderablesBuffer.erase(T3::renderablesBuffer.begin() + i);
                    break;
                }
            }
        };
    };




    namespace entities{
        
        void init(){
        
        }

    }

}