#include "utils/math.hpp"
#include "ui/blocks.hpp"
#include "raymath.h"
//constants 
constexpr inline float normScale=1.0f;
constexpr inline float maxScale=1.1f;
constexpr inline float minScale=0.98f;
void Button::update(float dt, float offsetY){
    Vector2 mousePosition=GetMousePosition();
    bool hovering=CheckCollisionPointRec(mousePosition,normalizeRect());
    //look if you are hovering first
    if(hovering){
        baseColor=GREEN;
        baseScale=lerp(baseScale,maxScale,0.3f);
        if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
            baseColor=RED;
            baseScale=lerp(baseScale,minScale,0.6f);
            clicked=true;
        }
        else if(IsMouseButtonDown(MOUSE_LEFT_BUTTON)){
            baseColor=RED;
            baseScale=lerp(baseScale,minScale,0.6f);
      
            clicked=true;
        }
    }
    //then check if youve clicked something
    else if(clicked){
        baseColor=ORANGE;
        //If you clicked somewhere else and you weren't hovering
        if(!hovering && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
            clicked=false;
        }
    }
    //if none of those it means you arent on it and you havent clicked it
    else{ 
        baseScale=lerp(baseScale,normScale,0.3f);
  
        baseColor=WHITE;
    }
}
void Button::render(float offsetY) const {
    if(texture){
        if(clicked){
            DrawTexturePro(*texture,
                {0,0,(float)texture->width,(float)texture->height},
                {rectangle.x,rectangle.y,buttonWidth*baseScale,buttonHeight*baseScale},
                { buttonWidth / 2.0f, buttonHeight / 2.0f },
                0.0f,WHITE);
            DrawRectangleRoundedLinesEx({(rectangle.x-rectangle.width/2),(rectangle.y-rectangle.height/2),buttonWidth*baseScale,buttonHeight*baseScale},buttonRoundness,buttonSegments,1.5f,WHITE);
        }
        else{
            DrawTexturePro(*texture,
                {0,0,(float)texture->width,(float)texture->height},
                {rectangle.x,rectangle.y,buttonWidth*baseScale,buttonHeight*baseScale},
                { buttonWidth / 2.0f, buttonHeight / 2.0f },
                0.0f,WHITE);
           
        }
    }
    //if no texture is found
    else{
        if(clicked){
            DrawRectangleRounded({(rectangle.x-rectangle.width/2),(rectangle.y-rectangle.height/2),buttonWidth*baseScale,buttonHeight*baseScale},buttonRoundness,buttonSegments,baseColor);
            DrawRectangleRoundedLinesEx({(rectangle.x-rectangle.width/2),(rectangle.y-rectangle.height/2),buttonWidth*baseScale,buttonHeight*baseScale},buttonRoundness,buttonSegments,1.5f,WHITE);
        }
        else{
            DrawRectangleRounded({(rectangle.x-rectangle.width/2),(rectangle.y-rectangle.height/2),buttonWidth*baseScale,buttonHeight*baseScale},buttonRoundness,buttonSegments,baseColor);
        }
    
    }
    
}
Rectangle Button::normalizeRect() const {
    return {rectangle.x - rectangle.width / 2.0f, rectangle.y - rectangle.height / 2.0f, rectangle.width, rectangle.height};
 }
 