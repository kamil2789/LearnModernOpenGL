#version 330 core

out vec4 FragColor;

in vec3 Color;
in vec2 TextCoord;

uniform sampler2D myTexture;

void main()
{
    FragColor = texture(myTexture, TextCoord);
}