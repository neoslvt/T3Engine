namespace gui{
	void GuiSetFont( std::string font ){
		auto result = T3::loadFont(font);

		GuiSetFont(T3::fontBuffer[result]);
	}

	void GuiSetStyle( int control, int property, int value ){
		GuiSetStyle(control, property, value);
	}

	bool GuiButton( float x, float y, float width, float heigth, const char* text ){
		return GuiButton((Rectangle){ x, y, width, heigth }, text);
	}
}