#pragma once

#ifndef _TEXTURE_H_
#define _TEXTURE_H_

#include "Header.h"

vector<GLuint> listTexture;
int loadGLTextures();

int loadGLTextures() {
	for (int i = 0; i < 2; i++) {
	    GLuint textureNumber = SOIL_load_OGL_texture(
	        textureFileNames[i],
	        SOIL_LOAD_AUTO,
	        SOIL_CREATE_NEW_ID,
	        SOIL_FLAG_INVERT_Y);
	
	    if (textureNumber == 0)
	    {
	        cout << "Load texture " << i << " FAIL" << endl;
	        return false;
	    }
	    listTexture.push_back(textureNumber);
	}
	return true;
}

//class Texture {
//public:
//    static vector<GLuint> listTexture;
//	static int loadGLTextures();
//};
//
//
//int Texture::loadGLTextures() {
//	for (int i = 0; i < 8; i++) {
//        GLuint textureNumber = SOIL_load_OGL_texture(
//            textureFileNames[i],
//            SOIL_LOAD_AUTO,
//            SOIL_CREATE_NEW_ID,
//            SOIL_FLAG_INVERT_Y);
//
//        if (textureNumber == 0)
//        {
//            cout << "Load texture " << i << " FAIL" << endl;
//            return false;
//        }
//        listTexture.push_back(textureNumber);
//    }
//    return true;
//}

#endif